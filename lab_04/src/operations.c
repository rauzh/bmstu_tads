#include "operations.h"

int load_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2)
{
    int stack_number, rc = EXIT_SUCCESS;

    printf("1 - первый стек, 2 - второй стек, 3 - оба стека\n");
    printf("Выберите стек, в который хотите добавить элементы: ");
    if (fscanf(stdin, "%d", &stack_number) != 1)
        return STACK_NUMBER_ERROR;
    if (stack_number < 1 || stack_number > 3)
        return STACK_NUMBER_ERROR;

    if (*head_1 == NULL && *head_2 == NULL)
    {
        if (array_stack_init(array_stack_1) != EXIT_SUCCESS)
        {
            print_error(MEMORY_ALLOCATION_ERROR);
            return MEMORY_ALLOCATION_ERROR;
        }
        if (array_stack_init(array_stack_2) != EXIT_SUCCESS)
        {
            print_error(MEMORY_ALLOCATION_ERROR);
            free((*array_stack_1).data);
            return MEMORY_ALLOCATION_ERROR;
        }
    }

    if (stack_number == 1 || stack_number == 3)
    {
        printf("\nЗаполнение 1-го стека\n");
        rc = stack_fill(array_stack_1, head_1);
        if (rc != EXIT_SUCCESS)
            return rc;
        printf("Элементы успешно добавлены в 1-ый стек\n");
    }
    if (stack_number == 2 || stack_number == 3)
    {
        printf("\nЗаполнение 2-го стека\n");
        rc = stack_fill(array_stack_2, head_2);
        if (rc != EXIT_SUCCESS)
            return rc;
        printf("Элементы успешно добавлены во 2-ой стек\n");
    }    

    return EXIT_SUCCESS;
}

void print_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2, \
    node_t **head_res, arr_stack_t *array_stack_res)
{
    printf("\nСтеки в виде массива:");
    printf("\nПервый стек >> ");
    array_stack_print(array_stack_1);

    printf("Второй стек >> ");
    array_stack_print(array_stack_2);
    if (head_res == NULL)
        printf("Отсортированное слияние двух стеков >> [ ]");
    else
    {
        printf("Отсортированное слияние двух стеков >> ");
        array_stack_print(array_stack_res);
    }

    printf("\nСтеки в виде списка:");
    printf("\nПервый стек >> ");
    list_stack_print(head_1);

    printf("Второй стек >> ");
    list_stack_print(head_2);
    if (head_res == NULL)
        printf("Отсортированное слияние двух стеков >> [ ]");
    else
    {
        printf("Отсортированное слияние двух стеков >> ");
        list_stack_print(head_res);
    }

    printf("\nМассив освобождённых областей >> ");
    printf("[ ");
    for (int i = 0; i < freed.len; i++)
    {
        printf("%p ", (void *)freed.free_arr_ptrs[i]);
    }
    printf("]\n");
}

int sort_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2, \
    node_t **head_res, arr_stack_t *array_stack_res)
{
    if (*head_res != NULL)
    {
        free(array_stack_res->data);
        list_stack_free(head_res);
        *head_res = NULL;
    }
    if (array_stack_init(array_stack_res) != EXIT_SUCCESS)
    {
        free(array_stack_1->data);
        free(array_stack_2->data);
        return MEMORY_ALLOCATION_ERROR;
    }

    arr_stack_t stack_1_cp, stack_2_cp, temp_stack;

    if (array_stack_init(&stack_1_cp) != EXIT_SUCCESS)
        return MEMORY_ALLOCATION_ERROR;

    if (array_stack_init(&temp_stack) != EXIT_SUCCESS)
    {
        free(stack_1_cp.data);
        return MEMORY_ALLOCATION_ERROR;
    }

    if (array_stack_init(&stack_2_cp) != EXIT_SUCCESS)
    {
        free(stack_1_cp.data);
        free(temp_stack.data);
        return MEMORY_ALLOCATION_ERROR;
    }

    array_stack_copy(array_stack_1, &stack_1_cp, &temp_stack);
    array_stack_copy(array_stack_2, &stack_2_cp, &temp_stack);

    if (array_stack_sort(&stack_1_cp, &stack_2_cp, array_stack_res) != EXIT_SUCCESS)
        return STACK_OVERFLOW;
    list_stack_sort(head_1, head_2, head_res);
    printf("Сортировка прошла успешно\n");

    printf("Отсортированное слияние двух стеков в виде массива >> ");
    array_stack_print(array_stack_res);

    printf("Отсортированное слияние двух стеков в виде списка >> ");
    list_stack_print(head_res);

    *head_res = NULL; array_stack_res = NULL;

    printf("Теперь стеки пусты.");

    return EXIT_SUCCESS;
}

