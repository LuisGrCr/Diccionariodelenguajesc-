#include "Diccionariodedatos.h"
#include <cstdio>
#include <cstring>

// Archivo global
FILE *arch = NULL;

// Leer entero seguro
int leerEntero(){
    int num;
    char buffer[100];

    while (true){
        if (fgets(buffer, sizeof(buffer), stdin)){
            if (sscanf(buffer, "%d", &num) == 1){
                return num;
            }
        }
        cout << "\nEntrada invalida, ingresa un numero:\n";
    }
}

// ENTIDADES
void creaEntidad(){
    cout << "Trabajando...\n";
}

void consultaEntidades(){
    cout << "\nTrabajando...\n";
}

void eliminaEntidad(){
    cout << "\nTrabajando...\n";
}

void modificaEntidadM(){
    cout << "\nTrabajando...\n";
}

// ATRIBUTOS
void creaAtributo(){
    cout << "\nTrabajando...\n";
}

void consultaAtributos(){
    cout << "\nTrabajando...\n";
}

void eliminaAtributos(){
    cout << "\nTrabajando...\n";
}

void modificaAtributo(){
    cout << "\nTrabajando...\n";
}

// REGISTROS
void creaRegistro(){
    cout << "\nTrabajando...\n";
}

void consultaRegistro(){
    cout << "\nTrabajando...\n";
}

void eliminaRegistro(){
    cout << "\nTrabajando...\n";
}

void modificaRegistro(){
    cout << "\nTrabajando...\n";
}

// Crear diccionario
int nuevoDiccionario(){
    char nombre[50];
    long cab = -1;
    FILE *temp;

    cout << "\nNombre del archivo: ";
    cin >> nombre;

    temp = fopen(nombre, "rb");

    if(temp != NULL){
        cout << "\nEl archivo ya existe\n";
        fclose(temp);
        return 0;
    }

    FILE *nuevo = fopen(nombre, "wb");
    if(nuevo == NULL){
        cout << "\nError al crear archivo\n";
        return 0;
    }

    fwrite(&cab, sizeof(long), 1, nuevo);
    fclose(nuevo);

    arch = fopen(nombre, "rb+");

    cout << "\nArchivo creado correctamente\n";
    return 1;
}

// Abrir diccionario
int abrirDiccionario(){
    char nombre[50];

    cout << "\nNombre del archivo: ";
    cin >> nombre;

    arch = fopen(nombre, "rb+");

    if(arch == NULL){
        cout << "\nNo se pudo abrir el archivo\n";
        return 0;
    }

    cout << "\nArchivo abierto correctamente\n";
    return 1;
}