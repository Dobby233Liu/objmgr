#include <stdio.h>

#ifndef TEST_PRETTYPRINT_H
#define TEST_PRETTYPRINT_H

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgnu-zero-variadic-macro-arguments"
#endif
/* FIXME: avoid ##, somehow */
#define PPRINT(m, o, p, x, ...) fprintf(o, m ": " p ": " x "\n", ##__VA_ARGS__)
#define INFO(m, ...) PPRINT(m, stdout, "info", __VA_ARGS__)
#define ERR(m, ...) PPRINT(m, stderr, "err", __VA_ARGS__)
#define WARN(m, ...) PPRINT(m, stderr, "warn", __VA_ARGS__)
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#endif /* TEST_PRETTYPRINT_H */
