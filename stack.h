#pragma once

#include <lib/stack.h>

#ifndef NULL
#define NULL ((void *)0)
#endif  /* NULL */

struct stk {
    unsigned int capacity;
    unsigned int noccupied;
    void *(*stk_alloc)(unsigned int);
    void (*stk_free)(stk_t *);
    item_t item[];
};
