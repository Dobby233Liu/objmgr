#include <objmgr/objtypes.h>

#ifndef OBJMGR_H
#define OBJMGR_H

#define INSTANCE_POOL_SIZE 10

extern object_routine *object_main_routines[];

int objmgr_init(void);
int objmgr_deinit(void);
void objmgr_loop(void);

/* utility functions */
int objmgr_get_instance_count(void);
instance_memory_t *objmgr_get_obj_from_id(instance_id_t id);
instance_id_t objmgr_find_free_slot(void);

#endif /* OBJMGR_H */
