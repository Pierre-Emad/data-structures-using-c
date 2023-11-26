/**
  * @file	main.c
  * @author	Pierre Emad
  * @brief	showcasing of different stack implementations
  */
#include <stdio.h>
#include <stdlib.h>
#include "STACK_DYNAMIC.h"

int main()
{
    uint32_t ret_val = 0;
    void *ret_ptr = NULL;
    return_status_t ret_stat = R_OK;    // for fixed stack
    stack_status_t status = R_OK;       // for dynamic stack
    
    #ifdef _STACK_FIXED_H
    STACK_FIXED_t st;
    ret_stat &= stack_fixed_init(&st);
    #endif
    
    #ifdef _STACK_DYNAMIC_H
    STACK_DYNAMIC_t *st;
    st = stack_dynamic_create(10, &status);
    #endif
    
    if (R_NOK == status || R_NOK == ret_stat)
    {
        printf("Stack initialization failed\n");
    }
    else
    {
        #ifdef _STACK_FIXED_H
        printf("Fixed Stack ... \n");
        ret_stat &= stack_fixed_push(&st, 9);
        ret_stat &= stack_fixed_push(&st, 2);
        ret_stat &= stack_fixed_push(&st, 8);
        ret_stat &= stack_fixed_print(&st);
        ret_stat &= stack_fixed_pop(&st, &ret_val);
        ret_stat &= stack_fixed_top(&st, &ret_val);
        printf("top value = %i\n", ret_val);
        ret_stat &= stack_fixed_push(&st, 4);
        ret_stat &= stack_fixed_top(&st, &ret_val);
        printf("top value = %i\n", ret_val);
        ret_stat &= stack_fixed_push(&st, 5);
        ret_stat &= stack_fixed_push(&st, 6);
        ret_stat &= stack_fixed_print(&st);
        #endif

        #ifdef _STACK_DYNAMIC_H
        printf("Dynamic Stack ... \n");
        status = stack_dynamic_push(st, 5);
        PRINT_STATUS(status);
        
        ret_ptr = (uint32_t *) stack_dynamic_top(st, &status);
        printf("Top element in the stack is %i\n", ret_ptr);
        PRINT_STATUS(status);
        
        status = stack_dynamic_push(st, 6);
        PRINT_STATUS(status);

        status = stack_dynamic_push(st, 7);
        PRINT_STATUS(status);

        status = stack_dynamic_print(st);
        PRINT_STATUS(status);

        status = stack_dynamic_count(st, &ret_val);
        printf("Size of the stack is %i\n", ret_val);
        PRINT_STATUS(status);

        ret_ptr = (uint32_t *) stack_dynamic_pop(st, &status);
        printf("Popped value is %i\n", ret_ptr);
        PRINT_STATUS(status);

        status = stack_dynamic_count(st, &ret_val);
        printf("Size of the stack is %i\n", ret_val);
        PRINT_STATUS(status);

        status = stack_dynamic_print(st);
        PRINT_STATUS(status);

        ret_ptr = (uint32_t *) stack_dynamic_top(st, &status);
        printf("Top element in the stack is %i\n", ret_ptr);
        PRINT_STATUS(status);

        status = stack_dynamic_push(st, 'p');
        PRINT_STATUS(status);

        ret_ptr = (char *) stack_dynamic_top(st, &status);
        printf("Top element in the stack is %c\n", ret_ptr);
        PRINT_STATUS(status);

        st = stack_dynamic_free(st, &status);
        if (st == NULL && status == STACK_OK)
        {
            printf("Dynamic stack was freed sucessfully\n");
        }
        else
        {
            printf("Dynamic stack was not freed sucessfully\n");
        }
        #endif
        
    }

    return 0;
}