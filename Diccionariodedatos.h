#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// ESTRUCTURA
struct Entidad{
    char nombre[30];
    long atr;   // apunta a atributos (-1 si no hay)
    long data;  // apunta a datos (-1 si no hay)
    long sig;
};

// FUNCIONES BASE
Entidad capturaEntidad();
long escribeEntidad(Entidad ent);
int leerEntero();

// Archivo global
extern FILE *arch;

// Manejo de archivo
int nuevoDiccionario();
int abrirDiccionario();
void escribeCabecera(long cab);
long leeCabecera();

// Menus
void menuPrincipal(int *op);
void menuEntidades(int *op);
void menuAtributos(int *op);
void menuDatos(int *op);

// ENTIDADES
void creaEntidad();
void consultaEntidades();
void eliminaEntidad();
void modificaEntidadM();

// ATRIBUTOS
void creaAtributo();
void consultaAtributos();
void eliminaAtributos();
void modificaAtributo();

// REGISTROS
void creaRegistro();
void consultaRegistro();
void eliminaRegistro();
void modificaRegistro();

#endif