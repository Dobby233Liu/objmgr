#include <objmgr/objapi.h>
#include <objmgr/objmgr.h>
#include <objdefs/objdefs.h>

int main() {
  if (!objmgr_init()) {
    return 1;
  }

  if (instance_create(OBJECT_01) == OBJMGR_NO_INSTANCE) {
    return 1;
  }

  while (objmgr_get_instance_count() > 0) {
    objmgr_loop();
  }

  objmgr_deinit();

  return 0;
}
