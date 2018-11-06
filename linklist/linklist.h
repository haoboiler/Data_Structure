/*reference from https://github.com/clibs/list/*/
#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

typedef struct list_node{
    struct list_node * prev; //pointer to the previous node
    struct list_node * next; //pointer to the next node
    void * val; // value
}list_node;

typedef struct list_t{
    struct list_node * head; //head of the list ,maybe null
    struct list_node * tail; //tail of the list.
    void(*free)(void *val); // function to free the node's val

}list_t;

list_t * list_new(); //creat a new list

void list_destory(); //distory the list
/*
list_node * list_rpop(list_t * alist); //pop the last node of the list

list_node * list_lpop(list_t * alist); //pop the first not null node of the list

// push a node at the left of the list,return the node or null if failure
list_node * list_lpush(list_t * alist, list_node * anode); 
//right push
list_node * list_rpush(list_t * alist, list_node * anode);

//find the node with given value in the list
list_node * list_find(list_t* alist, void * val);

//remove a node and free it.
void * list_remove(list_t * alist, list_node *anode);
*/
#endif //LIST_H endif