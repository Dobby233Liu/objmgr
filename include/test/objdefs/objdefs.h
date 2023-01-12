#include <objmgr/objtypes.h>
#include <test/objdefs/obj_loop_5_then_remove_self.h>
#include <test/objdefs/obj_noop.h>

#ifndef TEST_OBJDEFS_OBJDEFS_H
#define TEST_OBJDEFS_OBJDEFS_H

enum {
  OBJECT__NULL_PLACE = OBJECT_NULL,

  OBJ_LOOP_5_THEN_REMOVE_SELF,
  OBJ_NOOP,

  OBJECT_DEFS_COUNT
};
#undef OBJECT__NULL_PLACE

extern object_routine *object_main_routines[OBJECT_DEFS_COUNT];

#endif /* TEST_OBJDEFS_OBJDEFS_H */

