#include <objmgr/objtypes.h>

#ifndef OBJDEFS_OBJECT01_H
#define OBJDEFS_OBJECT01_H

/* main routine should be public */
void object01(instance_memory_t *self, instance_id_t instance_id);

/* enums for vars and subs just in case
   someone else wants to modify them */
enum {
  OBJECT_01_VAR_COUNTER,
  OBJECT_01_VAR_COUNT = INSTANCE_VARS_COUNT
};

enum {
  OBJECT_01_SUB_INIT,
  OBJECT_01_SUB_LOOP,
  OBJECT_01_SUB_REMOVE_SELF,
  OBJECT_01_SUB_COUNT
};

#endif /* OBJDEFS_OBJECT01_H */
