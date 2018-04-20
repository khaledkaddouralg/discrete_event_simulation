#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"
#include "Structuers.h"

Node *create_node(void *data){
    Node *p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;

}


LinkedListe *create_linked_liste(){

    LinkedListe *list = (LinkedListe*) malloc(sizeof(LinkedListe));
    list->head = NULL;
    return list;

}


int add_item(LinkedListe *l, void *data){
    // this function add always an item to the head of the linked list
    // this function return 1 if adding item failed
    //this function return 0 if adding item successful
    Node *n = create_node(data);
    if(n == NULL)
        return 1;
    else
    {
    n->next = l->head;
    l->head = n;
    return 0;
    }
}


int append(LinkedListe *l, void *data){
    // this function add always an item to the end of the linked liste
    // this function return 1 if adding item failed
    //this function return 0 if adding item successful
    Node *h = l->head;
    Node *n = create_node(data);
    if (n == NULL){
        return 1;
    }else{
        if (h == NULL){
            //the list is empty for this adding the first item is different to other items
            n->next = l->head;
            l->head = n;
        }else{
            //add other items
            while(h->next != NULL){
                // to find the last item of the linked list
                h = h->next;
            }
            h->next = n;

        }
        return 0;
    }
}

void *get_item_data(LinkedListe *l, int index){
    //this function return data in the item at index
    //if the index in the range of linked list return data
    //if the index out the rang of linked list return NULL

    Node *h = l->head;
    int count = 0;
    void *data = NULL;
    while(h != NULL && count < index){


        count ++;
        h = h->next;
    }
    if( h != NULL){
        // if the index in the range of the linked list
        data = h->data;
    }
    return data;
}

void *remove_head(LinkedListe *l){
    // this function remove the head of the list and
    // return the data if the list is not empty
    // return NULL if list empty

    void *data = NULL;
    Node *h = l->head;
    if (h != NULL){
        data = h->data;
        l->head = h->next;
        free(h);
    }
    return data;

}

void *remove_index(LinkedListe *l, int index){
    //this function remove the item at index
    // return the data if the index in the range
    // return NULL if the index out the range
    void *data = NULL;
    Node *h = l->head;
    int count = 0;
    Node *prev;

    if(index == 0){
        data = remove_head(l);
    }else{
        while(h != NULL && count < index ){
            prev = h;
            h = h->next;
            count ++;
        }
        if (h != NULL){
            data = h->data;
            prev->next = h->next;
            free(h);
        }
    }
    return data;
}

int list_is_empty(LinkedListe *l){
    //this function to test if list is empty
    //return 0 if empty
    //return 1 if not empty

    int test = 0;
    if (l->head != NULL)
        test = 1;
    return test;
}

int add_event_sorted(LinkedListe *l, void *data){
    // this function add item to linked list and sorted it
    //return 0 if add  item
    // return 1 else fialed to add item

    Node *n = create_node(data);
    if (n == NULL){
        return 1;
    }else{
        //check if the list is empty
        if(l->head == NULL){
            l->head = n;
        }else{
             if(((Event*)data)->time <= ((Event*)l->head->data)->time){
                    n->next = l->head;
                    l->head = n;
             }else{
                Node *current, *prev;
                current = l->head;
                while(current != NULL && ((Event*)current->data)->time <= ((Event*)data)->time){
                    prev = current;
                    current = current->next;
                }
                n->next = prev->next;
                prev->next = n;
             }
        }

        return 0;
    }
}

