
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT_NUM 8888

// utilerias
struct UserData{
    char name[20];
    
    struct address{
        char street[20];
        int number;
        char city[20];
    }addrss;
};

int initialization();
int connection(int socket_desc);
int close(int sock);

// servicio(s)
void newUser(struct UserData * p);




