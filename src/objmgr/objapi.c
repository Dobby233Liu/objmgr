#include <string.h> /* for memset */

#include <objmgr/objtypes.h>
#include <objmgr/objmgr.h>
#include <objmgr/objapi.h>

instance_id_t instance_create(object_index_t obj_index) {
  instance_id_t i = objmgr_find_free_slot();
  if (i != OBJMGR_STATUS_FAILURE) {
    instance_memory_t *instance = objmgr_get_obj_from_id(i);
    memset(instance, 0, sizeof(*instance));
    instance->object_index = obj_index;
    return i;
  }
  return OBJMGR_STATUS_FAILURE;
}

int instance_destroy(instance_memory_t *instance) {
  if (instance == NULL) {
    return OBJMGR_STATUS_FAILURE;
  }
  instance->object_index = OBJECT_NULL;
  return OBJMGR_STATUS_SUCCESS;
}
