#include <objmgr/objtypes.h>

#ifndef OBJAPI_H
#define OBJAPI_H

instance_id_t instance_create(object_index_t obj);
int instance_destroy(instance_memory_t *instance);

#endif /* OBJAPI_H */
