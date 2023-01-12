#include <string.h> /* for memset */

#include <objmgr/objtypes.h>
#include <objmgr/objmgr.h>

static instance_memory_t instance_pool[INSTANCE_POOL_SIZE];

int objmgr_init() {
  /* clear instance memory */
  memset(&instance_pool, 0, sizeof(instance_pool));
  return OBJMGR_STATUS_SUCCESS;
}

int objmgr_deinit() {
  objmgr_init();
  return OBJMGR_STATUS_SUCCESS;
}

void objmgr_loop() {
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (instance->object_index != OBJECT_NULL) {
      object_main_routines[instance->object_index](instance, i);
    }
  }
}

int objmgr_get_instance_count() {
  int count = INSTANCE_POOL_SIZE;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (instance->object_index == OBJECT_NULL) {
      count--;
      continue;
    }
  }
  return count;
}

instance_memory_t *objmgr_get_obj_from_id(instance_id_t id) {
  return &instance_pool[id];
}

instance_id_t objmgr_find_free_slot() {
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (instance->object_index == OBJECT_NULL) {
      return i;
    }
  }
  return OBJMGR_STATUS_FAILURE;
}
