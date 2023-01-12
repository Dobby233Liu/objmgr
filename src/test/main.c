#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include <objmgr/objmgr.h>
#include <test/test.h>
#include <test/prettyprint.h>
#include <test/hash.h>
#include "tests.h"

#define ME "test"

static bool test_run(test_t test) {
  if (!objmgr_init()) {
    ERR(ME, "failure to initalize objmgr");
    return false;
  }

  bool res = test.func();

  if (!objmgr_deinit()) {
    ERR(ME, "failure to deinitalize objmgr");
    return false;
  }

  if (test.should_fail)
    return !res;
  return res;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    ERR(ME, "must provide a test as command arg 1");
    return 2;
  }

  test_hash_init();

  test_t *test = test_hash_find(argv[1]);
  if (!test) {
    ERR(ME, "test does not exist");
    return 2;
  }

  bool res = test_run(*test);

  test_hash_deinit();
  if (!res)
    return 1;
  return 0;
}
