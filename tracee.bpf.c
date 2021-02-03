//
// Created by Simarpreet Singh on 2021-02-02.
//

//#include "tracee.bpf.h"

static __inline int has_prefix(char *prefix, char *str, int n)
{
    int i;
#pragma unroll
    for (i = 0; i < n; prefix++, str++, i++) {
        if (!*prefix)
            return 1;
        if (*prefix != *str) {
            return 0;
        }
    }

    // prefix is too long
    return 0;
}