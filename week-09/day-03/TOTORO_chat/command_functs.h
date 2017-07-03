#ifndef COMMAND_FUNCTS_H_INCLUDED
#define COMMAND_FUNCTS_H_INCLUDED
typedef struct user {
    char name[256];
    const char *ip_address;
    int port_number;
    int discovery_port_number;
}user_t;

user_t user_array[50];
int user_array_size = sizeof(user_array) / sizeof(user_array[0]);
int user_index;

void wsa_init();
void startup_com_list();
void print_command_list();
void print_user_list();


#endif // COMMAND_FUNCTS_H_INCLUDED


