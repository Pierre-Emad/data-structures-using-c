#include <stdio.h>
#include <stdlib.h>
#include "STACK_ArrayBased.h"

STACK_ArrayBased_t st1, st2;

int main()
{
    return_status_t ret = R_OK;
    uint32_t ret_val = 0;
    ret &= stack_init(&st1);
    ret &= stack_init(&st2);

    if (ret == R_NOK)
    {
        printf("Stack initialization failed\n");
    }
    else
    {
        ret &= stack_push(&st1, 5);
        ret &= stack_push(&st1, 6);
        ret &= stack_push(&st1, 7);
        ret &= stack_pop(&st1, &ret_val);
        ret &= stack_top(&st1, &ret_val);
        printf("return value = %i\n", ret_val);
        ret &= stack_push(&st1, 50);
        ret &= stack_top(&st1, &ret_val);
        printf("return value = %i\n", ret_val);
        ret &= stack_push(&st1, 8);
        ret &= stack_push(&st1, 10);
        ret &= stack_print(&st1);
    }

    return 0;
}