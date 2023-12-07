#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"

#define QUEUE_DEBUG_MODE

typedef struct QUEUE_ds
{
    void **QUEUE_array;     // pointer to array of pointers to the elements of the queue
    uint32_t QUEUE_size;    // maximum size of the queue
    uint32_t QUEUE_count;   // actual size of the queue
    sint32_t QUEUE_front;   // index of front element
    sint32_t QUEUE_rear;    // index of rear element
} QUEUE_t;

typedef enum
{
    QUEUE_NOK,
    QUEUE_OK,
    QUEUE_FULL,
    QUEUE_EMPTY,
    QUEUE_NULL_POINTER
} QUEUE_STATUS_t;

/**
  * @brief create the queue
  * @param max_size maximum size of the queue
  * @param ret_status returned status of the function
  * @retval pointer to the created queue, returns NULL if not created
  */
QUEUE_t* queue_create(uint32_t max_size, QUEUE_STATUS_t *ret_status);

/**
  * @brief add an element to the queue
  * @param queue pointer to the queue
  * @param value value to be added to the queue
  * @retval status of the function
  */
QUEUE_STATUS_t queue_enqueue(QUEUE_t *queue, void *value);

/**
  * @brief remove an element from the queue
  * @param queue pointer to the queue
  * @param ret_status returned status of the function
  * @retval pointer to the removed value, returns NULL if dequeing failed
  */
void* queue_dequeue(QUEUE_t *queue, QUEUE_STATUS_t *ret_status);

/**
  * @brief outputs the front value of the queue
  * @param queue pointer to the queue
  * @param ret_status returned status of the function
  * @retval pointer to the front value, returns NULL if there is no front element
  */
void* queue_front(QUEUE_t *queue, QUEUE_STATUS_t *ret_status);

/**
  * @brief outputs the rear value of the queue
  * @param queue pointer to the queue
  * @param ret_status returned status of the function
  * @retval pointer to the rear value, returns NULL if there is no rear element
  */
void* queue_rear(QUEUE_t *queue, QUEUE_STATUS_t *ret_status);

/**
  * @brief outputs the actual size of the queue
  * @param queue pointer to the queue
  * @param ret_count pointer to the value to return the actual size
  * @retval status of the function
  */
QUEUE_STATUS_t queue_count(QUEUE_t *queue, uint32_t *ret_count);

/**
  * @brief free/destroy the queue
  * @param queue pointer to the queue
  * @retval status of the function
  */
QUEUE_STATUS_t queue_free(QUEUE_t *queue);

#endif