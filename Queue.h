#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
typedef struct Node1{
    // this structure to define a element in data structure (linked list, Queue, Stack)
    void *data; //
    struct Node1 * next;

}Node1;

typedef struct Queue{
    Node1 *head;
    Node1 *queu;
}Queue;



// create Nodes of data structure
Node1 *create_node1(void *data);

// create and initialise the Queue
Queue *create_queue();

//******************************Queue functions**************************************


void *pull_queue(Queue *q);
int push_queue(Queue *a, void *data);
int queue_empty(Queue *q);

#endif // QUEUE_H_INCLUDED
