//===-- sanitizer_procmaps.h ------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file is shared between AddressSanitizer and ThreadSanitizer.
//
// Information about the process mappings.
//===----------------------------------------------------------------------===//
#ifndef SANITIZER_PROCMAPS_H
#define SANITIZER_PROCMAPS_H

#include "sanitizer_internal_defs.h"

namespace __sanitizer {

class ProcessMaps {
 public:
  ProcessMaps();
  bool Next(uptr *start, uptr *end, uptr *offset,
            char filename[], uptr filename_size);
  void Reset();
  // Gets the object file name and the offset in that object for a given
  // address 'addr'. Returns true on success.
  bool GetObjectNameAndOffset(uptr addr, uptr *offset,
                              char filename[], uptr filename_size);
  ~ProcessMaps();
 private:
  // Default implementation of GetObjectNameAndOffset.
  // Quite slow, because it iterates through the whole process map for each
  // lookup.
  bool IterateForObjectNameAndOffset(uptr addr, uptr *offset,
                                     char filename[], uptr filename_size) {
    Reset();
    uptr start, end, file_offset;
    for (int i = 0; Next(&start, &end, &file_offset, filename, filename_size);
         i++) {
      if (addr >= start && addr < end) {
        // Don't subtract 'start' for the first entry. Don't ask me why.
        *offset = (addr - (i ? start : 0)) + file_offset;
        return true;
      }
    }
    if (filename_size)
      filename[0] = '\0';
    return false;
  }

#if defined(__linux__) || defined(__NetBSD__)
  char *proc_self_maps_buff_;
  uptr proc_self_maps_buff_mmaped_size_;
  uptr proc_self_maps_buff_len_;
  char *current_;
#elif defined __APPLE__
  template<u32 kLCSegment, typename SegmentCommand>
  bool NextSegmentLoad(uptr *start, uptr *end, uptr *offset,
                       char filename[], uptr filename_size);
  int current_image_;
  u32 current_magic_;
  int current_load_cmd_count_;
  char *current_load_cmd_addr_;
#endif
};

}  // namespace __sanitizer

#endif  // SANITIZER_PROCMAPS_H
