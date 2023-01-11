#include "objtypes.h"
#include "objects.h"

#ifndef _OBJMGR_H
#define _OBJMGR_H

object_routine *object_def_pointers[OBJECT_DEFS_COUNT];

#define INSTANCE_POOL_SIZE 10
struct instance_memory instance_pool[INSTANCE_POOL_SIZE];

int objmgr_init();
int objmgr_deinit();
void objmgr_loop();

/* utility functions */
int objmgr_get_instance_count();

#define STATUS_FAILURE -1
#define STATUS_SUCCESS 0

#endif /* _OBJMGR_H */
