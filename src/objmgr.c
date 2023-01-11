#include <stdlib.h>
#include <string.h> /* for memset */

#include <objmgr/objtypes.h>
#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>

/* main functionality */

int objmgr_init() {
  /* clear instance memory */
  memset(&instance_pool, 0, sizeof(instance_pool));
  return STATUS_SUCCESS;
}

int objmgr_deinit() {
  objmgr_init();
  return STATUS_SUCCESS;
}

void objmgr_loop() {
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = &instance_pool[i];
    if (instance->object_index != OBJECT_NULL) {
      object_main_routines[instance->object_index](instance, i);
    } else {
      /* TODO: maybe clear memory asap */
      /* memset(instance, 0, sizeof(*instance)); */
    }
  }
}

int objmgr_get_instance_count() {
  int count = 0;
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = &instance_pool[i];
    if (instance->object_index == OBJECT_NULL) {
      continue;
    }
    count++;
  }
  return count;
}

/* object api */

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
  return STATUS_FAILURE;
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
