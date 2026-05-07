#include "Diccionariodedatos.h"
//MANUEL MARTINEZ GRIMALDO
//Granja Carranco Luis Adrian
Diccionariodedatos::Diccionariodedatos(){
    NumAtributos = 0;
    tamBloque = 0;
    dirActiva = -1;
    int op;
    menuPrincipal(&op);
}
//lee entero
int Diccionariodedatos::leerEntero()
{
    int num;
    char buffer[MAX];

    while(1)
    {
        fgets(buffer, sizeof(buffer), stdin);

        // Validar que sea entero
        if(sscanf(buffer, "%d", &num) == 1)
        {
            return num;
        }

        printf("Entrada invalida. Ingresa un numero: ");
    }
}


void Diccionariodedatos::menuPrincipal(int *op){
    do{
        printf("\n-----Menu Principal-----\n");
        printf("1.-Nuevo diccionario\n");
        printf("2.-Abrir diccionario\n");
        printf("3.-Salir\n");

        *op = leerEntero();

        switch(*op){
            case 1:
                if(nuevoDiccionario()){
                    menuEntidades(op);
                    //cierra archivo al salir del menu
                    fclose(archivo);
                    archivo = NULL;
                } 
                break;
            case 2:
                if(abrirDiccionario()){
                    menuEntidades(op);
                    //cierra archivo al salir del menu
                    fclose(archivo);
                    archivo = NULL;
                }
                break;
        }
    }while(*op != 3);
}


int Diccionariodedatos::nuevoDiccionario()
{
    char nombre[50];
    printf("\nNombre del nuevo diccionario: ");
    scanf("%s", nombre);
    getchar();

    archivo = fopen(nombre, "rb");
    if(archivo)
    {
        printf("\nEl archivo ya existe\n");
        fclose(archivo);
        return 0;
    }
    archivo = fopen(nombre, "wb+");
    if(!archivo)
    {
        printf("\nError al crear el archivo");
        return 0;
    }
    printf("\nArchivo %s creado correctamente\n", nombre);
    escribeCabEntidades(-1);
    return 1;
}

int Diccionariodedatos::abrirDiccionario(){

    char nombre[MAX];

    printf("\nNombre del archivo: ");
    scanf(" %[^\n]", nombre);
    getchar();

    archivo = fopen(nombre, "rb+");

    if(archivo == NULL){
        printf("\nNo se pudo abrir el archivo\n");
        return 0;
    }

    printf("\nArchivo abierto correctamente\n");
    return 1;
}


