#include "Diccionariodedatos.h"

Diccionariodedatos::Diccionariodedatos(){
    NumAtributos = 0;
    tamBloque = 0;
    dirActiva = -1;
    int op = leerEntero();
    menuPrincipal(op);
}
//lee entero
int leerEntero(){
    int num;
    char buffer[MAX];

    while(1){
        if(fgets(buffer, sizeof(buffer), stdin)){
            if(sscanf(buffer, "%d", &num) == 1){
                return num;
            }
        }
        printf("Entrada invalida, ingresa un numero:\n");
    }
}

void Diccionariodedatos::menuPrincipal(int op){
    do{
        printf("\n-----Menu Principal-----\n");
        printf("1.-Nuevo diccionario\n");
        printf("2.-Abrir diccionario\n");
        printf("3.-Salir\n");

        op = leerEntero();

        switch(op){
            case 1:
                if(nuevoDiccionario()) menuEntidades(op);
                break;
            case 2:
                if(abrirDiccionario()) menuEntidades(op);
                break;
        }
    }while(op != 3);
}

void Diccionariodedatos::menuEntidades(int op){
    do{
        printf("\n-----MENU ENTIDADES-----\n");
        printf("1.-Nueva Entidad\n");
        printf("2.-Consulta Entidad\n");
        printf("3.-Elimina Entidad\n");
        printf("4.-Modifica Entidad\n");
        printf("5.-Menu atributos\n");
        printf("6.-Menu de Datos\n");
        printf("7.-Regresar\n");

        op = leerEntero();

        switch(op){
            case 1: creaEntidad(); break;
            case 2: consultaEntidades(); break;
            case 3: eliminaEntidad(); break;
            case 4: modificaEntidad(); break;
            case 5: menuAtributos(op); break;
            case 6: menuDatos(op); break;
        }
    }while(op != 7);
}

void Diccionariodedatos::menuAtributos(int op){
    do{
        printf("\n-----Menu de Atributos-----\n");
        printf("1.-Nuevo atributo\n");
        printf("2.-Consulta atributo\n");
        printf("3.-Elimina atributo\n");
        printf("4.-Modifica atributo\n");
        printf("5.-Regresar\n");

        op = leerEntero();

        switch(op){
            case 1: creaAtributo(); break;
            case 2: consultaAtributos(); break;
            case 3: eliminaAtributos(); break;
            case 4: modificaAtributo(); break;
        }
    }while(op != 5);
}

void Diccionariodedatos::menuDatos(int op){
    do{
        printf("\n-----Menu de Datos-----\n");
        printf("1.-Nuevo Registro\n");
        printf("2.-Consultar Registro\n");
        printf("3.-Eliminar Registro\n");
        printf("4.-Modificar Registro\n");
        printf("5.-Regresar\n");

        op = leerEntero();

        switch(op){
            case 1: creaRegistro(); break;
            case 2: consultaRegistro(); break;
            case 3: eliminaRegistro(); break;
            case 4: modificaRegistro(); break;
        }
    }while(op != 5);
}

void Diccionariodedatos::creaEntidad(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::consultaEntidades(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::eliminaEntidad(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::modificaEntidad(){ printf("\nTrabajando...\n"); }

void Diccionariodedatos::creaAtributo(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::consultaAtributos(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::eliminaAtributos(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::modificaAtributo(){ printf("\nTrabajando...\n"); }

void Diccionariodedatos::creaRegistro(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::consultaRegistro(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::eliminaRegistro(){ printf("\nTrabajando...\n"); }
void Diccionariodedatos::modificaRegistro(){ printf("\nTrabajando...\n"); }

int Diccionariodedatos::nuevoDiccionario(){
    char nombre[MAX]
    long cab = -1;

    printf("\nNombre del archivo: ");
    scanf("%[^\n]",nombre);
    getchar();

    ifstream temp(nombre, ios::binary);
    if(temp.is_open()){
        printf("\nEl archivo ya existe\n");
        temp.close();
        return 0;
    }

    ofstream nuevo(nombre, ios::binary);
    if(!nuevo) return 0;

    nuevo.write((char*)&cab, sizeof(long));
    nuevo.close();

    arch.open(nombre, ios::in | ios::out | ios::binary);

    if(!arch.is_open()) return 0;

    printf("\nArchivo creado correctamente\n");
    return 1;

}

int CDiccionario::abrirDiccionario(){
    char nombre[50];

    printf("\nNombre del archivo: ");
    scanf("%49s", nombre);
    getchar();

    arch.open(nombre, ios::in | ios::out | ios::binary);

    if(!arch.is_open()){
        printf("\nNo se pudo abrir el archivo\n");
        return 0;
    }

    printf("\nArchivo abierto correctamente\n");
    return 1;
}

void CDiccionario::insertaEntidad(Entidad nuevo, long dir){}
void CDiccionario::escribeCabeceraEntidades(long cab){}
void CDiccionario::reescribeEntidad(Entidad ent, long dir){}
Entidad CDiccionario::leeEntidad(long dir){ return activa; }
long CDiccionario::getCabEntidades(){ return -1; }
Entidad CDiccionario::capturaEntidad(){ return activa; }