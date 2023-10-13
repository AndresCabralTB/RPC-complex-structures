
#include "server.h"

struct UserData * recv_message(int client_sock);
void send_result(int client_sock, struct UserData * p);

struct UserData p;

int main(int argc, char *argv[])
{
    int socket_desc = initialization();
    
    while(1) {
        
        int client_sock = connection(socket_desc);
        struct UserData * p = recv_message(client_sock);
        newUser(p);
        send_result(client_sock, p); // adaptador del resultado
    }
    
    close(socket_desc);
    return 0;
}

struct UserData * recv_message(int client_sock)
{
    struct UserData * p1 =& p;
    int read_size, length;
    
    // receive the message length from client
    read_size = recv(client_sock, &p.name, sizeof(p.name), 0);
    read_size = recv(client_sock, &p.addrss.street, sizeof(p.addrss.street), 0);
    read_size = recv(client_sock, &p.addrss.city, sizeof(p.addrss.city), 0);
    read_size = recv(client_sock, &p.addrss.number, sizeof(int), 0);

    if(read_size == 0) {
        puts("Client disconnected");
        fflush(stdout);
    }
    else if(read_size == -1) {
        perror("recv failed");
    }
    
    return p1;
}

void send_result(int client_sock, struct UserData * p)
{
    //Send the results through the socket
    send(client_sock, &p->name, sizeof(p->name), 0);
    send(client_sock, &p->addrss.street, sizeof(p->addrss.street), 0);
    send(client_sock, &p->addrss.city, sizeof(p->addrss.city), 0);
    send(client_sock, &p->addrss.number, sizeof(int), 0);

    // send result to the client: LITTLE ENDIAN
    if(send(client_sock, &p->addrss.number, sizeof(int), 0) < 0) {
        puts("Send failed");
        exit(1);
    }
}
