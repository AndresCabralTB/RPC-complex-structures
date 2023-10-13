
#include "client.h"

extern int sock;

void newUser(struct UserData * p){
    int read_size, length;
    
    send(sock, &p->name, sizeof(p->name), 0);
    send(sock, &p->addrss.street, sizeof(p->addrss.street), 0);
    //send(sock, &p->addrss.number, sizeof(int), 0);
    send(sock, &p->addrss.city, sizeof(p->addrss.city), 0);

    if(send(sock, &p->addrss.number, sizeof(int), 0) < 0) {
        puts("Send fails(client stub)");
        exit(1);
    }
    
    read_size=recv(sock, &p->name, sizeof(p->name), 0);
    read_size=recv(sock, &p->addrss.street, sizeof(p->addrss.street), 0);
    read_size=recv(sock, &p->addrss.city, sizeof(p->addrss.city), 0);
    read_size=recv(sock, &p->addrss.number, sizeof(int), 0);

    
    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1) {
        perror("recv failed");
    }
}