int del_stacks(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2)
{
    int stack_number, stack_pop_number;
    void *deleted_ptr;

    printf("1 - первый стек, 2 - второй стек, 3 - оба стека\n");
    printf("Выберите стек, из которого хотите удалить элементы: ");
    if (fscanf(stdin, "%d", &stack_number) != 1)
        return STACK_NUMBER_ERROR;
    if (stack_number < 1 || stack_number > 3)
        return STACK_NUMBER_ERROR;

    if (stack_number == 1 || stack_number == 3)
    {

        printf("\nВведите количество удаляемых элементов из 1-го стека: ");
        if (fscanf(stdin, "%d", &stack_pop_number) != 1)
            return STACK_POP_NUMBER_ERROR;

        for (int i = 0; i < stack_pop_number; i++)
        {
            if (array_stack_pop(array_stack_1) == STACK_UNDERFLOW)
               return STACK_UNDERFLOW;

            deleted_ptr = *head_1;
            if (freed.len < MAX_LEN_ARR_PTRS - 1)
            {
                freed.free_arr_ptrs[freed.len] = deleted_ptr;
                freed.len++;
            }

            if (list_stack_pop(head_1) == STACK_UNDERFLOW)
               return STACK_UNDERFLOW;

            printf("Удалён: %p\n", (void *) deleted_ptr);
        }
        printf("Элементы успешно удалены из 1-го стека\n");
    }
    if (stack_number == 2 || stack_number == 3)
    {

        printf("\nВведите количество удаляемых элементов из 2-го стека: ");
        if (fscanf(stdin, "%d", &stack_pop_number) != 1)
            return STACK_POP_NUMBER_ERROR;

        for (int i = 0; i < stack_pop_number; i++)
        {
            if (array_stack_pop(array_stack_2) == STACK_UNDERFLOW)
                return STACK_UNDERFLOW;

            deleted_ptr = *head_2;
            if (freed.len < MAX_LEN_ARR_PTRS - 1)
            {
                freed.free_arr_ptrs[freed.len] = deleted_ptr;
                freed.len++;
            }

            if (list_stack_pop(head_2) == STACK_UNDERFLOW)
               return STACK_UNDERFLOW;

            printf("Удалён: %p\n", (void *) deleted_ptr);
        }
        printf("Элементы успешно удалены из 2-го стека\n");
    }

    return EXIT_SUCCESS;
}


int efficiency_result(node_t **head_1, node_t **head_2, arr_stack_t *array_stack_1, arr_stack_t *array_stack_2, \
    node_t **head_res, arr_stack_t *array_stack_res)
{
    if (*head_res != NULL)
    {
        free(array_stack_res->data);
        list_stack_free(head_res);
        *head_res = NULL;
    }

    if (array_stack_init(array_stack_res) != EXIT_SUCCESS)
    {
        free(array_stack_1->data);
        free(array_stack_2->data);
        return MEMORY_ALLOCATION_ERROR;
    }

    unsigned long long start, end, arr_time = 0, list_time = 0;

    for (int i = 0; i < 100; i++)
    {
        if (*head_res != NULL)
        {
            free(array_stack_res->data);
            list_stack_free(head_res);
            *head_res = NULL;
        }

        if (array_stack_init(array_stack_res) != EXIT_SUCCESS)
        {
            free(array_stack_1->data);
            free(array_stack_2->data);
            return MEMORY_ALLOCATION_ERROR;
        }

        arr_stack_t stack_1_cp, stack_2_cp, temp_stack;

        if (array_stack_init(&stack_1_cp) != EXIT_SUCCESS)
            return MEMORY_ALLOCATION_ERROR;

        if (array_stack_init(&temp_stack) != EXIT_SUCCESS)
        {
            free(stack_1_cp.data);
            return MEMORY_ALLOCATION_ERROR;
        }

        if (array_stack_init(&stack_2_cp) != EXIT_SUCCESS)
        {
            free(stack_1_cp.data);
            free(temp_stack.data);
            return MEMORY_ALLOCATION_ERROR;
        }

        array_stack_copy(array_stack_1, &stack_1_cp, &temp_stack);
        array_stack_copy(array_stack_2, &stack_2_cp, &temp_stack);

        start = microseconds_now();
        array_stack_sort(&stack_1_cp, &stack_2_cp, array_stack_res);
        end = microseconds_now();

        arr_time += (end - start);
    }

    arr_time /= 100;

    for (int i = 0; i < 100; i++)
    {
        if (*head_res != NULL)
        {
            list_stack_free(head_res);
            *head_res = NULL;
        }

        node_t *head_1_cp = NULL, *head_2_cp = NULL, *tmp_stack = NULL;

        list_stack_copy(head_1, &head_1_cp, &tmp_stack);
        list_stack_copy(head_2, &head_2_cp, &tmp_stack);

        start = microseconds_now();
        list_stack_sort(&head_1_cp, &head_2_cp, head_res);
        end = microseconds_now();

        list_time += (end - start);
    }

    list_time /= 100;

    arr_stack_t stack_1cp, stack_2cp, tempstack;
    array_stack_copy(array_stack_1, &stack_1cp, &tempstack);
    array_stack_copy(array_stack_2, &stack_2cp, &tempstack);

    array_stack_sort(&stack_1cp, &stack_2cp, array_stack_res);

    printf("\n                 Сортировка стека-массива         Сортировка стека-списка\n");
    printf("Объем памяти:          %lu Б, 100%%                     %lu Б, %lu%%\n", \
        (sizeof(arr_stack_t) + sizeof(int) * array_stack_res->top), sizeof(node_t) * list_stack_size(*head_res), \
        (100 * sizeof(node_t) * list_stack_size(*head_res)) / ((sizeof(arr_stack_t) + sizeof(int) * array_stack_res->top)));
    printf("Время выполнения:      %llu мкс, 100%%                   %llu мкс, %llu%%\n", \
        arr_time, list_time, ((list_time * 100) / arr_time));

    return EXIT_SUCCESS;
}


unsigned long long microseconds_now(void)
{
    struct timeval val;

    if (gettimeofday(&val, NULL))
        return (unsigned long long) -1;

    return 1000000ULL * val.tv_sec + val.tv_usec;
}
