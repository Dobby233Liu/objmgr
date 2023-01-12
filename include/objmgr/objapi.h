#include <stdbool.h>
#include <objmgr/objtypes.h>

#ifndef OBJMGR_OBJAPI_H
#define OBJMGR_OBJAPI_H

instance_id_t instance_create(object_index_t object_index);
bool instance_exists(instance_memory_t *instance);
bool instance_destroy(instance_memory_t *instance);

#endif /* OBJMGR_OBJAPI_H */
