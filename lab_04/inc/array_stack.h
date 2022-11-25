#ifndef __ARR_STACK_H__
#define __ARR_STACK_H__

#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "types.h"

int array_stack_init(arr_stack_t *stack);
int array_stack_push(arr_stack_t *stack, const int value);
int array_stack_pop(arr_stack_t *stack);
int array_stack_peek(arr_stack_t *stack);
int array_stack_empty(arr_stack_t *stack);
int array_stack_copy(arr_stack_t *stack, arr_stack_t *stack_copy, arr_stack_t *stack_temp);
size_t array_stack_counter_el(arr_stack_t *stack, const int element);
int array_stack_max_el(arr_stack_t *stack, arr_stack_t *sorted_stack);

#endif // __ARR_STACK_H__
