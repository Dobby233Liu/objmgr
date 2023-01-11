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
    if (instance->main_routine != NULL) {
      instance->main_routine(instance, i);
    } else {
      memset(instance, 0, sizeof(*instance));
    }
  }
}

int objmgr_get_instance_count() {
  int count = 0;
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = &instance_pool[i];
    if (instance->main_routine == NULL) {
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
    if (instance->main_routine == NULL) {
      memset(instance, 0, sizeof(*instance));
      instance->main_routine = object_def_pointers[obj_index];
      return i;
    }
  }
  return STATUS_FAILURE;
}

void instance_destroy(struct instance_memory *instance) {
  if (instance == NULL) {
    return;
  }
  instance->main_routine = NULL;
}

void instance_destroy_by_id(instance_id_t id) {
  instance_destroy(&instance_pool[id]);
}
