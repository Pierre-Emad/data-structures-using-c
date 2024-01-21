/**
  * @file	LINKEDLIST_S.c
  * @author	Pierre Emad
  * @brief	source file for single linked list implementation
  */

#include <stdio.h>
#include <stdlib.h>
#include "LINKEDLIST_S.h"

void linkedlist_insertAtStart(node **linked_list_head, uint32_t data)
{
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
        }
        else
        {
            /* if it wasn't empty, the new node points to the old head */
            newNode->LINKEDLIST_next_node = *linked_list_head;
            *linked_list_head = newNode;
        }
    }
    else
    {
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Failed to allocate space for new node\n");
        #endif
    }
}

void linkedlist_insertAtEnd(node **linked_list_head, uint32_t data)
{
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
        }
    }
    else
    {
        #ifdef LINKEDLIST_DEBUG_MODE
        printf("Failed to allocate space for new node\n");
        #endif
    }
}

void linkedlist_insertAt(node *linked_list_head, uint32_t data, uint16_t insertPosition)
{
    node *newNode = NULL, *prevNode = NULL;
    uint16_t currentPosition = 1, listLength = 0;

    listLength = linkedlist_getLength(linked_list_head);

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
        }
    }
}

uint16_t linkedlist_getLength(node *linked_list_head)
{
    node *head = linked_list_head;
    uint16_t linked_list_length;
    if (head == NULL)
    {
        linked_list_length = 0;
    }
    else
    {
        linked_list_length = 0;
        while (head != NULL)
        {
            linked_list_length++;
            head = head->LINKEDLIST_next_node;
        }
    }
    return linked_list_length;
}

void linkedlist_print(node *linked_list_head)
{
    node *head = linked_list_head;
    if (head == NULL)
    {
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
    }
}
