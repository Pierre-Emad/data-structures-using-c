/**
 * @author:      Pierre Emad
 * @create_time: 2023-11-21 23:36:35
 * @brief:       implementation of an array-based fixed size stack
 */

#include <stdio.h>
#include <stdlib.h>
#include "STACK_FIXED.h"

static stack_status_t is_stack_full(const STACK_FIXED_t *stack)
{
    if (STACK_FIXED_MAXSIZE-1 == stack->STACK_FIXED_pointer)
    {
        return STACK_FULL;
    }
    else 
    {
        return STACK_NOT_EMPTY;
    }
}

static stack_status_t is_stack_empty(const STACK_FIXED_t *stack)
{
    if (-1 == stack->STACK_FIXED_pointer)
    {
        return STACK_EMPTY;
    }
    else 
    {
        return STACK_NOT_EMPTY;
    }
}

return_status_t stack_fixed_init(STACK_FIXED_t *stack)
{
    if (NULL == stack)
    {
        printf("NULL pointer was passed to function\n");
        return R_NOK;
    }
    else
    {
        stack->STACK_FIXED_pointer = -1;
        return R_OK;
    }
}

/*
 * @brief push an element to the stack
 * @param stack Pointer to the stack
 * @param value Value to be pushed
 * @retval Status of the function
 */
return_status_t stack_fixed_push(STACK_FIXED_t *stack, uint32_t value)
{
    if (NULL == stack || STACK_FULL == is_stack_full(stack))
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function or Full stack\n");
        #endif
        return R_NOK;
    }
    else
    {
        (stack->STACK_FIXED_pointer)++;
        stack->STACK_FIXED_data[stack->STACK_FIXED_pointer] = value;
        #ifdef STACK_DEBUG_MODE
        printf("Value %i was pushed successfully\n", stack->STACK_FIXED_data[stack->STACK_FIXED_pointer]);
        #endif
        return R_OK;
    }
}

return_status_t stack_fixed_pop(STACK_FIXED_t *stack, uint32_t *ret_value)
{
    if (NULL == stack || NULL == ret_value || STACK_EMPTY == is_stack_empty(stack))
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function or Empty stack\n");
        #endif
        return R_NOK;
    }
    else
    {
        *ret_value = stack->STACK_FIXED_data[stack->STACK_FIXED_pointer];
        stack->STACK_FIXED_pointer--;
        #ifdef STACK_DEBUG_MODE
        printf("Value %i was popped successfully\n", *ret_value);
        #endif
        return R_OK;
    }
}

return_status_t stack_fixed_top(STACK_FIXED_t *stack, uint32_t *ret_value)
{
    if (NULL == stack || NULL == ret_value || STACK_EMPTY == is_stack_empty(stack))
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function or Empty stack\n");
        #endif
        return R_NOK;
    }
    else
    {
        *ret_value = stack->STACK_FIXED_data[stack->STACK_FIXED_pointer];
        return R_OK;
    }
}

return_status_t stack_fixed_size(STACK_FIXED_t *stack, uint32_t *ret_value)
{
    if (NULL == stack || NULL == ret_value)
    {   
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        return R_NOK;
    }
    else
    {
        *ret_value = (stack->STACK_FIXED_pointer) + 1;
        return R_OK;
    }
}

return_status_t stack_fixed_print(const STACK_FIXED_t *stack)
{
    if (NULL == stack || STACK_EMPTY == is_stack_empty(stack))
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function or Empty stack\n");
        #endif
        return R_NOK;
    }
    else
    {
        sint32_t it = 0;
        printf("Stack elements are: ");
        for (it = stack->STACK_FIXED_pointer; it > 0; it--)
        {
            printf("%i ", stack->STACK_FIXED_data[it]);
        }
        printf("\n");
        return R_OK;
    }
}
