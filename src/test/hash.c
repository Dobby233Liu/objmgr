#include <uthash.h>

#include <test/test.h>
#include <test/hash.h>
#include "tests.h"

static test_t *tests_hash = NULL;

void test_hash_init() {
  for (unsigned int i = 0; i < COUNTOF(tests); i++) {
    HASH_ADD_STR(tests_hash, name, &tests[i]);
  }
}

test_t *test_hash_find(char* name) {
  test_t *test;
  HASH_FIND_STR(tests_hash, name, test);
  return test;
}

void test_hash_deinit() {
  HASH_CLEAR(hh, tests_hash);
}