void Diccionariodedatos::menuEntidades(int *op){
    do{
        printf("\n-----MENU ENTIDADES-----\n");
        printf("1.-Nueva Entidad\n");
        printf("2.-Consulta Entidad\n");
        printf("3.-Elimina Entidad\n");
        printf("4.-Modifica Entidad\n");
        printf("5.-Menu atributos\n");
        printf("6.-Menu de Datos\n");
        printf("7.-Regresar\n");

        *op = leerEntero();

        switch(*op){
            case 1: 
            printf("\nIngrese entidad\n");
            altaEntidad(); break;
            
            case 2: consultaEntidades(); break;
            case 3: eliminaEntidad(); break;
            case 4: modificaEntidad(); break;
            case 5: menuAtributos(*op); break;
            case 6: menuDatos(op); break;
        }
    }while(*op != 7);
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
void Diccionariodedatos::menuDatos(int *op){
    do{
        printf("\n-----Menu de Datos-----\n");
        printf("1.-Nuevo Registro\n");
        printf("2.-Consultar Registro\n");
        printf("3.-Eliminar Registro\n");
        printf("4.-Modificar Registro\n");
        printf("5.-Regresar\n");

        *op = leerEntero();

        switch(*op){
            case 1: creaRegistro(); break;
            case 2: consultaRegistro(); break;
            case 3: eliminaRegistro(); break;
            case 4: modificaRegistro(); break;
        }
    }while(*op != 5);
}

//--Funciones de Entidades--
void Diccionariodedatos::altaEntidad(){
    ENTIDAD nueva;
    long dir;
    nueva = capturaEntidad();

if(buscaEntidad(nueva) == -1){
    dir =escribeEntidad(nueva);
    insertarEntidad(nueva, dir);;
    }else{
        printf("\nLa entidad ya existe\n");
    }
}
ENTIDAD Diccionariodedatos::capturaEntidad(){
    ENTIDAD ent;
    printf("\nNombre de la entidad: ");
    scanf(" %[^\n]", ent.nombre);

    ent.atr = -1;
    ent.sig = -1;
    ent.data= -1;
    return ent;
}
void Diccionariodedatos::escribeCabEntidades(long cab)
{ 
    fseek(archivo, 0, SEEK_SET);
    fwrite(&cab, sizeof(long), 1, archivo);
}
void Diccionariodedatos::consultaEntidades()
{ 
    ENTIDAD nuevo;
    long cab = getCabEntidades();
    while (cab != -1)
    {
        nuevo = leeEntidad(cab);
        printf("%s,-> %ld, -> %ld,-> %ld\n", nuevo.nombre, nuevo.atr, nuevo.sig, nuevo.data);
        cab = nuevo.sig;
    }
    
}
long Diccionariodedatos::eliminaEntidad(char nombre[MAX])
{
    long cab = getCabEntidades();

    //  Caso 1: lista vacía
    if(cab == -1){
        return -1;
    }

    ENTIDAD actual = leeEntidad(cab);
    ENTIDAD anterior;
    long dirActual = cab;
    long dirAnterior = -1;

    //Caso 2: eliminar el primero
    if(strcmp(actual.nombre, nombre) == 0){
        escribeCabEntidades(actual.sig);
        return cab;
    }

    //Buscar en la lista
    while(dirActual != -1 && strcmp(actual.nombre, nombre) != 0){
        dirAnterior = dirActual;
        anterior = actual;

        dirActual = actual.sig;
        if(dirActual != -1){
            actual = leeEntidad(dirActual);
        }
    }

    //Caso 3: encontrado
    if(dirActual != -1){
        anterior.sig = actual.sig;
        reescribeEntidad(anterior, dirAnterior);
        return dirActual;
    }

    //Caso 4: no encontrado
    return -1;
}
void Diccionariodedatos::eliminaEntidad(){
    char nombre[MAX];

    printf("\nNombre de la entidad a eliminar: ");
    scanf(" %[^\n]", nombre);

    long res = eliminaEntidad(nombre);

    if(res == -1){
        printf("\nNo se encontro la entidad\n");
    }else{
        printf("\nEntidad eliminada correctamente\n");
    }
}
void Diccionariodedatos::modificaEntidad()
{ 
    char nombre[MAX];
    long dir;
    ENTIDAD nueva, original;

    printf("\nNombre de la entidad a modificar: ");
    scanf(" %[^\n]", nombre);

    //Crear entidad auxiliar para buscar
    strcpy(original.nombre, nombre);

    dir = buscaEntidad(original);

    //Si no existe
    if(dir == -1){
        printf("\nNo se encontro la entidad\n");
        return;
    }

    //Capturar nuevos datos
    nueva = capturaEntidad();

    //Verificar duplicado (si cambió el nombre)
    ENTIDAD aux;
    strcpy(aux.nombre, nueva.nombre);

    if(strcmp(nombre, nueva.nombre) != 0 && buscaEntidad(aux) != -1){
        printf("\nYa existe una entidad con ese nombre\n");
        return;
    }

    //Eliminar anterior
    eliminaEntidad(nombre);

    //Escribir nueva en misma posición
    reescribeEntidad(nueva, dir);

    //Reinsertar ordenadamente
    insertarEntidad(nueva, dir);

    printf("\nEntidad modificada correctamente\n");
}
long Diccionariodedatos::getCabEntidades(){
    long dir;
    fseek(archivo, 0, SEEK_SET);
    fread(&dir, sizeof(long), 1, archivo);
    return dir;
}
long Diccionariodedatos::buscaEntidad(ENTIDAD ent){
    long cab = getCabEntidades();
    ENTIDAD actual;
    while(cab != -1){
        actual = leeEntidad(cab);
        if(strcmp(ent.nombre, actual.nombre) == 0){
            return cab;
        }
        cab = actual.sig;
    }
    return -1;
    printf("DEBUG: cab = %ld\n", cab);
}
long Diccionariodedatos::escribeEntidad(ENTIDAD ent){
    long dir;
    fseek(archivo, 0, SEEK_END);
    dir = ftell(archivo);
    fwrite(&ent, sizeof(ENTIDAD), 1, archivo);
    return dir;
}
ENTIDAD Diccionariodedatos::leeEntidad(long dir){
    ENTIDAD nuevo;
    fseek(archivo, dir, SEEK_SET);
    fread(&nuevo, sizeof(ENTIDAD), 1, archivo);
    return nuevo;
}
void Diccionariodedatos::reescribeEntidad(ENTIDAD ent, long dir){
    fseek(archivo, dir, SEEK_SET);
    fwrite(&ent, sizeof(ENTIDAD), 1, archivo);
}
void Diccionariodedatos::insertarEntidad(ENTIDAD nuevo, long dir){
    long cab = getCabEntidades();
    ENTIDAD actual, anterior;
    long dirActual = cab;
    long dirAnterior = -1;

    // Caso 1: lista vacía
    if(cab == -1){
        nuevo.sig = -1;
        reescribeEntidad(nuevo, dir);
        escribeCabEntidades(dir);
        return;
    }

    actual = leeEntidad(dirActual);

    // Caso 2: insertar al inicio
    if(strcmp(nuevo.nombre, actual.nombre) < 0){
        nuevo.sig = dirActual;
        reescribeEntidad(nuevo, dir);
        escribeCabEntidades(dir);
        return;
    }

    //  Caso 3: buscar posición
    while(dirActual != -1 && strcmp(actual.nombre, nuevo.nombre) < 0){
        dirAnterior = dirActual;
        anterior = actual;

        dirActual = actual.sig;
        if(dirActual != -1){
            actual = leeEntidad(dirActual);
        }
    }

    // Insertar
    nuevo.sig = dirActual;
    reescribeEntidad(nuevo, dir);

    anterior.sig = dir;
    reescribeEntidad(anterior, dirAnterior);
}

//Captura los datos de un atributo
void Diccionariodedatos::creaAtributo()
{
    ATRIBUTO nuevo;

    long dir;

    pideEntidad();

    if(dirActiva != -1)
    {
        nuevo = capturaAtributo();

        if(buscaAtributo(nuevo.nombre) == -1)
        {
            dir = escribeAtributo(nuevo);

            insertarAtributo(nuevo,dir);

            printf("\nAtributo insertado\n");
        }
        else
            printf("\nEl atributo ya existe");
    }
}
//Busca un atributo en la entidad activa
void Diccionariodedatos::consultaAtributos()
{
    ATRIBUTO nuevo;

    long cab;

    pideEntidad();

    if(dirActiva != -1)
    {
        cab = activa.atr;

        if(cab == -1)
        {
            printf("\nNo hay atributos\n");
            return;
        }

        while(cab != -1)
        {
            nuevo = leeAtributo(cab);

            printf("\n%s %c %d %ld %d %s",
                   nuevo.nombre,
                   nuevo.tipo,
                   nuevo.tam,
                   nuevo.sig,
                   nuevo.clave,
                   nuevo.descripcion);

            cab = nuevo.sig;
        }
    }
}
//Pide una entidad y la deja activa para trabajar con sus atributos
void Diccionariodedatos::pideEntidad()
{
    ENTIDAD aux;

    printf("\nNombre entidad: ");
    scanf(" %[^\n]",aux.nombre);

    dirActiva = buscaEntidad(aux);

    if(dirActiva == -1)
        printf("\nNo existe entidad");
    else
        activa = leeEntidad(dirActiva);
}
//Captura los datos de un atributo
ATRIBUTO Diccionariodedatos::capturaAtributo()
{
    ATRIBUTO atr;

    printf("\nNombre atributo: ");
    scanf(" %[^\n]",atr.nombre);

    printf("Tipo: ");
    scanf(" %c",&atr.tipo);

    printf("Tamano: ");
    scanf("%d",&atr.tam);

    printf("Clave: ");
    scanf("%d",&atr.clave);

    printf("Descripcion: ");
    scanf(" %[^\n]",atr.descripcion);

    atr.sig = -1;

    return atr;
}
//Busca un atributo por nombre en la entidad activa
long Diccionariodedatos::buscaAtributo(char *atr)
{
    long cab = activa.atr;

    ATRIBUTO actual;

    while(cab != -1)
    {
        actual = leeAtributo(cab);

        if(strcmp(actual.nombre,atr) == 0)
            return cab;

        cab = actual.sig;
    }

    return -1;
}
//Escribe un atributo al final del archivo
long Diccionariodedatos::escribeAtributo(ATRIBUTO atr)
{
    long dir;

    fseek(archivo,0,SEEK_END);

    dir = ftell(archivo);

    fwrite(&atr,sizeof(ATRIBUTO),1,archivo);

    return dir;
}
//Lee un atributo desde una direccion especifica
ATRIBUTO Diccionariodedatos::leeAtributo(long dir)
{
    ATRIBUTO nvo;

    fseek(archivo,dir,SEEK_SET);

    fread(&nvo,sizeof(ATRIBUTO),1,archivo);

    return nvo;
}
//Actualiza la informacion de un atributo en el archivo
void Diccionariodedatos::reescribeAtributo(ATRIBUTO atr,long dir)
{
    fseek(archivo,dir,SEEK_SET);

    fwrite(&atr,sizeof(ATRIBUTO),1,archivo);
}
//Inserta un atributo en orden alfabetico
void Diccionariodedatos::insertarAtributo(ATRIBUTO nuevo,long dir)
{
    long cab = activa.atr;

    long dirant;

    ATRIBUTO actual, atrant;

    if(activa.atr == -1)
    {
        activa.atr = dir;

        reescribeEntidad(activa,dirActiva);
    }
    else
    {
        actual = leeAtributo(cab);

        if(strcmp(actual.nombre,nuevo.nombre) > 0)
        {
            nuevo.sig = cab;

            reescribeAtributo(nuevo,dir);

            activa.atr = dir;

            reescribeEntidad(activa,dirActiva);
        }
        else
        {
            while(cab != -1 &&
                  strcmp(nuevo.nombre,actual.nombre) > 0)
            {
                atrant = actual;

                dirant = cab;

                cab = actual.sig;

                if(cab != -1)
                    actual = leeAtributo(cab);
            }

            nuevo.sig = cab;

            reescribeAtributo(nuevo,dir);

            atrant.sig = dir;

            reescribeAtributo(atrant,dirant);
        }
    }
}
//Da de baja un atributo
void Diccionariodedatos::eliminaAtributos()
{
    char nombre[MAX];

    long dir;

    pideEntidad();

    if(dirActiva != -1)
    {
        printf("\nIngrese el nombre del atributo a eliminar: ");
        scanf(" %[^\n]",nombre);

        dir = buscaAtributo(nombre);

        if(dir == -1)
        {
            printf("\nError: el atributo no existe");
        }
        else
        {
            eliminaAtributo(nombre);

            printf("\nAtributo eliminado");
        }
    }
}

//Elimina un atributo de la lista enlazada
long Diccionariodedatos::eliminaAtributo(char nombre[MAX])
{
    long cab = activa.atr;

    long dirant = -1;

    ATRIBUTO actual, ant;

    if(cab == -1)
        return -1;

    actual = leeAtributo(cab);

    //Caso 1: eliminar el primero
    if(strcmp(actual.nombre,nombre) == 0)
    {
        activa.atr = actual.sig;

        reescribeEntidad(activa,dirActiva);

        return cab;
    }
    else
    {
        while(cab != -1 &&
              strcmp(actual.nombre,nombre) != 0)
        {
            dirant = cab;

            ant = actual;

            cab = actual.sig;

            if(cab != -1)
                actual = leeAtributo(cab);
        }

        //Caso 2: encontrado
        if(cab != -1)
        {
            ant.sig = actual.sig;

            reescribeAtributo(ant,dirant);

            return cab;
        }
    }

    //Caso 3: no encontrado
    return -1;
}

void Diccionariodedatos::modificaAtributo()
{
    char nombre[MAX];

    ATRIBUTO nuevo;

    long dir2, dir3;

    pideEntidad();

    if(dirActiva != -1)
    {
        printf("\nIngrese atributo a modificar: ");
        scanf(" %[^\n]",nombre);

        if(buscaAtributo(nombre) != -1)
        {
            printf("\nIngresa la nueva informacion:\n");

            nuevo = capturaAtributo();

            dir2 = buscaAtributo(nuevo.nombre);

            if(strcmp(nuevo.nombre,nombre) == 0 ||
               dir2 == -1)
            {
                dir3 = eliminaAtributo(nombre);

                reescribeAtributo(nuevo,dir3);

                insertarAtributo(nuevo,dir3);

                printf("\nAtributo modificado");
            }
            else
            {
                printf("\nNo se puede modificar porque ya existe uno con ese nombre");
            }
        }
        else
        {
            printf("\nNo existe el atributo");
        }
    }
}


void Diccionariodedatos::creaRegistro()
{ printf("\nTrabajando...\n"); }
void Diccionariodedatos::consultaRegistro()
{ printf("\nTrabajando...\n"); }
void Diccionariodedatos::eliminaRegistro()
{ printf("\nTrabajando...\n"); }
void Diccionariodedatos::modificaRegistro()
{ printf("\nTrabajando...\n"); }

