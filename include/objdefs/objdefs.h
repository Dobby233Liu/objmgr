#include <objmgr/objtypes.h>
#include <objdefs/object01.h>

#ifndef OBJDEFS_OBJDEFS_H
#define OBJDEFS_OBJDEFS_H

enum {
  OBJECT__NULL_PLACE = OBJECT_NULL,

  OBJECT_01,

  OBJECT_DEFS_COUNT
};
#undef OBJECT__NULL_PLACE

extern object_routine *object_main_routines[OBJECT_DEFS_COUNT];

#endif /* OBJDEFS_OBJDEFS_H */

