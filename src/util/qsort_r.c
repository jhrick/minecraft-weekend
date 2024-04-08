#include "qsort_r.h"

#include <stdlib.h>
#include <string.h>

// Implementação de qsort_r
void qsort_r(void *base, size_t nmemb, size_t size, cmp_func_t cmp, void *arg) {
    if (nmemb <= 1) {
        return;
    }

    char *pivot = base;
    char *left = base + size;
    char *right = base + (nmemb - 1) * size;

    while (left <= right) {
        while (left <= right && cmp(left, pivot, arg) < 0) {
            left += size;
        }
        while (left <= right && cmp(right, pivot, arg) > 0) {
            right -= size;
        }
        if (left <= right) {
            // Troca left e right
            char *temp = malloc(size);
            memcpy(temp, left, size);
            memcpy(left, right, size);
            memcpy(right, temp, size);
            free(temp);
            left += size;
            right -= size;
        }
    }

    // Recursivamente ordena as partições
    qsort_r(base, (left - (char *)base) / size, size, cmp, arg);
    qsort_r(left, nmemb - (left - (char *)base) / size, size, cmp, arg);
}

