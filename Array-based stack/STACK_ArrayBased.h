#ifndef _STACK_ARRAY_BASED_H
#define _STACK_ARRAY_BASED_H

#include "STD_TYPES.h"
#define STACK_ArrayBased_MAXSIZE 5
#define STACK_DEBUG_MODE 1

typedef struct STACK_ArrayBased_ds
{
    sint32_t STACK_ArrayBased_pointer;
    uint32_t STACK_ArrayBased_data[];
} STACK_ArrayBased_t;

typedef enum
{
    STACK_EMPTY,
    STACK_FULL,
    STACK_NOT_EMPTY
} stack_status_t;

return_status_t stack_init(STACK_ArrayBased_t *stack);
return_status_t stack_push(STACK_ArrayBased_t *stack, uint32_t value);
return_status_t stack_pop(STACK_ArrayBased_t *stack, uint32_t *ret_value);
return_status_t stack_top(STACK_ArrayBased_t *stack, uint32_t *ret_value);
return_status_t stack_size(STACK_ArrayBased_t *stack, uint32_t *ret_value);
return_status_t stack_print(STACK_ArrayBased_t *stack);


#endif
