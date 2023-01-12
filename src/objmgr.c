#include <string.h> /* for memset */

#include <objmgr/objtypes.h>
#include <objmgr/objmgr.h>

struct instance_memory instance_pool[INSTANCE_POOL_SIZE];

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
