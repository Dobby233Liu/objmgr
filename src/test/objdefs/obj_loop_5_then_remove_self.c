#include <stdio.h>

#include <objmgr/objtypes.h>
#include <objmgr/objapi.h>
#include <test/test.h>
#include <test/prettyprint.h>
#include <test/objdefs/obj_loop_5_then_remove_self.h>

#define ME "o_l5trs (%i)"

static void obj_loop_5_then_remove_self_init(instance_memory_t *self, instance_id_t instance_id);
static void obj_loop_5_then_remove_self_loop(instance_memory_t *self, instance_id_t instance_id);
static void obj_loop_5_then_remove_self_remove_self(instance_memory_t *self, instance_id_t instance_id);

static object_routine *obj_loop_5_then_remove_self_subroutines[OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_COUNT] = {
  &obj_loop_5_then_remove_self_init,
  &obj_loop_5_then_remove_self_loop,
  &obj_loop_5_then_remove_self_remove_self
};

void obj_loop_5_then_remove_self(instance_memory_t *self, instance_id_t instance_id) {
  /* assuming subroutine_index is 0 at the start of our lifecycle */
  obj_loop_5_then_remove_self_subroutines[self->subroutine_index](self, instance_id);
}

static void obj_loop_5_then_remove_self_init(instance_memory_t *self, instance_id_t instance_id) {
  INFO(ME, "init", instance_id);
  self->subroutine_index = OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_LOOP; /* start loop */
}

static void obj_loop_5_then_remove_self_loop(instance_memory_t *self, instance_id_t instance_id) {
  self->vars[OBJ_LOOP_5_THEN_REMOVE_SELF_VAR_COUNTER]++;
  INFO(ME, "loop %i", instance_id, self->vars[OBJ_LOOP_5_THEN_REMOVE_SELF_VAR_COUNTER]);
  if (self->vars[OBJ_LOOP_5_THEN_REMOVE_SELF_VAR_COUNTER] == 5) {
    self->subroutine_index = OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_REMOVE_SELF; /* remove ourselves the next loop */
  }
}

static void obj_loop_5_then_remove_self_remove_self(instance_memory_t *self, instance_id_t instance_id) {
  INFO(ME, "end of life", instance_id);
  instance_destroy(self);
}
