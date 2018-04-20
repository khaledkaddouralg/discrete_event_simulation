#ifndef STRUCTUERS_H_INCLUDED
#define STRUCTUERS_H_INCLUDED
typedef struct Event{
    int type;
    int time;

}Event;

typedef struct Client{
    int ID;
    int arrival_time;
    int start_servic;
    int service_time;

}Client;

Event *create_event(int type, int time);
Client *create_client(int id, int arrival_time, int start_servic, int service_time);

#endif // STRUCTUERS_H_INCLUDED
