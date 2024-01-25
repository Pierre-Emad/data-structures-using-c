/**
  * @file	main.c
  * @author	Pierre Emad
  * @brief	showcase of different linked list implementations
  */

#include <stdio.h>
#include <stdlib.h>
#include "LINKEDLIST_S.h"

int main()
{
    node *single_list = NULL;
    linkedlist_insertAtStart(&single_list, 4);
    linkedlist_insertAtStart(&single_list, 5);

    linkedlist_print(single_list);
    printf("The size of the list is %i\n", linkedlist_getLength(single_list, NULL));

    linkedlist_insertAtEnd(&single_list, 7);
    linkedlist_insertAtEnd(&single_list, 1);
    linkedlist_insertAtEnd(&single_list, 3);

    linkedlist_print(single_list);
    printf("The size of the list is %i\n", linkedlist_getLength(single_list, NULL));

    linkedlist_insertAt(single_list, 9, 3);
    linkedlist_insertAt(single_list, 40, 1); // should have no effect
    linkedlist_insertAt(single_list, 40, 2);

    linkedlist_print(single_list);
    printf("The size of the list is %i\n", linkedlist_getLength(single_list, NULL));

    linkedlist_deleteAtStart(&single_list);
    linkedlist_deleteAtStart(&single_list);
    linkedlist_deleteAtStart(&single_list);

    linkedlist_print(single_list);
    printf("The size of the list is %i\n", linkedlist_getLength(single_list, NULL));

    linkedlist_deleteAt(single_list, 2);
    linkedlist_deleteAt(single_list, 2);
    linkedlist_deleteAt(single_list, 6); // should have no effect

    linkedlist_print(single_list);
    printf("The size of the list is %i\n", linkedlist_getLength(single_list, NULL));

    linkedlist_deleteList(&single_list);   
    
    return 0;
}
