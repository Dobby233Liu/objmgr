#include <stddef.h>

#include <objmgr/objtypes.h>
#include <test/objdefs/objdefs.h>

object_routine *object_main_routines[OBJECT_DEFS_COUNT] = {
  NULL,
  &obj_loop_5_then_remove_self,
  &obj_noop
};
