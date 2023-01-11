#include <objmgr/objtypes.h>

#ifndef _OBJECT01_H
#define _OBJECT01_H

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
object_routine *object01_subroutines[OBJECT_01_SUB_COUNT];

void object01(struct instance_memory *self, instance_id_t instance_id);
void object01_init(struct instance_memory *self, instance_id_t instance_id);
void object01_loop(struct instance_memory *self, instance_id_t instance_id);
void object01_remove_self(struct instance_memory *self, instance_id_t instance_id);

#endif /* _OBJECT01_H */