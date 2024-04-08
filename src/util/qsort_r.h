#ifndef QSORT_R_H
#define QSORT_R_H

#include <stddef.h>

typedef int (*cmp_func_t)(const void *, const void *, void *);

void qsort_r(void *base, size_t nmemb, size_t size, cmp_func_t cmp, void *arg);

#endif
