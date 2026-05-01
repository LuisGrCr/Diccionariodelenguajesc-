#include "Diccionariodedatos.h"

Diccionariodedatos::Diccionariodedatos()
{
    archivo = NULL;
    NumAtributos = 0;
    tamBloque = 0;
    int op = leerEntero;
    menuPrincipal(op);
}

// Leer entero seguro
int leerEntero(){
    int num;
    char buffer[100];

    while (true){
        if (cin.getline(buffer, sizeof(buffer))){
            if (sscanf(buffer, "%d", &num) == 1){
                return num;
            }
        }
        printf("\nEntrada invalida, ingresa un numero:\n");
    }
}

void Diccionariodedatos::menuPrincipal(int op){

}
