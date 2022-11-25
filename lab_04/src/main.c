#include "operations.h"
#include "read_print.h"
#include "defs.h"

#include <stdio.h>

void print_menu();

int main(void)
{
    system("clear");
    printf("\n\n            %s<<Сортировка двух стeков в третий>>%s\n\n"
           "                     <Информация>\n"
           "* Вводится пункт меню - целое число от 0 до 5.\n"
           "* Элементы стека вводятся через пробел - целые числа.\n"
           "* Нумерация идет с нуля.\n"
           "* Размер стека ограничен программой по умолчанию.\n"
           "* При попытке совершить операцию над пустыми стеками будет ошибка.\n", BLACK, RESET);

    int running = true;
    arr_stack_t array_stack_1, array_stack_2, array_stack_res;
    node_t *head_1 = NULL, *head_2 = NULL, *head_res = NULL;
    freed.len = 0;

    while (running)
    {
        int rc = 0;
        print_menu();
        menu_item_t menu_number;
        if (scanf("%d", &menu_number) == 1 && menu_number >= 0 && menu_number <= 5)
        {
            switch (menu_number) {
                case EXIT:
                    running = false;
                    break;
                case STACK_APPEND:
                    rc = load_stacks(&head_1, &head_2, &array_stack_1, &array_stack_2);
                    break;
                case STACK_DEL:
                    FILLED_CHECK(array_stack_1, array_stack_2, head_1, head_2)
                    rc = del_stacks(&head_1, &head_2, &array_stack_1, &array_stack_2);
                    break;
                case PRINT_STACKS:
                    FILLED_CHECK(array_stack_1, array_stack_2, head_1, head_2)
                    print_stacks(&head_1, &head_2, &array_stack_1, &array_stack_2, &head_res, &array_stack_res);
                    break;
                case SORT_STACKS:
                    FILLED_CHECK(array_stack_1, array_stack_2, head_1, head_2)
                    rc = sort_stacks(&head_1, &head_2, &array_stack_1, &array_stack_2, &head_res, &array_stack_res);
                    break;
                case EFFICIENCY_RESULT:
                    FILLED_CHECK(array_stack_1, array_stack_2, head_1, head_2)
                    rc = efficiency_result(&head_1, &head_2, &array_stack_1, &array_stack_2, &head_res, &array_stack_res);
                    break;
                default:
                    printf("\n%sНеверный пункт меню.%s\n", RED, RESET);
                    getchar();
            }
        }
        else
        {
            printf("\n%sНеверный пункт меню.%s\n", RED, RESET);
            getchar();
        }

        if (rc != EXIT_SUCCESS)
            print_error(rc);
    }

    return EXIT_SUCCESS;
}

void print_menu()
{
    printf("\n                     %sМЕНЮ:%s\n\n"
           "  1. Добавить элементы в стеки\n"
           "  2. Удалить элементы из стеков\n"
           "  3. Вывести текущее состояние стеков\n"
           "  4. Отсортировать два стека в третий\n"
           "  5. Сравнить методы хранения и обработки стека по времени и памяти\n"
           "  0. Выйти из программы\n", PURPLE, RESET);
    printf("Введите пункт меню: ");
}

