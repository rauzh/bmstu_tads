#ifndef __TYPES_H__
#define __TYPES_H__

#include "defs.h"

typedef struct 
{
	size_t size;
	size_t top;

	int *data;
} arr_stack_t; // стэк-массив

typedef struct node_t
{
	int data;

	struct node_t *next;
} node_t; // список 

typedef struct 
{
	node_t *free_arr_ptrs[MAX_LEN_ARR_PTRS];

	int len;
} free_ptrs_t; // массив указателей на освобождённые элементы стека

free_ptrs_t freed;

typedef enum {
    false,
    true
} bool;

#endif // __TYPES_H__
