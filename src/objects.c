#include <objmgr/objmgr.h>
#include <objmgr/objtypes.h>
#include <objmgr/objects.h>

object_routine *object_main_routines[OBJECT_DEFS_COUNT] = {
  NULL,
  &object01
};
