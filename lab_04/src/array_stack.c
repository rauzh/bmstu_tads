#include "array_stack.h"

int array_stack_init(arr_stack_t *stack) 
{
    stack->top = INIT_TOP;
    stack->size = MAX_STACK_SIZE;
    stack->data = malloc(stack->size * sizeof(int));
    if (stack->data == NULL)
        return MEMORY_ALLOCATION_ERROR;

    return EXIT_SUCCESS;
}

int array_stack_push(arr_stack_t *stack, const int value)
{
    if (stack->top >= stack->size)
        return STACK_OVERFLOW;

    stack->data[stack->top] = value;
    (stack->top)++;

    return EXIT_SUCCESS;
}

int array_stack_pop(arr_stack_t *stack)
{
    if (stack->top < 1)
        return STACK_UNDERFLOW;

    (stack->top)--;

    return stack->data[stack->top];
}

int array_stack_peek(arr_stack_t *stack)
{
    if (stack->top < 1) 
        return STACK_UNDERFLOW;

    return stack->data[stack->top - 1];
}

int array_stack_empty(arr_stack_t *stack)
{
    if (stack->top < 1)
        return STACK_EMPTY;

    return EXIT_SUCCESS;
}

int array_stack_copy(arr_stack_t *stack, arr_stack_t *stack_copy, arr_stack_t *stack_temp)
{
    while (array_stack_empty(stack) != STACK_EMPTY)
    {
        if (array_stack_push(stack_temp, array_stack_peek(stack)) != EXIT_SUCCESS)
            return STACK_OVERFLOW;
        array_stack_pop(stack);
    }

    while (array_stack_empty(stack_temp) != STACK_EMPTY)
    {
        if (array_stack_push(stack, array_stack_peek(stack_temp)) != EXIT_SUCCESS)
            return STACK_OVERFLOW;
        if (array_stack_push(stack_copy, array_stack_peek(stack_temp)) != EXIT_SUCCESS)
            return STACK_OVERFLOW;

        array_stack_pop(stack_temp);
    }

    return EXIT_SUCCESS;
}

size_t array_stack_counter_el(arr_stack_t *stack, const int element)
{
    arr_stack_t stack_copy, stack_temp;
    size_t counter = 0;

    if (array_stack_init(&stack_copy) != EXIT_SUCCESS)
        return MEMORY_ALLOCATION_ERROR;
    if (array_stack_init(&stack_temp) != EXIT_SUCCESS)
    {
        free(stack_copy.data);
        return MEMORY_ALLOCATION_ERROR;
    }

    array_stack_copy(stack, &stack_copy, &stack_temp);

    while(array_stack_empty(&stack_copy) != STACK_EMPTY)
    {
        if (array_stack_pop(&stack_copy) == element)
            counter++;
    }

    free(stack_copy.data);
    free(stack_temp.data);

    return counter;
}

int array_stack_max_el(arr_stack_t *stack, arr_stack_t *sorted_stack)
{
    if (array_stack_empty(stack) == STACK_EMPTY)
        return STACK_EMPTY;

    int max = array_stack_peek(stack);
    while (array_stack_counter_el(stack, max) <= array_stack_counter_el(sorted_stack, max))
    {
        array_stack_pop(stack);
        max = array_stack_peek(stack);
    }

    for (int tmp; array_stack_empty(stack) != STACK_EMPTY; array_stack_pop(stack))
    {
        tmp = array_stack_peek(stack);
        if (tmp > max && (array_stack_counter_el(stack, tmp) > array_stack_counter_el(sorted_stack, tmp)))
            max = tmp;
    }

    return max;
}

