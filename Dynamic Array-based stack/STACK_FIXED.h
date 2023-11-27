/**
  * @file	STACK_DYNAMIC.h
  * @author	Pierre Emad
  * @brief	header file for array-based fixed size stack implementation
  */

#ifndef _STACK_FIXED_H
#define _STACK_FIXED_H

#include "STD_TYPES.h"
#define STACK_FIXED_MAXSIZE 10
#define STACK_DEBUG_MODE 

typedef struct STACK_FIXED_ds
{
    sint32_t STACK_FIXED_pointer;
    uint32_t STACK_FIXED_data[STACK_FIXED_MAXSIZE];
} STACK_FIXED_t;

typedef enum
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_EMPTY
} stack_status_t;

return_status_t stack_fixed_init(STACK_FIXED_t *stack);
return_status_t stack_fixed_push(STACK_FIXED_t *stack, uint32_t value);
return_status_t stack_fixed_pop(STACK_FIXED_t *stack, uint32_t *ret_value);
return_status_t stack_fixed_top(STACK_FIXED_t *stack, uint32_t *ret_value);
return_status_t stack_fixed_size(STACK_FIXED_t *stack, uint32_t *ret_value);
return_status_t stack_fixed_print(const STACK_FIXED_t *stack);

#endif

