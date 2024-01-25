/**
  * @file	LINKEDLIST_S.h
  * @author	Pierre Emad
  * @brief	header file for single linked list implementation
  */

#ifndef _LINKED_LIST_SINGLE_H
#define _LINKED_LIST_SINGLE_H

#include "STD_TYPES.h"

#define LINKEDLIST_DEBUG_MODE

/* S --> singly linked */
typedef struct LINKEDLIST_NODE_S
{
    uint32_t LINKEDLIST_data; // data held in the node
    struct LINKEDLIST_NODE_S *LINKEDLIST_next_node; // pointer to the next node
} node;

typedef enum
{
    LINKEDLIST_NOK,
    LINKEDLIST_OK,
    LINKEDLIST_FULL,
    LINKEDLIST_EMPTY,
    LINKEDLIST_NULL_POINTER
} LINKEDL_STATUS_t;


/**
  * @brief insert a node at the beginning of the linked list
  * @param linked_list_head pointer to the head of the list
  * @param data data to be inserted
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_insertAtStart(node **linked_list_head, uint32_t data);

/**
  * @brief insert a node at the end of the linked list
  * @param linked_list_head pointer to the head of the list
  * @param data data to be inserted
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_insertAtEnd(node **linked_list_head, uint32_t data);

/**
  * @brief insert a node at a certain position
  * @param linked_list_head the head of the list
  * @param data data to be inserted
  * @param insertPosition position of the new node
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_insertAt(node *linked_list_head, uint32_t data, uint16_t insertPosition);

/**
  * @brief delete the node at the start of the list
  * @param linked_list_head a pointer to the head of the list
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_deleteAtStart(node **linked_list_head);

/**
  * @brief deletes the node at a certain position
  * @param linked_list_head the head of the list
  * @param deletePosition position of the node to be deleted
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_deleteAt(node *linked_list_head, uint16_t deletePosition);

/**
  * @brief deletes (frees) the entire list from memory
  * @param linked_list_head a pointer to the head of the list
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_deleteList(node **linked_list_head);

/**
  * @brief print the contents of the list
  * @param linked_list_head head of the list
  * @retval function status
  */
LINKEDL_STATUS_t linkedlist_print(node *linked_list_head);

/**
  * @brief get the length of the given linked list
  * @param linked_list_head the head of the list
  * @param status pointer to status variable (pass NULL if not needed)
  * @retval the length of the linked list
  */
uint16_t linkedlist_getLength(node *linked_list_head, LINKEDL_STATUS_t *status);

#endif
