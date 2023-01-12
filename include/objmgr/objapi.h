#include <objmgr/objtypes.h>

#ifndef OBJAPI_H
#define OBJAPI_H

instance_id_t instance_create(object_index_t obj);
void instance_destroy(struct instance_memory *instance);
void instance_destroy_by_id(instance_id_t id);

#endif /* OBJAPI_H */
