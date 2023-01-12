#include <objmgr/objtypes.h>
#include <objmgr/objects.h>

#ifndef OBJMGR_H
#define OBJMGR_H

extern object_routine *object_main_routines[OBJECT_DEFS_COUNT];

#define INSTANCE_POOL_SIZE 10
extern struct instance_memory instance_pool[INSTANCE_POOL_SIZE];

int objmgr_init(void);
int objmgr_deinit(void);
void objmgr_loop(void);

/* utility functions */
int objmgr_get_instance_count(void);

#define OBJMGR_STATUS_FAILURE -1
#define OBJMGR_STATUS_SUCCESS 0

#endif /* OBJMGR_H */
