#ifndef __IO_H__
#define __IO_H__

#include "sort.h"
#include <stdio.h>

int stack_fill(arr_stack_t *stack, node_t **head);
void print_error(int error);
void array_stack_print(arr_stack_t *stack);
void list_stack_print(node_t **head);

#endif
