#include <objmgr/objmgr.h>
#include <objmgr/objects.h>
#include <stdint.h> /* for NULL */

object_routine *object_main_routines[OBJECT_DEFS_COUNT] = {
  NULL,
  &object01
};
