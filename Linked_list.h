#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

typedef struct Node{
    // this structure to define a element in data structure (linked list, Queue, Stack)
    void *data; //
    struct Node * next;

}Node;

typedef struct LinkedListe{

    Node *head;

}LinkedListe;




// =================function prototype========================

// create Nodes of data structure
Node *create_node(void *data);

// create and initialise the linked list
LinkedListe *create_linked_liste();

int add_item(LinkedListe *l, void *data);
int append(LinkedListe *l, void *data);
void *get_item_data(LinkedListe *l, int index);
void *remove_head(LinkedListe *l);
void *remove_index(LinkedListe *l, int index);
int list_is_empty(LinkedListe *l);
int add_event_sorted(LinkedListe *l, void *data);


#endif // LINKED_LIST_H_INCLUDED
