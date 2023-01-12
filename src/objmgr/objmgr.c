#include <string.h> /* for memset */
#include <objmgr/internal/macros.h>

#include <objmgr/objtypes.h>
#include <objmgr/internal/objdefs.h>
#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>

/* FIXME: reconsider adding this to a header */
static instance_memory_t instance_pool[10];
#define INSTANCE_POOL_TOTAL (int)(COUNTOF(instance_pool))

bool objmgr_init() {
  /* clear instance memory */
  memset(&instance_pool, 0, sizeof(instance_pool));
  return true;
}

bool objmgr_deinit() {
  return objmgr_init();
}

void objmgr_loop() {
  for (instance_id_t i = 0; i < INSTANCE_POOL_TOTAL; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (instance_exists(instance)) {
      object_main_routines[instance->object_index](instance, i);
    }
  }
}

int objmgr_get_instance_count() {
  int count = INSTANCE_POOL_TOTAL;
  for (instance_id_t i = 0; i < INSTANCE_POOL_TOTAL; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (!instance_exists(instance)) {
      count--;
      continue;
    }
  }
  return count;
}

instance_memory_t *objmgr_get_obj_from_id(instance_id_t id) {
  if (id < 0 || id >= INSTANCE_POOL_TOTAL) {
    return NULL;
  }
  return &instance_pool[id];
}

instance_id_t objmgr_find_free_slot() {
  for (instance_id_t i = 0; i < INSTANCE_POOL_TOTAL; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (!instance_exists(instance)) {
      return i;
    }
  }
  return OBJMGR_NO_INSTANCE;
}
