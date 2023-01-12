#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>
#include <test/objdefs/objdefs.h>
#include <test/test.h>
#include "tests.h"

static bool l5trs_single() {
  if (instance_create(OBJ_LOOP_5_THEN_REMOVE_SELF) == OBJMGR_NO_INSTANCE) {
    return false;
  }

  while (objmgr_get_instance_count() > 0) {
    objmgr_loop();
  }

  return true;
}

test_t tests[1] = {
  {
    .name = "l5trs_single",
    .func = &l5trs_single,
    .should_fail = false
  }
};
