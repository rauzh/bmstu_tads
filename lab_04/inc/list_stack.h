#ifndef __LIST_STACK_H__
#define __LIST_STACK_H__

#include <stdlib.h>
#include <string.h>

#include "defs.h"
#include "types.h"

node_t *list_element_init(const int value);
int list_stack_push(node_t **head, const int value);
int list_stack_pop(node_t **head);
int list_stack_peek(node_t *head);
int list_stack_empty(node_t *head);
size_t list_stack_size(node_t *head);
void list_stack_free(node_t **head);
int list_stack_copy(node_t **head, node_t **head_copy, node_t **head_temp);
size_t list_stack_counter_el(node_t *head, const int element);
int list_stack_max_el(node_t **head, node_t **sorted_head);

#endif // __LIST_STACK_H__
