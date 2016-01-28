#include "stack.h"

stk_t *stack_init(void *buf, unsigned int size)
{
    stk_t *stk;
    const unsigned int hdr_size = sizeof(*stk);

    if (buf == NULL) {
        return NULL;
    }

    if (size < hdr_size) {
        return NULL;
    }

    stk = buf;
    stk->capacity = (size - hdr_size) / sizeof(stk->item[0]);
    stk->noccupied = 0;
    stk->stk_alloc = NULL;
    stk->stk_free = NULL;

    return stk;
}

stk_t *stack_alloc(unsigned int count, void *(*stk_alloc)(unsigned int),
                   void (*stk_free)(stk_t *))
{
    stk_t *stk = NULL;

    if (stk_alloc) {
        stk = stk_alloc(sizeof(*stk) + count * sizeof(stk->item[0]));
    }

    if (stk) {
        stk->capacity = count;
        stk->noccupied = 0;
        stk->stk_alloc = stk_alloc;
        stk->stk_free = stk_free;
    }

    return stk;
}

void stack_free(stk_t *stk)
{
    if (stk && stk->stk_free) {
        stk->stk_free(stk);
    }
}

void stack_push(stk_t *stk, item_t item)
{
    if (stk && (stk->noccupied < stk->capacity)) {
        stk->item[stk->noccupied++] = item;
    }
}

item_t stack_pop(stk_t *stk)
{
    if (stk && (stk->noccupied > 0)) {
        return stk->item[--stk->noccupied];
    }

    return NULL;
}

int stack_isempty(stk_t *stk)
{
    if (stk && (stk->noccupied == 0)) {
        return 1;
    }

    return 0;
}

int stack_isfull(stk_t *stk)
{
    if (stk && (stk->noccupied == stk->capacity)) {
        return 1;
    }

    return 0;
}
