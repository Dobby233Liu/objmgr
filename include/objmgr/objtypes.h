#include <stdint.h>

#ifndef _OBJTYPES_H
#define _OBJTYPES_H

#define INSTANCE_VARS_COUNT 10

typedef int object_index_t;
typedef int instance_id_t;
typedef uint8_t object_subroutine_index_t;

struct instance_memory;

typedef void object_routine(struct instance_memory *self, instance_id_t instance_id);

struct instance_memory {
  object_routine *main_routine;
  object_subroutine_index_t subroutine_index; /* can be disregarded, but standard objects should use this */
  int8_t vars[INSTANCE_VARS_COUNT];
};

#endif /* _OBJTYPES_H */
