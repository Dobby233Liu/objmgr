#include <stdio.h>

#ifndef TEST_PRETTYPRINT_H
#define TEST_PRETTYPRINT_H

/* FIXME: oops! all gnu extension */

#define PPRINT_FOR(s) s ": "
#define PPRINT(m, o, p, x, ...) fprintf(o, PPRINT_FOR(m) PPRINT_FOR(p) x "\n", ##__VA_ARGS__)
#define INFO(m, ...) PPRINT(m, stdout, "info", __VA_ARGS__)
#define ERR(m, ...) PPRINT(m, stderr, "err", __VA_ARGS__)
#define WARN(m, ...) PPRINT(m, stderr, "warn", __VA_ARGS__)

#endif /* TEST_PRETTYPRINT_H */
