#ifndef __SORT_H__
#define __SORT_H__

#include <stdlib.h>
#include <string.h>

#include "array_stack.h"
#include "list_stack.h"
#include "defs.h"
#include "types.h"

int list_stack_sort(node_t **head_1, node_t **head_2, node_t **head_res);
int array_stack_sort(arr_stack_t *stack_1, arr_stack_t *stack_2, arr_stack_t *stack_res);


#endif // __SORT_H__
