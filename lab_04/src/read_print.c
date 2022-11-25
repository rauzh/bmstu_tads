#include <stdlib.h>
#include <stdio.h>

#include "read_print.h"
#include "defs.h"
#include "types.h"

int stack_fill(arr_stack_t *stack, node_t **head)
{
    int number;

    printf("Введите количество элементов: ");
    if (fscanf(stdin, "%d", &number) != 1)
        return STACK_FILL_ERROR;
    if (number < 1)
        return STACK_EMPTY;

    printf("Введите элементы через пробел: ");
    for (int i = 0, rc, value; i < number; i++)
    {
        if (fscanf(stdin, "%d", &value) != 1)
            return STACK_FILL_ERROR;
        
        if (array_stack_push(stack, value) != EXIT_SUCCESS)
            return STACK_OVERFLOW;

        rc = list_stack_push(head, value);
        if (rc != EXIT_SUCCESS)
        {
            list_stack_free(head);
            return rc;
        }
    }

    return EXIT_SUCCESS;
}

void array_stack_print(arr_stack_t *stack)
{   
    arr_stack_t stack_copy, stack_temp;

    array_stack_init(&stack_copy);
    array_stack_init(&stack_temp);

    array_stack_copy(stack, &stack_copy, &stack_temp);
    
    printf("[ ");
    while (array_stack_empty(&stack_copy) != STACK_EMPTY)
    {
        printf("%d ", array_stack_pop(&stack_copy));
    }
    printf("]\n");

    free(stack_copy.data);
    free(stack_temp.data);
}

void list_stack_print(node_t **head)
{   
    node_t *head_copy, *head_temp;

    head_copy = NULL;
    head_temp = NULL;

    list_stack_copy(head, &head_copy, &head_temp);

    printf("[ ");
    while (list_stack_empty(head_copy) != STACK_EMPTY)
        printf("%d ", list_stack_pop(&head_copy));
    printf("]\n");

    node_t *tmp_ptr = *head;

    printf("Адреса элементов стека --> ");
    printf("[ ");
    while (tmp_ptr != NULL)
    {
        printf("%p ", (void *) tmp_ptr);
        tmp_ptr = tmp_ptr->next;
    }
    printf("]\n");

    list_stack_free(&head_copy);
    list_stack_free(&head_temp);
}


void print_error(int error)
{
    switch (error) {
        case MEMORY_ALLOCATION_ERROR:
            printf("\n%sОшибка при выделении динамической памяти%s\n", RED, RESET);
            break;
        case STACK_OVERFLOW:
            printf("\n%sСтек переполнен%s\n", RED, RESET);
            break;
        case STACK_UNDERFLOW:
            printf("\n%sСлишком маленький стек%s\n", RED, RESET);
            break;
        case STACK_EMPTY:
            printf("\n%sСтек пустой%s\n", RED, RESET);
            break;
        case STACK_FILL_ERROR:
            printf("\n%sОшибка при заполнении стека%s\n", RED, RESET);
            break;
        case STACK_POP_NUMBER_ERROR:
            printf("\n%sОшибка при удалении элемента стека%s\n", RED, RESET);
            break;
        default:
            printf("\n%sНеизвестная ошибка%s\n", RED, RESET);
    }
}

