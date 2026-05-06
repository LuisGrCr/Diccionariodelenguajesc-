#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef char cadena[100];

// ESTRUCTURA
typedef struct
{
    long atr;
    long sig;
    long data;
    cadena nombre;
}ENTIDAD;

typedef struct 
{
    char tipo;
    int tam;
    long sig;
    int clave;
    cadena descripcion;
}ATRIBUTO;


class Diccionariodedatos
{
    private:
    FILE  *archivo;
    ENTIDAD activa;
    long dirActiva;
    long tamBloque;
    int NumAtributos;
    char nombreArchivo [MAX];
    
    public:
    Diccionariodedatos();

    int nuevoDiccionario();
    int abrirDiccionario();

    int leerEntero();

    //Menus
    void menuPrincipal(int *op);
    void menuEntidades(int *op);
    void menuAtributos(int op);
    void menuDatos(int *op);

    // ENTIDADES
    void altaEntidad();
    void consultaEntidades();
    void eliminaEntidad();
    long eliminaEntidad(char nombre[MAX]);
    void modificaEntidad();
    long getCabEntidades();
    void escribeCabEntidades(long cab);
    ENTIDAD capturaEntidad();
    long buscaEntidad(ENTIDAD ent);
    ENTIDAD leeEntidad(long dir);
    long escribeEntidad(ENTIDAD ent);
    void reescribeEntidad(ENTIDAD nuevo,long dir);
    void insertarEntidad(ENTIDAD nuevo,long dir);
    
    
    //Funciones atributos
    void creaAtributo();
    void consultaAtributos();
    void eliminaAtributos();
    void modificaAtributo();

    void creaRegistro();
    void consultaRegistro();
    void eliminaRegistro();
    void modificaRegistro();

};


#endif