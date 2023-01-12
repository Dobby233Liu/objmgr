#include <objmgr/config_consts.h>

#ifndef OBJMGR_OBJTYPES_H
#define OBJMGR_OBJTYPES_H

typedef unsigned int object_index_t;
typedef int instance_id_t;

#define OBJECT_NULL (object_index_t)0

typedef unsigned int object_subroutine_index_t;

struct instance_memory {
  object_index_t object_index;

  /* standard variables */
  object_subroutine_index_t subroutine_index;

  /* user-defined variables */
  int vars[OBJMGR_INSTANCE_VARS_COUNT];
};
typedef struct instance_memory instance_memory_t;

typedef void object_routine(instance_memory_t *self, instance_id_t instance_id);

#endif /* OBJMGR_OBJTYPES_H */
