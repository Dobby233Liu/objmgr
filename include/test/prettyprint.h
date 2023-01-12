#include <stdio.h>

#ifndef TEST_PRETTYPRINT_H
#define TEST_PRETTYPRINT_H

/* oops! all gnu extension */
#define PPRINT_FOR(s) s ": "
#define PPRINT(o, p, m, x, ...) fprintf(o, m PPRINT_FOR(p) x "\n", ##__VA_ARGS__)
#define INFO(m, ...) PPRINT(stdout, "info", PPRINT_FOR(m), __VA_ARGS__)
#define ERR(m, ...) PPRINT(stderr, "err", PPRINT_FOR(m), __VA_ARGS__)
#define WARN(m, ...) PPRINT(stderr, "warn", PPRINT_FOR(m), __VA_ARGS__)

#endif /* TEST_PRETTYPRINT_H */
