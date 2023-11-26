/**
  * @file	STACK_DYNAMIC.c
  * @author	Pierre Emad
  * @brief	implementation of an array-based dynamic size stack
  */

#include <stdio.h>
#include <stdlib.h>
#include "STACK_DYNAMIC.h"

STACK_DYNAMIC_t* stack_dynamic_create(uint32_t max_size, stack_status_t *ret_status)
{
    STACK_DYNAMIC_t *stack = NULL;
    if (NULL == ret_status)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        stack = (STACK_DYNAMIC_t *) malloc(sizeof(STACK_DYNAMIC_t));
        if (NULL == stack)
        {
            #ifdef STACK_DEBUG_MODE
            printf("NULL pointer was created in function\n");
            #endif
            *ret_status = STACK_NOK;
        }
        else
        {
            stack->STACK_DYNAMIC_top = -1;
            stack->STACK_DYNAMIC_count = 0;
            stack->STACK_DYNAMIC_size = max_size;
            stack->STACK_DYNAMIC_array = (void **) calloc(max_size, sizeof(void *));
            if (NULL == stack->STACK_DYNAMIC_array)
            {
                #ifdef STACK_DEBUG_MODE
                printf("NULL pointer was created in function\n");
                #endif
                free(stack->STACK_DYNAMIC_array);
                *ret_status = STACK_NOK;
            }
            else
            {
                *ret_status = STACK_OK;
            }
        }
    }
    return stack;
}

STACK_DYNAMIC_t* stack_dynamic_free(STACK_DYNAMIC_t *stack, stack_status_t *ret_status)
{
    STACK_DYNAMIC_t *ret_ptr = NULL; // return null pointer if freed
    if (NULL == stack || NULL == ret_status)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_ptr = stack; // return original stack pointer if not freed
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        free(stack->STACK_DYNAMIC_array);
        free(stack);
        *ret_status = STACK_OK;
    }
    return ret_ptr;
}

stack_status_t stack_dynamic_push(STACK_DYNAMIC_t *stack, uint32_t value)
{
    stack_status_t ret_status = STACK_NOK;
    if (NULL == stack)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if (stack->STACK_DYNAMIC_count == stack->STACK_DYNAMIC_size)
        {
            #ifdef STACK_DEBUG_MODE
            printf("Stack is full, cannot push\n");
            #endif
            ret_status = STACK_FULL;
        }
        else
        {
            (stack->STACK_DYNAMIC_top)++;
            stack->STACK_DYNAMIC_array[stack->STACK_DYNAMIC_top] = value;
            (stack->STACK_DYNAMIC_count)++;
            ret_status = STACK_OK;
        }
    }
    return ret_status;
}

void* stack_dynamic_pop(STACK_DYNAMIC_t *stack, stack_status_t *ret_status)
{
    void *ret_value = NULL;
    if (NULL == stack || NULL == ret_status)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if (stack->STACK_DYNAMIC_count == 0)
        {
            #ifdef STACK_DEBUG_MODE
            printf("Stack is empty, cannot pop\n");
            #endif
            *ret_status = STACK_EMPTY;
        }
        else
        {
            ret_value = stack->STACK_DYNAMIC_array[stack->STACK_DYNAMIC_top];
            (stack->STACK_DYNAMIC_top)--;
            (stack->STACK_DYNAMIC_count)--;
            *ret_status = STACK_OK;
        }
    }
    return ret_value;
}

void* stack_dynamic_top(STACK_DYNAMIC_t *stack, stack_status_t *ret_status)
{
    void *ret_value = NULL;
    if (NULL == stack || NULL == ret_status)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if (stack->STACK_DYNAMIC_count == 0)
        {
            #ifdef STACK_DEBUG_MODE
            printf("Stack is empty, there is no top\n");
            #endif
            *ret_status = STACK_EMPTY;
        }
        else
        {
            ret_value = stack->STACK_DYNAMIC_array[stack->STACK_DYNAMIC_top];
            *ret_status = STACK_OK;
        }
    }
    return ret_value;
}

stack_status_t stack_dynamic_count(STACK_DYNAMIC_t *stack, uint32_t *ret_count)
{
    stack_status_t ret_status = STACK_NOK;
    if (NULL == stack || NULL == ret_count)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = STACK_NULL_POINTER;
    }
    else
    {
        *ret_count = stack->STACK_DYNAMIC_count;
        ret_status = STACK_OK;
    }
    return ret_status;
}

stack_status_t stack_dynamic_print(const STACK_DYNAMIC_t *stack)
{
    stack_status_t ret_status = STACK_NOK;
    if (NULL == stack)
    {
        #ifdef STACK_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        ret_status = STACK_NULL_POINTER;
    }
    else
    {
        if (stack->STACK_DYNAMIC_count == 0)
        {
            #ifdef STACK_DEBUG_MODE
            printf("Stack is empty, cannot print\n");
            #endif
            ret_status = STACK_EMPTY;
        }
        else
        {
            uint32_t it = 0;
            printf("Stack elements are: ");
            for (it = stack->STACK_DYNAMIC_top; it > 0; it--)
            {
                printf("%i ", stack->STACK_DYNAMIC_array[it]);
            }
            printf("%i\n", stack->STACK_DYNAMIC_array[it]);
            ret_status = STACK_OK;
        }
    }
    return ret_status;
}
