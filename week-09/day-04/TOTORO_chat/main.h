#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

char key;

typedef struct user {
    char name[256];
    unsigned long ip_address;
    unsigned short port_number;
    int discovery_port_number;
}user_t;

user_t user_array[50];
int user_index;

#endif // MAIN_H_INCLUDED
