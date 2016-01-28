#pragma once

/**
 * @brief User-defined type of stack item.
 */
typedef const void * item_t;

typedef struct stk stk_t;

/**
 * @brief Initializes new stack on giving buffer.
 * @return Pointer to new stack.
 */
stk_t *stack_init(void *buf, unsigned int size);

/**
 * @brief Allocates new stack.
 * @return Pointer to new stack.
 */
stk_t *stack_alloc(unsigned int count, void *(*stk_alloc)(unsigned int),
                   void (*stk_free)(stk_t *));

/**
 * @brief Frees existing stack.
 * @return Pointer to new stack.
 */
void stack_free(stk_t *stk);

/**
 * @brief Pushes new item on top.
 */
void stack_push(stk_t *stk, item_t item);

/**
 * @brief Pops next item from top.
 * @return New item or NULL.
 */
item_t stack_pop(stk_t *stk);

/**
 * @brief Checks if stack @stk is empty and cannot accept pop().
 * @return 1 if stack @stk is empty, 0 otherwise.
 */
int stack_isempty(stk_t *stk);

/**
 * @brief Checks if stack @stk is full and cannot accept push().
 * @return 1 if stack @stk is full, 0 otherwise.
 */
int stack_isfull(stk_t *stk);
