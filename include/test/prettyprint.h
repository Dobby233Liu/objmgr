#include <stdio.h>

#ifndef TEST_PRETTYPRINT_H
#define TEST_PRETTYPRINT_H

/* FIXME: avoid ## */
#define PPRINT(m, o, p, x, ...) fprintf(o, m ": " p ": " x "\n", ##__VA_ARGS__)
#define INFO(m, ...) PPRINT(m, stdout, "info", __VA_ARGS__)
#define ERR(m, ...) PPRINT(m, stderr, "err", __VA_ARGS__)
#define WARN(m, ...) PPRINT(m, stderr, "warn", __VA_ARGS__)

#endif /* TEST_PRETTYPRINT_H */
