# Porting ASan to NetBSD

This repository will hold the code needed to get Address Sanitizer (ASan) working
to find memory bugs in the NetBSD userland and kernel.

## Progress

#### Week 1

* Removed weak symbols from assembly stubs for intercepted syscalls.
* Begin adding interceptor functions for syscalls that write to memory.

#### Week 2

* Continue adding interceptor functions for syscalls writing to memory and
  begin adding syscalls that read from memory.
* Add `touch_mem()` function to touch each byte of a null-terminated string.

#### Week 3

* Tie up loose ends with interceptor functions.
* Begin copying the address sanitizer functionality needed for the interceptor
  functions.

#### Week 4

* Travel home to Canada.
