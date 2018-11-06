#include "linklist.h"

/* creat a new list and return it, if failure, return NULL */
list_t * list_new(){
    list_t * alist;
    alist = malloc(sizeof(list_t));
    //if create failure, return NULL
    if (alist == NULL) return NULL; 

    alist->head = NULL;
    alist->tail = NULL;
    alist->free = NULL;
    return alist;
}

/*free the given list*/
void list_destroy(list_t * alist){
    list_node * next;
    list_node * curr;
    if (alist->head != NULL){
        for(curr = alist->head;curr->next!=NULL;curr = next){
            next = curr->next;
            if (alist->free) alist->free(curr->val);
            free(curr);
        }
        free (curr);
    }
    free(alist);
}

/*right pop*/
list_node * list_rpop(list_t * alist){
    if (!alist || alist->tail == NULL) return NULL;
    list_node * anode = alist->tail;
    // if have more than one node, set the previous node as tail
    if (anode != alist->head){
        anode->prev->next = NULL;
        alist->tail = anode->prev;
    }
    //if only one node in the list
    else{
        alist->head = alist->tail = NULL;
    }

    anode->next = anode->prev = NULL;
    return anode;
}

list_node *list_lpop(list_t * alist){
    if (!alist || alist->head == NULL ) return NULL;
    list_node * anode = alist->head;
    // if have more than one node, set the previous node as tail
    if (anode != alist->tail){
        anode->next->prev = NULL;
        alist->head = anode->next;
    }
    //if only one node in the list
    else{
        alist->head = alist->tail = NULL;
    }

    anode->next = anode->prev = NULL;
    return anode;    
}

list_node * list_lpush(list_t * alist, list_node * anode){
    if (!anode || !alist) return NULL;;
    if(alist->head == alist->tail && alist->head ==NULL){
        alist->head = alist->tail = anode;
        anode->prev = anode->next = NULL;
    }
    else{
        anode->next = alist->head;
        anode->prev = NULL;
        alist->head->prev = anode;
        alist->head = anode;
    }
    return anode;
}
list_node * list_rpush(list_t * alist, list_node * anode){
    if (!anode || !alist) return NULL;;
    
    if(alist->head == alist->tail && alist->head ==NULL){
        alist->head = alist->tail = anode;
        anode->prev = anode->next = NULL;
    }
    else{
        anode->prev = alist->tail;
        anode->next = NULL;
        alist->tail->next = anode;
        alist->tail = anode;
    }
    return anode;
}

void * list_remove(list_t * alist, list_node *anode){
    anode->prev
        ? (anode->prev->next = anode->next)
        : (alist->head = anode->next);

    anode->next
        ? (anode->next->prev = anode->prev)
        : (alist->tail = anode->prev);

    if (alist->free) alist->free(anode->val);
    free(anode);
  
}

int main(){
    list_t * alist = list_new();
    
    list_node * anode = malloc(sizeof(list_node));
    list_lpush(alist,anode);
    printf("%d\n",alist->head->val);
    list_node * bnode = list_lpop(alist);
    printf("%d\n",bnode->val);
    list_destroy(alist);
    return 0;
}
