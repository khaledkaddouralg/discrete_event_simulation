#include <stdio.h>
#include <stdlib.h>
#include "Structuers.h"

Event *create_event(int type, int time){

        Event *e = (Event*)malloc(sizeof(Event));
        e->type = type;
        e->time = time;
        return e;
}

Client *create_client(int id, int arrival_time, int start_servic, int service_time){

    Client *c = (Client*)malloc(sizeof(Client));
    c->arrival_time = arrival_time;
    c->ID = id;
    c->start_servic = start_servic;
    c->service_time = service_time;
    return c;

}
