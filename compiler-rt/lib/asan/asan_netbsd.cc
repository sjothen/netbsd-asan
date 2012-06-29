//===-- asan_netbsd.cc -----------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is a part of AddressSanitizer, an address sanity checker.
//
// NetBSD-specific details.
//===----------------------------------------------------------------------===//
#ifdef __NetBSD__

#include "asan_interceptors.h"
#include "asan_internal.h"
#include "asan_lock.h"
#include "asan_thread.h"
#include "sanitizer_common/sanitizer_libc.h"
#include "sanitizer_common/sanitizer_procmaps.h"

#include <sys/time.h>
#include <sys/resource.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <ucontext.h>

extern "C" void* _DYNAMIC;

namespace __asan {

void *AsanDoesNotSupportStaticLinkage() {
  // This will fail to link with -static.
  return &_DYNAMIC;  // defined in link.h
}

void GetPcSpBp(void *context, uptr *pc, uptr *sp, uptr *bp) {
#if defined(__arm__)
  ucontext_t *ucontext = (ucontext_t*)context;
  *pc = ucontext->uc_mcontext.__gregs[_REG_PC];
  *bp = ucontext->uc_mcontext.__gregs[_REG_FP];
  *sp = ucontext->uc_mcontext.__gregs[_REG_SP];
# elif defined(__x86_64__)
  ucontext_t *ucontext = (ucontext_t*)context;
  *pc = ucontext->uc_mcontext.__gregs[_REG_RIP];
  *bp = ucontext->uc_mcontext.__gregs[_REG_RBP];
  *sp = ucontext->uc_mcontext.__gregs[_REG_RSP];
# elif defined(__i386__)
  ucontext_t *ucontext = (ucontext_t*)context;
  *pc = ucontext->uc_mcontext.__gregs[_REG_EIP];
  *bp = ucontext->uc_mcontext.__gregs[_REG_EBP];
  *sp = ucontext->uc_mcontext.__gregs[_REG_ESP];
#else
# error "Unsupported arch"
#endif
}

bool AsanInterceptsSignal(int signum) {
  return signum == SIGSEGV && FLAG_handle_segv;
}

AsanLock::AsanLock(LinkerInitialized) {
  // We assume that pthread_mutex_t initialized to all zeroes is a valid
  // unlocked mutex. We can not use PTHREAD_MUTEX_INITIALIZER as it triggers
  // a gcc warning:
  // extended initializer lists only available with -std=c++0x or -std=gnu++0x
}

void AsanLock::Lock() {
  CHECK(sizeof(pthread_mutex_t) <= sizeof(opaque_storage_));
  pthread_mutex_lock((pthread_mutex_t*)&opaque_storage_);
  CHECK(!owner_);
  owner_ = (uptr)pthread_self();
}

void AsanLock::Unlock() {
  CHECK(owner_ == (uptr)pthread_self());
  owner_ = 0;
  pthread_mutex_unlock((pthread_mutex_t*)&opaque_storage_);
}

void AsanStackTrace::GetStackTrace(uptr max_s, uptr pc, uptr bp) {
  size = 0;
  trace[0] = pc;
  if ((max_s) > 1) {
    max_size = max_s;
    FastUnwindStack(pc, bp);
  }
}

}  // namespace __asan

#endif  // __NetBSD__
