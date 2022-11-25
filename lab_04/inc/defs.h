#ifndef __DEFS_H__
#define __DEFS_H__

#include <stdlib.h>
#include <stdio.h>

typedef enum {
    EXIT,
    STACK_APPEND,
    STACK_DEL,
    PRINT_STACKS,
    SORT_STACKS,
    EFFICIENCY_RESULT,
} menu_item_t;

#define FILLED_CHECK(a, b, c, d)                                               				  \
    if (array_stack_empty(&a) == STACK_EMPTY ||                                               \
        array_stack_empty(&b) == STACK_EMPTY ||                                               \
        list_stack_empty(c) == STACK_EMPTY ||                                                 \
        list_stack_empty(d) == STACK_EMPTY)                         					      \
    {                                                                    					  \
        printf("\n%sДля выполнения операций необходимо ввести cтеки.%s\n", RED, RESET);     \
        break;                                                          					  \
    }

#define INIT_TOP                        0
#define MAX_STACK_SIZE                  1000
#define MAX_LEN_ARR_PTRS                300

#define EXIT_SUCCESS                    0
#define MEMORY_ALLOCATION_ERROR         240
#define STACK_OVERFLOW                  241
#define STACK_UNDERFLOW                 242
#define STACK_EMPTY                     243
#define STACK_FILL_ERROR                244
#define STACK_NUMBER_ERROR              245
#define STACK_POP_NUMBER_ERROR          246
#define MENU_NUMBER_ERROR               247

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define PURPLE  "\033[1;35m"
#define BLACK   "\033[1;39m"


#endif // __DEFS_H__
