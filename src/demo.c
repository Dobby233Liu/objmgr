#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>
#include <objdefs/objdefs.h>

int main() {
  instance_id_t inst;

  if (!objmgr_init()) {
    return 1;
  }

  inst = instance_create(OBJECT_01);
  if (inst == OBJMGR_NO_INSTANCE) {
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
