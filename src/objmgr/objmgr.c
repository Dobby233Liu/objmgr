#include <string.h> /* for memset */
#include <objmgr/internal/macros.h>

#include <objmgr/objtypes.h>
#include <objmgr/config_consts.h>
#include <objmgr/internal/objdefs.h>
#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>

/* FIXME: reconsider adding this to a header */
static instance_memory_t instance_pool[OBJMGR_INSTANCE_POOL_TOTAL];

bool objmgr_init() {
  /* clear instance memory */
  return memset(&instance_pool, 0, sizeof(instance_pool));
}

bool objmgr_deinit() {
  return objmgr_init();
}

void objmgr_loop() {
  for (instance_id_t i = 0; i < OBJMGR_INSTANCE_POOL_TOTAL; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (instance_exists(instance)) {
      object_main_routines[instance->object_index](instance, i);
    }
  }
}

int objmgr_get_instance_count() {
  int count = OBJMGR_INSTANCE_POOL_TOTAL;
  for (instance_id_t i = 0; i < OBJMGR_INSTANCE_POOL_TOTAL; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (!instance_exists(instance)) {
      count--;
      continue;
    }
  }
  return count;
}

instance_memory_t *objmgr_get_obj_from_id(instance_id_t id) {
  if (id < 0 || id >= OBJMGR_INSTANCE_POOL_TOTAL) {
    return NULL;
  }
  return &instance_pool[id];
}

instance_id_t objmgr_find_free_slot() {
  for (instance_id_t i = 0; i < OBJMGR_INSTANCE_POOL_TOTAL; i++) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    if (!instance_exists(instance)) {
      return i;
    }
  }
  return OBJMGR_NO_INSTANCE;
}

bool objmgr_initalize_object(instance_memory_t *instance, object_index_t object_index) {
  if (!instance || !memset(instance, 0, sizeof(*instance))) {
    return false;
  }
  instance->object_index = object_index;
  return true;
}
