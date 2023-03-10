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
    ERR(ME, "failed to initalize objmgr - failure");
    return false;
  }

  bool res = test.func();

  if (!objmgr_deinit()) {
    ERR(ME, "failed to deinitalize objmgr - failure");
    return false;
  }

  return test.should_fail ? !res : res;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    ERR(ME, "usage: tester (test)");
    return 2;
  }

  test_hash_init();

  test_t *test = test_hash_find(argv[1]);
  if (!test) {
    ERR(ME, "no such test");
    return 2;
  }

  bool res = test_run(*test);
  if (res) {
    INFO(ME, "test passed");
  } else {
    INFO(ME, "test failure");
  }

  test_hash_deinit();
  if (!res)
    return 1;
  return 0;
}
