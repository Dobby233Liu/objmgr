#include <stdlib.h>

#include <objmgr/objapi.h>
#include <objmgr/objects.h>
#include <objmgr/objmgr.h>

int main() {
  instance_id_t inst;

  if (objmgr_init() != OBJMGR_STATUS_SUCCESS) {
    return 1;
  }

  inst = instance_create(OBJECT_01);
  if (inst == OBJMGR_STATUS_FAILURE) {
    return 1;
  }

  for (;;) {
    if (objmgr_get_instance_count() < 1) {
      break;
    }
    objmgr_loop();
  }

  objmgr_deinit();

  return 0;
}
