#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

/* definitions */

/* types & globals */

typedef int object_index_t;
typedef int instance_id_t;
typedef uint8_t object_subroutine_index_t;

struct instance_memory;

typedef void object_routine(struct instance_memory *self, instance_id_t instance_id);

#define INSTANCE_VARS_COUNT 10
struct instance_memory {
  object_routine *main_routine;
  object_subroutine_index_t subroutine_index; /* can be disregarded, but standard objects should use this */
  int8_t vars[INSTANCE_VARS_COUNT];
};

#define INSTANCE_POOL_SIZE 10
// TODO make statically allocated?
struct instance_memory *instance_pool[INSTANCE_POOL_SIZE];

/* funcs */

int objectmgr_init();
void objectmgr_loop();

/* object api */
instance_id_t instance_create(object_index_t obj);
void instance_destroy(struct instance_memory *instance);
void instance_destroy_by_id(instance_id_t id);

/* utility functions */
int objectmgr_get_instance_count();

int objectmgr_deinit();

/* obj 01 funcs */

void object01(struct instance_memory *self, instance_id_t instance_id);
void object01_init(struct instance_memory *self, instance_id_t instance_id);
void object01_loop(struct instance_memory *self, instance_id_t instance_id);
void object01_remove_self(struct instance_memory *self, instance_id_t instance_id);

/* object implementations */

/* object list */
enum {
  OBJECT_01,
  OBJECT_DEFS_COUNT
};
object_routine *object_def_pointers[OBJECT_DEFS_COUNT] = {
  &object01
};

enum {
  OBJECT_01_SUB_INIT,
  OBJECT_01_SUB_LOOP,
  OBJECT_01_SUB_REMOVE_SELF,
  OBJECT_01_SUB_COUNT
};
object_routine *object01_subroutines[OBJECT_01_SUB_COUNT] = {
  &object01_init,
  &object01_loop,
  &object01_remove_self
};

/* variables */
enum {
  OBJECT_01_VAR_COUNTER,
  OBJECT_01_VAR_COUNT = INSTANCE_VARS_COUNT
};

void object01(struct instance_memory *self, instance_id_t instance_id) {
  /* assuming subroutine_index is 0 at the start of our lifecycle */
  (*object01_subroutines[self->subroutine_index])(self, instance_id);
}

void object01_init(struct instance_memory *self, instance_id_t instance_id) { /* 00 */
  /*
    instance_id_t inst;
    inst = instance_create(OBJECT_01);
  */
  printf("object01 (%i): init (routine %i)\n", instance_id, self->subroutine_index);
  self->subroutine_index = OBJECT_01_SUB_LOOP; /* start loop */
}

void object01_loop(struct instance_memory *self, instance_id_t instance_id) { /* 01 */
  self->vars[OBJECT_01_VAR_COUNTER]++;
  printf("object01 (%i): loop (routine %i) %i\n", instance_id, self->subroutine_index, self->vars[OBJECT_01_VAR_COUNTER]);
  if (self->vars[OBJECT_01_VAR_COUNTER] == 5) {
    self->subroutine_index = OBJECT_01_SUB_REMOVE_SELF; /* remove ourselves the next loop */
  }
}

void object01_remove_self(struct instance_memory *self, instance_id_t instance_id) { /* 02 */
  printf("object01 (%i): end of life (routine %i)\n", instance_id, self->subroutine_index);
  instance_destroy(self);
}

/* manager implementation */

#define STATUS_FAILURE -1
#define STATUS_SUCCESS 0

int objectmgr_init() {
  memset(&instance_pool, 0, sizeof(instance_pool));
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance_pool[i] = (struct instance_memory *)malloc(sizeof(*instance_pool[i]));
    if (instance_pool[i] == NULL) {
      objectmgr_deinit();
      return STATUS_FAILURE;
    }
    memset(instance_pool[i], 0, sizeof(*instance_pool[i]));
  }
  return STATUS_SUCCESS;
}

int objectmgr_deinit() {
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    if (instance_pool[i] != NULL) {
        free(instance_pool[i]);
    }
  }
  memset(&instance_pool, 0, sizeof(instance_pool));
  return STATUS_SUCCESS;
}

void objectmgr_loop() {
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = instance_pool[i];
    if (instance != NULL) {
      if (instance->main_routine != NULL) {
        instance->main_routine(instance, i);
      } else {
        // TODO free mem asap?
        // memset(instance, 0, sizeof(*instance));
      }
    }
  }
}

int objectmgr_get_instance_count() {
  int count = 0;
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = instance_pool[i];
    if (instance == NULL || instance->main_routine == NULL) {
      continue;
    }
    count++;
  }
  return count;
}

/* object api */

instance_id_t instance_create(object_index_t obj_index) {
  struct instance_memory *instance;
  for (int i = 0; i < INSTANCE_POOL_SIZE; i++) {
    instance = instance_pool[i];
    if (instance == NULL || instance->main_routine == NULL) {
      memset(instance, 0, sizeof(*instance));
      instance->main_routine = object_def_pointers[obj_index];
      return i;
    }
  }
  return STATUS_FAILURE;
}

void instance_destroy(struct instance_memory *instance) {
  if (instance == NULL) {
    return;
  }
  instance->main_routine = NULL;
}

void instance_destroy_by_id(instance_id_t id) {
  instance_destroy(instance_pool[id]);
}

/* program implementation */

int main() {
  instance_id_t inst;

  if (objectmgr_init() != STATUS_SUCCESS) {
    return 1;
  }

  inst = instance_create(OBJECT_01);
  if (inst == STATUS_FAILURE) {
    return 1;
  }

  for (;;) {
    if (objectmgr_get_instance_count() < 1) {
      break;
    }

    objectmgr_loop();

    sleep(1/30);
  }

  objectmgr_deinit();
  return 0;
}