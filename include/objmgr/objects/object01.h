#include <objmgr/objtypes.h>

#ifndef OBJECT01_H
#define OBJECT01_H

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

void object01(instance_memory_t *self, instance_id_t instance_id);
void object01_init(instance_memory_t *self, instance_id_t instance_id);
void object01_loop(instance_memory_t *self, instance_id_t instance_id);
void object01_remove_self(instance_memory_t *self, instance_id_t instance_id);

#endif /* OBJECT01_H */
