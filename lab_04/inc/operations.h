#ifndef __OPERATIONS_H__
#define __OPERATIONS_H__

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

#include "read_print.h"


int load_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2);

void print_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2, \
    node_t **head_res, arr_stack_t *array_stack_res);

int sort_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2, \
    node_t **head_res, arr_stack_t *array_stack_res);

int del_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2);

int efficiency_result(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2, \
    node_t **head_res, arr_stack_t *array_stack_res);

//void efficiency_result(matrix_t a, matrix_t b);

unsigned long long microseconds_now(void);

#endif // __OPERATIONS_H__
