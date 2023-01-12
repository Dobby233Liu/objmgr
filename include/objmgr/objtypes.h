#ifndef OBJTYPES_H
#define OBJTYPES_H

#define INSTANCE_VARS_COUNT 10

typedef unsigned int object_index_t;
typedef int instance_id_t;
typedef unsigned int object_subroutine_index_t;

struct instance_memory;

typedef void object_routine(struct instance_memory *self, instance_id_t instance_id);

struct instance_memory {
  object_index_t object_index;
  object_subroutine_index_t subroutine_index;
  int vars[INSTANCE_VARS_COUNT];
};

#endif /* OBJTYPES_H */
