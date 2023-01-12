#include <stdio.h>

#include <objmgr/objtypes.h>
#include <objmgr/objapi.h>
#include <objdefs/object01.h>

static void object01_init(instance_memory_t *self, instance_id_t instance_id);
static void object01_loop(instance_memory_t *self, instance_id_t instance_id);
static void object01_remove_self(instance_memory_t *self, instance_id_t instance_id);

static object_routine *object01_subroutines[OBJECT_01_SUB_COUNT] = {
  &object01_init,
  &object01_loop,
  &object01_remove_self
};

void object01(instance_memory_t *self, instance_id_t instance_id) {
  /* assuming subroutine_index is 0 at the start of our lifecycle */
  object01_subroutines[self->subroutine_index](self, instance_id);
}

static void object01_init(instance_memory_t *self, instance_id_t instance_id) {
  printf("object01 (%i): init (routine %i)\n", instance_id, self->subroutine_index);
  self->subroutine_index = OBJECT_01_SUB_LOOP; /* start loop */
}

static void object01_loop(instance_memory_t *self, instance_id_t instance_id) {
  self->vars[OBJECT_01_VAR_COUNTER]++;
  printf("object01 (%i): loop (routine %i) %i\n", instance_id, self->subroutine_index, self->vars[OBJECT_01_VAR_COUNTER]);
  if (self->vars[OBJECT_01_VAR_COUNTER] == 5) {
    self->subroutine_index = OBJECT_01_SUB_REMOVE_SELF; /* remove ourselves the next loop */
  }
}

static void object01_remove_self(instance_memory_t *self, instance_id_t instance_id) {
  printf("object01 (%i): end of life (routine %i)\n", instance_id, self->subroutine_index);
  instance_destroy(self);
}
