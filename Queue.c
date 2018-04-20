#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Node1 *create_node1(void *data){
    Node1 *p = (Node1*)malloc(sizeof(Node1));
    p->data = data;
    p->next = NULL;
    return p;

}


Queue *create_queue(){

    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->head = NULL;
    q->queu = NULL;
    return q;
}



int push_queue(Queue *q, void *data){
    Node1 *n = create_node1(data);
    if (n == NULL)
        return 1;
    else{
    if (q->head == NULL && q->queu == NULL){
        q->head = n;
        q->queu = n;
    }else{
        q->queu->next = n;
        q->queu = n;

    }

    return 0;
    }

}


void *pull_queue(Queue *q){
    Node1 *h = q->head;
    void *data = NULL;

    if (h == NULL){
        return NULL;
    }
    if(h == q->queu){
            data = h->data;
            q->head = NULL;
            q->queu = NULL;
            free(h);
            return data;
    }else{
            data = h->data;
            q->head = q->head->next;
            free(h);
        }


    return data;
}


int queue_empty(Queue *q){

    if (q->head == NULL)
        return 0;
    else
        return 1;
}
