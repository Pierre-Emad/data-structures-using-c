/**
  * @file	STACK_FIXED.c
  * @author	Pierre Emad
  * @brief	implementation of an array-based fixed size stack
  */

#include <stdio.h>
#include <stdlib.h>
#include "STACK_FIXED.h"

static stack_status_t is_stack_full(const STACK_FIXED_t *stack)
{
    stack_status_t ret_status = STACK_NOT_EMPTY;
    if (STACK_FIXED_MAXSIZE-1 == stack->STACK_FIXED_pointer)
    {
        ret_status = STACK_FULL;
    }
    else 
    {
        ret_status = STACK_NOT_EMPTY;
    }
    return ret_status;
}

static stack_status_t is_stack_empty(const STACK_FIXED_t *stack)
{
    stack_status_t ret_status = STACK_NOT_EMPTY;
    if (-1 == stack->STACK_FIXED_pointer)
    {
        ret_status = STACK_EMPTY;
    }
    else 
    {
        ret_status = STACK_NOT_EMPTY;
    }
    return ret_status;
}

return_status_t stack_fixed_init(STACK_FIXED_t *stack)
{
    return_status_t ret_status = R_OK;
    if (NULL == stack)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = R_NOK;
    }
    else
    {
        stack->STACK_FIXED_pointer = -1;
        ret_status = R_OK;
    }
    return ret_status;
}

return_status_t stack_fixed_push(STACK_FIXED_t *stack, uint32_t value)
{
    return_status_t ret_status = R_OK;
    if (NULL == stack || STACK_FULL == is_stack_full(stack))
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function or Full stack\n");
        #endif
        ret_status = R_NOK;
    }
    else
    {
        (stack->STACK_FIXED_pointer)++;
        stack->STACK_FIXED_data[stack->STACK_FIXED_pointer] = value;
        #ifdef STACK_DEBUG_MODE
        printf("Value %i was pushed\n", stack->STACK_FIXED_data[stack->STACK_FIXED_pointer]);
        #endif
        ret_status = R_OK;
    }
    return ret_status;
}

return_status_t stack_fixed_pop(STACK_FIXED_t *stack, uint32_t *ret_value)
{
    return_status_t ret_status = R_OK;
    if (NULL == stack || NULL == ret_value)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = R_NOK;
    }
    else
    {
        if (STACK_EMPTY == is_stack_empty(stack))
        {
            #ifdef STACK_DEBUG_MODE
            printf("Empty stack, cannot pop\n");
            #endif
        }
        else
        {
            *ret_value = stack->STACK_FIXED_data[stack->STACK_FIXED_pointer];
            (stack->STACK_FIXED_pointer)--;
            #ifdef STACK_DEBUG_MODE
            printf("Value %i was popped\n", *ret_value);
            #endif
            ret_status = R_OK;
        }
    }
    return ret_status;
}

return_status_t stack_fixed_top(STACK_FIXED_t *stack, uint32_t *ret_value)
{
    return_status_t ret_status = R_OK;
    if (NULL == stack || NULL == ret_value)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = R_NOK;
    }
    else
    {
        if (STACK_EMPTY == is_stack_empty(stack))
        {
            #ifdef STACK_DEBUG_MODE
            printf("Empty stack, there is no top\n");
            #endif
        }
        else
        {
            *ret_value = stack->STACK_FIXED_data[stack->STACK_FIXED_pointer];
            ret_status = R_OK;
        }
    }
    return ret_status;
}

return_status_t stack_fixed_size(STACK_FIXED_t *stack, uint32_t *ret_value)
{
    return_status_t ret_status = R_OK;
    if (NULL == stack || NULL == ret_value)
    {   
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = R_NOK;
    }
    else
    {
        *ret_value = (stack->STACK_FIXED_pointer) + 1;
        ret_status = R_OK;
    }
    return ret_status;
}

return_status_t stack_fixed_print(const STACK_FIXED_t *stack)
{
    return_status_t ret_status = R_OK;
    if (NULL == stack)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = R_NOK;
    }
    else
    {
        if (STACK_EMPTY == is_stack_empty(stack))
        {
            #ifdef STACK_DEBUG_MODE
            printf("Empty stack, no elements to print\n");
            #endif
        }
        else
        {
            sint32_t it = 0;
            printf("Stack elements are: ");
            for (it = stack->STACK_FIXED_pointer; it >= 0; it--)
            {
                printf("%i ", stack->STACK_FIXED_data[it]);
            }
            printf("\n");
            ret_status = R_OK;
        }
    }
    return ret_status;
}
