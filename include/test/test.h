#include <stdbool.h>
#include <uthash.h>
#include <test/macros.h>

#ifndef TEST_TEST_H
#define TEST_TEST_H

typedef bool test_func(void);

struct test {
  char name[256];
  test_func *func;
  bool should_fail;
  char padding[3];
  UT_hash_handle hh;
};
typedef struct test test_t;

#endif /* TEST_TEST_H */
