#include "objtypes.h"

#ifndef _OBJAPI_H
#define _OBJAPI_H

instance_id_t instance_create(object_index_t obj);
void instance_destroy(struct instance_memory *instance);
void instance_destroy_by_id(instance_id_t id);

#endif /* _OBJAPI_H */
