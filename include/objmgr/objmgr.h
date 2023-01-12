#include <stdbool.h>
#include <objmgr/objtypes.h>

#ifndef OBJMGR_OBJMGR_H
#define OBJMGR_OBJMGR_H

#define OBJMGR_NO_INSTANCE -1

/* core functions */
bool objmgr_init(void);
bool objmgr_deinit(void);
void objmgr_loop(void);

/* utility functions */
int objmgr_get_instance_count(void);
instance_memory_t *objmgr_get_obj_from_id(instance_id_t id);
instance_id_t objmgr_find_free_slot(void);
bool objmgr_initalize_object(instance_memory_t *instance, object_index_t object_index);

#endif /* OBJMGR_OBJMGR_H */
