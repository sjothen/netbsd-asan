//===-- sanitizer_internal_defs.h -------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is shared between AddressSanitizer and ThreadSanitizer.
// It contains macro used in run-time libraries code.
//===----------------------------------------------------------------------===//
#ifndef SANITIZER_DEFS_H
#define SANITIZER_DEFS_H

#include <stdio.h>
#include "sanitizer_interface_defs.h"

// Common defs.
#define INLINE static inline
#define INTERFACE_ATTRIBUTE SANITIZER_INTERFACE_ATTRIBUTE
#define WEAK SANITIZER_WEAK_ATTRIBUTE

// If __WORDSIZE was undefined by the platform, define it in terms of the
// compiler built-ins __LP64__ and _WIN64.
#ifndef __WORDSIZE
# if __LP64__ || defined(_WIN64)
#  define __WORDSIZE 64
# else
#  define __WORDSIZE 32
#  endif
#endif  // __WORDSIZE

// NOTE: Functions below must be defined in each run-time.
#define CHECK_IMPL(c1, op, c2) \
  do { \
    u64 v1 = (u64)(c1); \
    u64 v2 = (u64)(c2); \
    if (!(v1 op v2)) \
      printf("ASan CHECK Failure: %s %d %s %llu %llu\n", __FILE__, __LINE__, \
        "(" #c1 ") " #op " (" #c2 ")", v1, v2); \
  } while (false) \
/**/
   
#define CHECK(a)       CHECK_IMPL((a), !=, 0)
#define CHECK_EQ(a, b) CHECK_IMPL((a), ==, (b))
#define CHECK_NE(a, b) CHECK_IMPL((a), !=, (b))
#define CHECK_LT(a, b) CHECK_IMPL((a), <,  (b))
#define CHECK_LE(a, b) CHECK_IMPL((a), <=, (b))
#define CHECK_GT(a, b) CHECK_IMPL((a), >,  (b))
#define CHECK_GE(a, b) CHECK_IMPL((a), >=, (b))

// Limits for integral types. We have to redefine it in case we don't
// have stdint.h (like in Visual Studio 9).
#if __WORDSIZE == 64
# define __INT64_C(c)  c ## L
# define __UINT64_C(c) c ## UL
#else
# define __INT64_C(c)  c ## LL
# define __UINT64_C(c) c ## ULL
#endif  // __WORDSIZE == 64
#undef INT32_MIN
#define INT32_MIN              (-2147483647-1)
#undef INT32_MAX
#define INT32_MAX              (2147483647)
#undef UINT32_MAX
#define UINT32_MAX             (4294967295U)
#undef INT64_MIN
#define INT64_MIN              (-__INT64_C(9223372036854775807)-1)
#undef INT64_MAX
#define INT64_MAX              (__INT64_C(9223372036854775807))
#undef UINT64_MAX
#define UINT64_MAX             (__UINT64_C(18446744073709551615))

#endif  // SANITIZER_DEFS_H
