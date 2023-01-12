#include <objmgr/objtypes.h>
#include <objmgr/objapi.h>
#include <test/objdefs/obj_noop.h>

void obj_noop(instance_memory_t *self, instance_id_t instance_id) {
  (void)self;
  (void)instance_id;
}
