/**
  * @file	STACK_DYNAMIC.h
  * @author	Pierre Emad
  * @brief	header file for array-based dynamic size stack implementation
  */

#ifndef _STACK_DYNAMIC_H
#define _STACK_DYNAMIC_H

#include "STD_TYPES.h"
#define STACK_DEBUG_MODE
#define PRINT_STATUS(status) printf("Status = %i\n", status)

typedef struct STACK_DYNAMIC_ds
{
    void **STACK_DYNAMIC_array;     // pointer to heap-allocated array
    uint32_t STACK_DYNAMIC_count;   // actual number of elements in the stack
    uint32_t STACK_DYNAMIC_size;    // maximum number of elements in the stack
    sint32_t STACK_DYNAMIC_top;     // index of the top element in the stack
} STACK_DYNAMIC_t;

typedef enum
{
    STACK_NOK,
    STACK_OK,
    STACK_EMPTY,
    STACK_FULL,
    STACK_NULL_POINTER
} stack_status_t;

STACK_DYNAMIC_t* stack_dynamic_create(uint32_t max_size, stack_status_t *ret_status);
STACK_DYNAMIC_t* stack_dynamic_free(STACK_DYNAMIC_t *stack, stack_status_t *ret_status);
stack_status_t   stack_dynamic_push(STACK_DYNAMIC_t *stack, uint32_t value);
void*            stack_dynamic_pop(STACK_DYNAMIC_t *stack, stack_status_t *ret_status);
void*            stack_dynamic_top(STACK_DYNAMIC_t *stack, stack_status_t *ret_status);
stack_status_t   stack_dynamic_count(STACK_DYNAMIC_t *stack, uint32_t *ret_count);
stack_status_t   stack_dynamic_print(const STACK_DYNAMIC_t *stack);

#endif
