#pragma once

#include "stdio.h"
#include "stdlib.h"
#include "stdlib.h"
#include "errno.h"

#ifdef DEBUG

#define PR_DEBUG(fmt, ...) fprintf(stdout, "DEBUG: " fmt "\n", ##__VA_ARGS__)
#define PR_INFO(fmt, ...) fprintf(stdout, "INFO: " fmt "\n", ##__VA_ARGS__)
#define PR_WARN(fmt, ...) fprintf(stdout, "WARN: " fmt "\n", ##__VA_ARGS__)
#define PR_ERR(fmt, ...) fprintf(stderr, "ERROR: " fmt "\n", ##__VA_ARGS__)

// Macros that provide additional information
// NOTE: In case the fprint fails, it's wrong to check errno.
#define PR_WARN_2(fmt, ...) do { \
    fprintf( \
        stdout, \
        "WARN: func: %s, line: %d. " fmt "\n", \
        __func__, \
        __LINE__, \
        ##__VA_ARGS__ \
    ); \
} while (0)

#define PR_ERR_2(fmt, ...) do { \
    if (errno != 0) { \
        fprintf( \
            stderr, \
            "ERROR: func: %s, line: %d, errno: %d. " fmt "\n", \
            __func__, \
            __LINE__, \
            errno, \
            ##__VA_ARGS__ \
        ); \
    } else { \
        fprintf( \
            stderr, \
            "ERROR: func: %s, line: %d. " fmt "\n", \
            __func__, \
            __LINE__, \
            ##__VA_ARGS__ \
        ); \
    } \
} while (0)

#define PR_ERR_DIE(fmt, ...) do { \
    PR_ERR(fmt, ##__VA_ARGS__); \
} while (0)

#define PR_ERR_DIE_2(fmt, ...) do { \
    PR_ERR_2(fmt, ##__VA_ARGS__); \
    exit(errno != 0 ? errno : EXIT_FAILURE); \
} while (0)

#else

#define PR_DEBUG (void)0
#define PR_INFO (void)0
#define PR_WARN (void)0
#define PR_WARN_2 (void)0
#define PR_ERR (void)0
#define PR_ERR_2 (void)0
#define PR_ERR_DIE (void)0

#endif
