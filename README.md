# Porting ASan to NetBSD

This repository will hold the code needed to get Address Sanitizer (ASan) working
to find memory bugs in the NetBSD userland and kernel.

## Progress

#### Week 1

* Removed weak symbols from assembly stubs for intercepted syscalls.
* Begin adding interceptor functions for syscalls that write to memory.

#### Week 2

* Continue adding interceptor functions for syscalls writing to memory and
  begin adding syscalls that write to memory.
