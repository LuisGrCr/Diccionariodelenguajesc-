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

void Diccionariodedatos::creaEntidad(){ 
    printf("\nTrabajando...\n");
 }
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

void Diccionariodedatos::nuevoDiccionario()
{
    char nombre[50];
    printf("\nNombre del nuevo diccionario: ");
    scanf("%s", nombre);

    //Verificamos que no exista abriendolo en modo lectura
    archivo = fopen(nombre, "rb");
    if(archivo)
    {
        printf("\nEl archivo ya existe\n");
        fclose(archivo);
    }else{

        printf("\nEl archivo NO existe, creando...");
        archivo = fopen(nombre, "wb+");
        if(!archivo)
        {
            printf("\nError al crear el archivo");
            return;
        }
        printf("\nArchivo %s creado correctamente\n", nombre);
        escribeCabEntidades(-1);
        fclose(archivo);
    }
}
int Diccionariodedatos::abrirDiccionario(){
    char nombre[MAX];

    printf("\nNombre del archivo: ");
    scanf("%98[^\n]", nombre);
    getchar();

    archivo = fopen(nombre, "rb+");

    if(archivo == NULL){
        printf("\nNo se pudo abrir el archivo\n");
        return 0;
    }

    printf("\nArchivo abierto correctamente\n");
    return 1;
}

void Diccionariodedatos::insertarEntidad(ENTIDAD nuevo, long dir){
    printf("\n----------Trabajando----------\n");
}
void Diccionariodedatos::escribeCabEntidades(long cab){}
void Diccionariodedatos::reescribeEntidad(ENTIDAD ent, long dir){}
ENTIDAD Diccionariodedatos::leeEntidad(long dir){ return activa; }
long Diccionariodedatos::getCabEntidades(){ return -1; }
ENTIDAD Diccionariodedatos::capturaEntidad(){ return activa; }