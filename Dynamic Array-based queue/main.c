/**
  * @file	main.c
  * @author	Pierre Emad
  * @brief	showcasing queue implementation using array
  */

#include <stdio.h>
#include <stdlib.h>
#include "QUEUE.h"

uint32_t arr[] = {5, 6, 7, 8, 9};
uint32_t queue_max_size = 4;
QUEUE_t *queue;
void *queue_ret_val;
QUEUE_STATUS_t queue_status = QUEUE_NOK;

int main()
{
	queue = queue_create(queue_max_size, &queue_status);
	if (NULL == queue)
	{
		printf("Queue initialization failed\n");
	}
	else
	{
		#define PRINT_QUEUE_STATUS printf("rear = %i, front = %i\n", \
					*((uint32_t *) queue_rear(queue, &queue_status)),\
					*((uint32_t *) queue_front(queue, &queue_status)))

		for (int i = 0; i < 5; i++)
		{
			queue_status = queue_enqueue(queue, &arr[i]);
			PRINT_QUEUE_STATUS;
		}

		queue_ret_val = queue_dequeue(queue, &queue_status);
		printf("dequeued element: %i\n", *((uint32_t *) queue_ret_val));
		PRINT_QUEUE_STATUS;
		
		queue_status = queue_count(queue, ((uint32_t *) queue_ret_val));
		printf("size of queue: %i\n", *((uint32_t *) queue_ret_val));

		queue_ret_val = queue_front(queue, &queue_status);
		printf("front element: %i\n", *((uint32_t *) queue_ret_val));
		queue_ret_val = queue_rear(queue, &queue_status);
		printf("rear element: %i\n", *((uint32_t *) queue_ret_val));

		for (int i = 0; i < 5; i++)
		{
			queue_ret_val = queue_dequeue(queue, &queue_status);
		}

		queue_status = queue_free(queue);

	}
	
  	return 0;
}
