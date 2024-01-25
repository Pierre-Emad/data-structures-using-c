/**
  * @file	LINKEDLIST_S.c
  * @author	Pierre Emad
  * @brief	source file for single linked list implementation
  */

#include <stdio.h>
#include <stdlib.h>
#include "LINKEDLIST_S.h"

LINKEDL_STATUS_t linkedlist_insertAtStart(node **linked_list_head, uint32_t data)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node *newNode = NULL;
    newNode = (node *) malloc(sizeof(node));
    if (newNode != NULL)
    {
        newNode->LINKEDLIST_data = data;

        /* check if the list was empty */
        if (*linked_list_head == NULL)
        {
            /* if the list was empty, the new node points to null */
            newNode->LINKEDLIST_next_node = NULL;
            *linked_list_head = newNode;
            ret_status = LINKEDLIST_EMPTY;
        }
        else
        {
            /* if it wasn't empty, the new node points to the old head */
            newNode->LINKEDLIST_next_node = *linked_list_head;
            *linked_list_head = newNode;
            ret_status = LINKEDLIST_OK;
        }
    }
    else
    {
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Failed to allocate space for new node\n");
        #endif
    }
    return ret_status;
}

LINKEDL_STATUS_t linkedlist_insertAtEnd(node **linked_list_head, uint32_t data)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node* newNode = NULL;
    node* lastNode = NULL; // will be needed in case of non-empty list
    newNode = (node *) malloc(sizeof(node));
    if (NULL != newNode)
    {
        newNode->LINKEDLIST_data = data;
        newNode->LINKEDLIST_next_node = NULL;
        
        /* the linked list is empty */
        if (*linked_list_head == NULL)
        {
            *linked_list_head = newNode;
            ret_status = LINKEDLIST_EMPTY;
        }
        else
        {
            /* the list is not empty, we need to find the last node first */
            lastNode = *linked_list_head;
            while (lastNode->LINKEDLIST_next_node != NULL)
            {
                lastNode = lastNode->LINKEDLIST_next_node;
            }
            /* the new node will be after the last node in the list */
            lastNode->LINKEDLIST_next_node = newNode;
            ret_status = LINKEDLIST_OK;
        }
    }
    else
    {
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Failed to allocate space for new node\n");
        #endif
    }
    return ret_status;
}

LINKEDL_STATUS_t linkedlist_insertAt(node *linked_list_head, uint32_t data, uint16_t insertPosition)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node *newNode = NULL, *prevNode = NULL;
    uint16_t currentPosition = 1, listLength = 0;

    listLength = linkedlist_getLength(linked_list_head, NULL);

    if (insertPosition == 1)
    {
        printf("Please use linkedlist_insertAtStart() function to insert at position 1\n");
    }
    else if (insertPosition > listLength)
    {
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Insert Position is greater than the list size\n");
        #endif
    }
    else
    {
        newNode = (node *) malloc(sizeof(node));
        if (newNode == NULL)
        {
            ret_status = LINKEDLIST_NOK;
            #ifdef LINKEDLIST_DEBUG_MODE
            printf("Failed to allocate space for new node\n");
            #endif
        }
        else
        {
            prevNode = linked_list_head;
            while (currentPosition < (insertPosition - 1))
            {
                prevNode = prevNode->LINKEDLIST_next_node;
                currentPosition++;
            }
            newNode->LINKEDLIST_data = data;
            /* connect the new node to the next node (leftside connection) */
            newNode->LINKEDLIST_next_node = prevNode->LINKEDLIST_next_node;
            /* connect the previous node to the new node (rightside connection) */
            prevNode->LINKEDLIST_next_node = newNode;
            ret_status = LINKEDLIST_OK; 
        }
    }
    return ret_status;
}

LINKEDL_STATUS_t linkedlist_deleteAtStart(node **linked_list_head)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node* oldHead = *linked_list_head;
    if (oldHead == NULL)
    {
        ret_status = LINKEDLIST_EMPTY;
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("List is empty, cannot delete\n");
        #endif
    }
    else
    {
        *linked_list_head = oldHead->LINKEDLIST_next_node;
        oldHead->LINKEDLIST_next_node = NULL; // to avoid dangling pointers
        free(oldHead);
        ret_status = LINKEDLIST_OK;
    }
    return ret_status;
}

LINKEDL_STATUS_t linkedlist_deleteAt(node *linked_list_head, uint16_t deletePosition)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node *oldNode = NULL, *prevNode = NULL;
    uint16_t currentPosition = 1, listLength = 0;

    listLength = linkedlist_getLength(linked_list_head, NULL);

    if (deletePosition == 1)
    {
        printf("Please use linkedlist_deleteAtStart() function\n");
    }
    else if (deletePosition > listLength)
    {
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Deletion Position is greater than the list size\n");
        #endif
    }
    else
    {
        prevNode = linked_list_head;
        while (currentPosition < deletePosition - 1)
        {
            prevNode = prevNode->LINKEDLIST_next_node;
            currentPosition++;
        }
        oldNode = prevNode->LINKEDLIST_next_node;
        prevNode->LINKEDLIST_next_node = oldNode->LINKEDLIST_next_node;
        oldNode->LINKEDLIST_next_node = NULL;
        free(oldNode);
        ret_status = LINKEDLIST_OK;
    }
    return ret_status;
}

LINKEDL_STATUS_t linkedlist_deleteList(node **linked_list_head)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node *tempHead = NULL, *freeNode = NULL;
    
    if (*linked_list_head == NULL)
    {
        ret_status = LINKEDLIST_EMPTY;
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Linked list is either empty or not created, cannot delete list\n");
        #endif
    }
    else
    {
        tempHead = *linked_list_head;
        while (tempHead != NULL)
        {
            freeNode = tempHead;
            tempHead = tempHead->LINKEDLIST_next_node;
            free(freeNode);
        }
        ret_status = LINKEDLIST_OK;
    }
    return ret_status;
}

uint16_t linkedlist_getLength(node *linked_list_head, LINKEDL_STATUS_t *status)
{
    node *head = linked_list_head;
    uint16_t linked_list_length;
    linked_list_length = 0;
    while (head != NULL)
    {
        linked_list_length++;
        head = head->LINKEDLIST_next_node;
    }
    if (status != NULL)
    {
        if (linked_list_length == 0)
        {
            *status = LINKEDLIST_EMPTY;
        }
        else
        {
            *status = LINKEDLIST_OK;
        }
    }
    else {}
    return linked_list_length;
}

LINKEDL_STATUS_t linkedlist_print(node *linked_list_head)
{
    LINKEDL_STATUS_t ret_status = LINKEDLIST_NOK;
    node *head = linked_list_head;
    if (head == NULL)
    {
        ret_status = LINKEDLIST_EMPTY;
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Linked list is empty, cannot print\n");
        #endif
    }
    else
    {
        while (head != NULL)
        {
            printf("%i ", (head->LINKEDLIST_data));
            head = head->LINKEDLIST_next_node;
        }
        printf("\n");
        ret_status = LINKEDLIST_OK;
    }
    return ret_status;
}
