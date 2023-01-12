#include <objmgr/objtypes.h>

#ifndef TEST_OBJDEFS_OBJ_LOOP_5_THEN_REMOVE_SELF_H
#define TEST_OBJDEFS_OBJ_LOOP_5_THEN_REMOVE_SELF_H

/* main routine should be public */
void obj_loop_5_then_remove_self(instance_memory_t *self, instance_id_t instance_id);

/* enums for vars and subs just in case
   someone else wants to modify them */
enum {
  OBJ_LOOP_5_THEN_REMOVE_SELF_VAR_COUNTER,
  OBJ_LOOP_5_THEN_REMOVE_SELF_VAR_COUNT = OBJMGR_INSTANCE_VARS_COUNT
};

enum {
  OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_INIT,
  OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_LOOP,
  OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_REMOVE_SELF,
  OBJ_LOOP_5_THEN_REMOVE_SELF_SUB_COUNT
};

#endif /* TEST_OBJDEFS_OBJ_LOOP_5_THEN_REMOVE_SELF_H */
