#include "list_stack.h"

node_t *list_element_init(const int value)
{   
    node_t *node = malloc(sizeof(struct node_t));

    if (node)
    {
        (node)->data = value;
        (node)->next = NULL; 
    }

    return node;
}

int list_stack_push(node_t **head, const int value)
{
    node_t *node = list_element_init(value);
    if (node == NULL)
        return MEMORY_ALLOCATION_ERROR;

    node->next = *head;
    *head = node;

    return EXIT_SUCCESS;
}

int list_stack_pop(node_t **head)
{
    int head_value;
    node_t* temp_node;

    if (*head == NULL) 
        return STACK_UNDERFLOW;
    
    temp_node = *head;
    head_value = temp_node->data;
    *head = (*head)->next;

    return head_value;
}

int list_stack_peek(node_t *head)
{
    if (head == NULL)
        return STACK_UNDERFLOW;

    return head->data;
}

int list_stack_empty(node_t *head)
{
    if (head == NULL)
        return STACK_EMPTY;

    return EXIT_SUCCESS;
}

size_t list_stack_size(node_t *head)
{
    node_t *head_copy, *head_temp;
    size_t size = 0;

    head_copy = NULL;
    head_temp = NULL;

    list_stack_copy(&head, &head_copy, &head_temp);

    while (head_copy)
    {
        list_stack_pop(&head_copy);
        size++;
    }

    list_stack_free(&head_copy);
    list_stack_free(&head_temp);

    return size;
}

void list_stack_free(node_t **head)
{
    node_t *next;

    for (; *head; *head = next)
    {
        next = (*head)->next;
        free(*head);
    }
}

int list_stack_copy(node_t **head, node_t **head_copy, node_t **head_temp)
{
    while (list_stack_empty(*head) != STACK_EMPTY)
    {
        if (list_stack_push(head_temp, list_stack_peek(*head)) != EXIT_SUCCESS)
            return STACK_OVERFLOW;

        list_stack_pop(head);
    }
    while (list_stack_empty(*head_temp) != STACK_EMPTY)
    {
        if (list_stack_push(head, list_stack_peek(*head_temp)) != EXIT_SUCCESS)
            return STACK_OVERFLOW;
        if (list_stack_push(head_copy, list_stack_peek(*head_temp)) != EXIT_SUCCESS)
            return STACK_OVERFLOW;

        list_stack_pop(head_temp);
    }

    return EXIT_SUCCESS;
}

size_t list_stack_counter_el(node_t *head, const int element)
{
    node_t *head_copy, *head_temp;
    size_t counter = 0;

    head_copy = NULL;
    head_temp = NULL;

    list_stack_copy(&head, &head_copy, &head_temp);

    while (list_stack_empty(head_copy) != STACK_EMPTY)
    {
        if (list_stack_pop(&head_copy) == element)
            counter++;
    }

    list_stack_free(&head_copy);
    list_stack_free(&head_temp);

    return counter;
}

int list_stack_max_el(node_t **head, node_t **sorted_head)
{
    if (list_stack_empty(*head) != EXIT_SUCCESS)
        return STACK_EMPTY;

    int max = list_stack_peek(*head);
    while (list_stack_counter_el(*head, max) <= list_stack_counter_el(*sorted_head, max))
    {
        list_stack_pop(head);
        max = list_stack_peek(*head);
    }

    for (int tmp; list_stack_empty(*head) != STACK_EMPTY; list_stack_pop(head))
    {
        tmp = list_stack_peek(*head);
        if (tmp > max && (list_stack_counter_el(*head, tmp) > list_stack_counter_el(*sorted_head, tmp)))
            max = tmp;
    }

    return max;
}


