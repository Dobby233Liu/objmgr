#include <stddef.h>

#include <objmgr/objtypes.h>
#include <objdefs/objdefs.h>

object_routine *object_main_routines[OBJECT_DEFS_COUNT] = {
  NULL,
  &object01
};
