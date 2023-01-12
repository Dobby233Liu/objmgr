#include <string.h> /* for memset */

#include <objmgr/objtypes.h>
#include <objmgr/objmgr.h>
#include <objmgr/objapi.h>

instance_id_t instance_create(object_index_t obj_index) {
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = &instance_pool[i];
    if (instance->object_index == OBJECT_NULL) {
      memset(instance, 0, sizeof(*instance));
      instance->object_index = obj_index;
      return i;
    }
  }
  return OBJMGR_STATUS_FAILURE;
}

void instance_destroy(struct instance_memory *instance) {
  if (instance == NULL) {
    return;
  }
  instance->object_index = OBJECT_NULL;
}

void instance_destroy_by_id(instance_id_t id) {
  instance_destroy(&instance_pool[id]);
}
