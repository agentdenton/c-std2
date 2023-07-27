#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "stdlib.h"
#include "errno.h"

#include "logging.h"

#define ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))

static inline void *malloc_or_die(size_t size)
{
    void *mem = malloc(size);
    if (mem == NULL) {
        PR_ERR_DIE("The malloc failed.");
    }
    return mem;
}

static inline void *malloc_or_die_msg(size_t size, const char *err_msg)
{
    void *mem = malloc(size);
    if (mem == NULL) {
        PR_ERR_DIE("The malloc function failed. %s.", err_msg);
    }
    return mem;
}
