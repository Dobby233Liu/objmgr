#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>
#include <test/objdefs/objdefs.h>
#include <test/test.h>
#include "tests.h"

static bool create_loop_and_destroy() {
  #define ME "create_loop_and_destroy"

  if (instance_create(OBJ_LOOP_5_THEN_REMOVE_SELF) == OBJMGR_NO_INSTANCE) {
    ERR(ME, "can't create obj_l5trs instance - failure");
    return false;
  }

  unsigned int runs = 1;
  while (objmgr_get_instance_count() > 0 || runs < 10) {
    objmgr_loop();
    runs++;
  }

  bool is_done = objmgr_get_instance_count() <= 1;
  if (!is_done) {
    ERR(ME, "obj_l5trs did not remove itself in 10 runs - failure");
  }
  return is_done;

  #undef ME
}

test_t tests[1] = {
  {
    .name = "create_loop_and_destroy",
    .func = &create_loop_and_destroy,
    .should_fail = false
  }
};
