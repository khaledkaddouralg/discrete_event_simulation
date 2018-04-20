#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Linked_list.h"
#include "Structuers.h"

#define ARRIVAL_TIME 4
#define SERVICE_TIME 8

#define ARRIVAL 1
#define START_SERVICE 2
#define DEPARTURE 3

//declaration des variable

//variable of the system
    int t_now;
    int server;
    Queue *queue;
    LinkedListe *list_events;

// variable of the statistiques

    static double mean_res_time;
    static double mean_wai_time;
    static int client_served;
// help variable

Client *c;
Event *e;
static int ID = 0;


void initialisation(){
    //variable of the system
    t_now = 0;
    server = 0;
    queue = create_queue();
    list_events = create_linked_liste();

    // variable of the statistiques
    mean_res_time = 0.0;
    mean_wai_time = 0.0;
    client_served = 0;

    // workload
    Event *e = create_event(ARRIVAL, t_now);
    add_event_sorted(list_events, e);


}

void p_arrivale(){

    Client *client = create_client(ID++, t_now, 0, SERVICE_TIME);
    push_queue(queue, client);

    if(server == 0){
        Event * e = create_event(START_SERVICE, t_now);
        add_event_sorted(list_events, e);
    }
     Event *e = create_event(ARRIVAL, t_now + ARRIVAL_TIME);
     add_event_sorted(list_events, e);
}


void p_start_service(){


    server = 1;
    c = pull_queue(queue);

    c->start_servic = t_now;

    Event *e = create_event(DEPARTURE, t_now + c->service_time);
    add_event_sorted(list_events, e);
}


void p_departuer(){

    server = 0;
    mean_res_time += (t_now - c->arrival_time);
    mean_wai_time += (c->start_servic - c->arrival_time);
    client_served += 1;

    if (queue_empty(queue) != 0){

    Event *e =create_event(START_SERVICE, t_now);
    add_event_sorted(list_events, e);


    }


}


void statistic(){
    printf("\n============================statistics====================================\n");
    printf("client served is : %d\n", client_served);
    printf("time now is : %d\n", t_now);
    printf("Avrage of response time is : %f \n", mean_res_time / client_served);
    printf("Avrage of wiating time is : %f \n", mean_wai_time / client_served);
    printf("debit is : %f \n", (float)client_served / t_now);


}

int main()
{
    initialisation();
    while(client_served < 1000){
    Event *e = remove_head(list_events);
    t_now = e->time;
    switch(e->type){
        case ARRIVAL:
            p_arrivale();
            break;
        case START_SERVICE:
            p_start_service();
            break;
        case DEPARTURE:
            p_departuer();
            break;
    }

    }

    statistic();

    return 0;
}
