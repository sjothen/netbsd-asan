#ifndef _ASAN_INTERCEPTORS_
#define _ASAN_INTERCEPTORS_

#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "sanitizer_internal_defs.h"
#include "asan_mapping.h"

#define __LIBC12_SOURCE__

#define GET_CALLER_PC() (uintptr_t)__builtin_return_address(0)
#define GET_CURRENT_FRAME() (uintptr_t)__builtin_frame_address(0)

uintptr_t GetCurrentPc(void);

void __asan_report_error(uintptr_t, uintptr_t, uintptr_t,
		uintptr_t, bool, size_t);

// Use this macro if you want to print stack trace with the current
// function in the top frame.
#define GET_CURRENT_PC_BP_SP \
  uintptr_t bp = GET_CURRENT_FRAME();              \
  uintptr_t pc = GetCurrentPc();   \
  uintptr_t local_stack;                           \
  uintptr_t sp = (uintptr_t)&local_stack;

// Macros taken from ASan code (asan_interceptors.cc)
#define ACCESS_ADDRESS(address, isWrite)   do {         \
  if (AddressIsPoisoned(address)) {                     \
    GET_CURRENT_PC_BP_SP;                               \
    __asan_report_error(pc, bp, sp, address, isWrite, /* access_size */ 1); \
  } \
} while (0)

#define ACCESS_MEMORY_RANGE(offset, size, isWrite) do { \
  if (size > 0) { \
    uintptr_t ptr = (uintptr_t)(offset); \
    ACCESS_ADDRESS(ptr, isWrite); \
    ACCESS_ADDRESS(ptr + (size) - 1, isWrite); \
  } \
} while (0)

#define ASAN_READ_RANGE(offset, size) do { \
  ACCESS_MEMORY_RANGE(offset, size, false); \
} while (0)

#define ASAN_WRITE_RANGE(offset, size) do { \
  ACCESS_MEMORY_RANGE(offset, size, true); \
} while (0)

// Function to touch all of the bytes in a  null-terminated string.
void touch_mem(const char *p);

#endif
