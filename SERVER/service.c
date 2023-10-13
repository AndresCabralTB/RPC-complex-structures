
// Almacena mensajes en "mensajes.txt"

/* service.c: Código de la función remota */

#include <stdio.h>
#include <string.h>
#include "server.h"

// Transferir estructura y almacenar en un archivo .txt

void newUser(struct UserData * p){
    
    FILE * fp = fopen( "Userdata.txt", "a" );
    fprintf( fp, "Name: %s\n", p->name );
    fprintf( fp, "Street: %s\n", p-> addrss.street );
    fprintf( fp, "Number: %i\n", p->addrss.number );
    fprintf( fp, "City: %s\n", p->addrss.city );
    
    fclose( fp );   
}
