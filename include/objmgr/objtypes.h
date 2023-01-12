#ifndef OBJTYPES_H
#define OBJTYPES_H

#ifndef NULL
#define NULL 0
#endif

#define OBJMGR_STATUS_FAILURE -1
#define OBJMGR_STATUS_SUCCESS 0

#define INSTANCE_VARS_COUNT 10

typedef unsigned int object_index_t;
typedef int instance_id_t;
typedef unsigned int object_subroutine_index_t;

#define OBJECT_NULL (object_index_t)0

struct instance_memory;
typedef struct instance_memory instance_memory_t;

typedef void object_routine(instance_memory_t *self, instance_id_t instance_id);

struct instance_memory {
  object_index_t object_index;
  object_subroutine_index_t subroutine_index;
  int vars[INSTANCE_VARS_COUNT];
};

#endif /* OBJTYPES_H */
