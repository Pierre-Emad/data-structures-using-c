/**
  * @file	QUEUE.c
  * @author	Pierre Emad
  * @brief	queue data structure implementation
  */
 
 #include "QUEUE.h"

QUEUE_t *queue_create(uint32_t max_size, QUEUE_STATUS_t *ret_status)
{
    QUEUE_t *queue = NULL;
    if (NULL == ret_status)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = QUEUE_NULL_POINTER;
    }
    else if (0 == max_size)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("cannot create queue of size 0\n");
        #endif
        *ret_status = QUEUE_NOK;
    }
    else
    {
        queue = (QUEUE_t *) malloc(sizeof(QUEUE_t));
        if (NULL == queue)
        {
            #ifdef QUEUE_DEBUG_MODE
            printf("NULL pointer was created in function\n");
            #endif
            free(queue);
            *ret_status = QUEUE_NULL_POINTER;
        }
        else
        {
            queue->QUEUE_array = (void **) calloc(max_size, sizeof(void *));
            queue->QUEUE_count = 0;
            queue->QUEUE_size = max_size;
            queue->QUEUE_rear = -1;
            queue->QUEUE_front = -1;
            if (NULL == queue->QUEUE_array)
            {
                #ifdef QUEUE_DEBUG_MODE
                printf("NULL pointer was created in function\n");
                #endif
                free(queue->QUEUE_array);
                *ret_status = QUEUE_NULL_POINTER;
            }
            else
            {
                *ret_status = QUEUE_OK;
            }
        }
    }
    return queue;
}

QUEUE_STATUS_t queue_enqueue(QUEUE_t *queue, void *value)
{
    QUEUE_STATUS_t status = QUEUE_NOK;
    if (NULL == queue || NULL == value)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        status = QUEUE_NULL_POINTER;
    }
    else
    {
        if (queue->QUEUE_count == queue->QUEUE_size)
        {
            #ifdef QUEUE_DEBUG_MODE
            printf("Queue is full, cannot enqueue more elements\n");
            #endif
            status = QUEUE_FULL;
        }
        else
        {
            (queue->QUEUE_rear)++;
            if (queue->QUEUE_rear == queue->QUEUE_size)
            {
                /* circular queue */
                queue->QUEUE_rear = 0;
            }

            queue->QUEUE_array[queue->QUEUE_rear] = value;
            if (queue->QUEUE_count == 0)
            {
                queue->QUEUE_front = queue->QUEUE_rear;
            }
            (queue->QUEUE_count)++;
            status = QUEUE_OK;
        }
    }
    return status;
}

void *queue_dequeue(QUEUE_t *queue, QUEUE_STATUS_t *ret_status)
{
    void *ret_value = NULL;
    if (NULL == queue || NULL == ret_status)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if (queue->QUEUE_count == 0)
        {
            #ifdef QUEUE_DEBUG_MODE
            printf("Queue is empty, cannot dequeue any elements\n");
            #endif
            *ret_status = QUEUE_EMPTY;
            ret_value = NULL;
        }
        else
        {
            ret_value = queue->QUEUE_array[queue->QUEUE_front];
            (queue->QUEUE_front)++;
            if (queue->QUEUE_front == queue->QUEUE_size)
            {
                /* circular queue */
                queue->QUEUE_front = 0;
            }

            if (queue->QUEUE_count == 1)
            {
                /* queue will be empty */
                queue->QUEUE_front = -1;
                queue->QUEUE_rear = -1;
            }
            (queue->QUEUE_count)--;
            *ret_status = QUEUE_OK;
        }
    }
    return ret_value;
}

void *queue_front(QUEUE_t *queue, QUEUE_STATUS_t *ret_status)
{
    void *ret_value = NULL;
    if (NULL == queue || NULL == ret_status)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if (queue->QUEUE_front == -1 || queue->QUEUE_count == 0)
        {
            #ifdef QUEUE_DEBUG_MODE
            printf("queue is empty\n");
            #endif
            *ret_status = QUEUE_EMPTY;
            ret_value = NULL;
        }
        else
        {
            ret_value = queue->QUEUE_array[queue->QUEUE_front];
            *ret_status = QUEUE_OK;
        }
    }
    return ret_value;
}

void *queue_rear(QUEUE_t *queue, QUEUE_STATUS_t *ret_status)
{
    void *ret_value = NULL;
    if (NULL == queue || NULL == ret_status)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        *ret_status = QUEUE_NULL_POINTER;
    }
    else
    {
        if (queue->QUEUE_rear == -1 || queue->QUEUE_count == 0)
        {
            #ifdef QUEUE_DEBUG_MODE
            printf("queue is empty\n");
            #endif
            *ret_status = QUEUE_EMPTY;
            ret_value = NULL;
        }
        else
        {
            ret_value = queue->QUEUE_array[queue->QUEUE_rear];
            *ret_status = QUEUE_OK;
        }
    }
    return ret_value;
}

QUEUE_STATUS_t queue_count(QUEUE_t *queue, uint32_t *ret_count)
{
    QUEUE_STATUS_t status = QUEUE_NOK;
    if (NULL == queue || NULL == ret_count)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        status = QUEUE_NOK;
    }
    else
    {
        *ret_count = queue->QUEUE_count;
        if (*ret_count == 0)
        {
            status = QUEUE_EMPTY;
        }
        else
        {
            status = QUEUE_OK;
        }
    }
    return status;
}

QUEUE_STATUS_t queue_free(QUEUE_t *queue)
{
    QUEUE_STATUS_t status = QUEUE_NOK;
    if (NULL == queue)
    {
        #ifdef QUEUE_DEBUG_MODE
        printf("NULL pointer was passed to function\n");
        #endif
        status = QUEUE_NOK;
    }
    else
    {
        free(queue->QUEUE_array);
        free(queue);
        status = QUEUE_OK;
    }
    return status;
}
