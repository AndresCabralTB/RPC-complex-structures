
// store messages using a service

#include "client.h"

int sock;
char * host;

int main( int argc, char * argv[] )
{
    struct UserData * p;
    struct UserData p2;
   
    if( argc != 6 ) {
        fprintf(stderr, "Uso: %s <host> <Name> <Street> <Number> <City>\n", argv[0]);
        exit( 1 );
    }
    host = argv[1];
    //Almacenar el nombre
    strncpy(p2.name, argv[2], sizeof(p2.name) - 1);
    p2.name[sizeof(p2.name) - 1] = '\0';
    //Almacenar la calle
    strncpy(p2.addrss.street, argv[3], sizeof(p2.addrss.street) - 1);
    p2.addrss.street[sizeof(p2.addrss.street) - 1] = '\0';
    //Almacenar el número
    p2.addrss.number = atoi(argv[4]);
    //Almacenar la ciudad
    strncpy(p2.addrss.city, argv[5], sizeof(p2.addrss.city) - 1);
    p2.addrss.city[sizeof(p2.addrss.city) - 1] = '\0';

    sock = connection();            // conección con el servidor
    p=&p2;
    newUser(p); //Enviar información
    
    //printf("Resultado recibido por el cliente: %d\n", result);
    printf("El mensaje fue almacenado\n");
    printf("Name: %s\n", p2.name);
    printf("Street: %s\n", p2.addrss.street);
    printf("Number: %i\n", p2.addrss.number);
    printf("City: %s\n", p2.addrss.city);

    close(sock);                    // cerrar la conección
    return 0;
}


