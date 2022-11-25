#include "sort.h"

int list_stack_sort(node_t **head_1, node_t **head_2, node_t **head_res)
{
    int tmp_1, tmp_2;
    *head_res = NULL;

    while (list_stack_empty(*head_1) != STACK_EMPTY)
    {
        tmp_1 = list_stack_pop(head_1);
        if (list_stack_empty(*head_2) != STACK_EMPTY)
        {
            tmp_2 = list_stack_pop(head_2);
            if (tmp_2 > tmp_1)
            {
                while ((list_stack_empty(*head_res) != STACK_EMPTY) && (list_stack_peek(*head_res) > tmp_2))
                {
                    list_stack_push(head_2, list_stack_pop(head_res));
                }
                list_stack_push(head_res, tmp_2);
                list_stack_push(head_1, tmp_1);
            }
            else
            {
                while ((list_stack_empty(*head_res) != STACK_EMPTY) && (list_stack_peek(*head_res) > tmp_1))
                {
                    list_stack_push(head_1, list_stack_pop(head_res));
                }
                list_stack_push(head_res, tmp_1);
                list_stack_push(head_2, tmp_2);
            }
        }
        else
        {
            while ((list_stack_empty(*head_res) != STACK_EMPTY) && (list_stack_peek(*head_res) > tmp_1))
            {
                list_stack_push(head_1, list_stack_pop(head_res));
            }
            list_stack_push(head_res, tmp_1);
        }
    }

    return EXIT_SUCCESS;
}

int array_stack_sort(arr_stack_t *stack_1, arr_stack_t *stack_2, arr_stack_t *stack_res)
{
    int tmp_1, tmp_2;

    while (array_stack_empty(stack_1) != STACK_EMPTY)
    {
        tmp_1 = array_stack_pop(stack_1);
        if (array_stack_empty(stack_2) != STACK_EMPTY)
        {
            tmp_2 = array_stack_pop(stack_2);
            if (tmp_2 > tmp_1)
            {
                while ((array_stack_empty(stack_res) != STACK_EMPTY) && (stack_res->data[stack_res->top - 1]) > tmp_2)
                {
                    array_stack_push(stack_2, array_stack_pop(stack_res));
                }
                array_stack_push(stack_res, tmp_2);
                array_stack_push(stack_1, tmp_1);
            }
            else
            {
                while ((array_stack_empty(stack_res) != STACK_EMPTY) && (stack_res->data[stack_res->top - 1]) > tmp_1)
                {
                    array_stack_push(stack_1, array_stack_pop(stack_res));
                }
                array_stack_push(stack_res, tmp_1);
                array_stack_push(stack_2, tmp_2);
            }
        }
        else
        {
            while ((array_stack_empty(stack_res) != STACK_EMPTY) && (stack_res->data[stack_res->top - 1]) > tmp_1)
            {
                array_stack_push(stack_1, array_stack_pop(stack_res));
            }
            array_stack_push(stack_res, tmp_1);
        }
    }

    return EXIT_SUCCESS;
}
