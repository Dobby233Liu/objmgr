#include <stddef.h>
#include <string.h> /* for memset */

#include <objmgr/objtypes.h>
#include <objmgr/objmgr.h>
#include <objmgr/objapi.h>

instance_id_t instance_create(object_index_t object_index) {
  instance_id_t i = objmgr_find_free_slot();
  instance_memory_t *instance = objmgr_get_obj_from_id(i);
  if (!instance || !objmgr_initalize_object(instance, object_index)) {
    return OBJMGR_NO_INSTANCE;
  }
  return i;
}

bool instance_exists(instance_memory_t *instance) {
  return instance && instance->object_index != OBJECT_NULL;
}

bool instance_destroy(instance_memory_t *instance) {
  if (!instance_exists(instance)) {
    return false;
  }
  instance->object_index = OBJECT_NULL;
  return true;
}
