
#include "Diccionariodedatos.h"

int main(){
    int op;
    menuPrincipal(&op);
    return 0;
}

// MENU PRINCIPAL
void menuPrincipal(int *op){
    do{
        cout << "\n-----MENU PRINCIPAL-----\n";
        cout << "1.- Nuevo diccionario\n";
        cout << "2.- Abrir Diccionario\n";
        cout << "3.- Salir\n";

        *op = leerEntero();

        switch (*op){
        case 1:
            if(nuevoDiccionario()){
                menuEntidades(op);
            }
            break;

        case 2:
            if(abrirDiccionario()){
                menuEntidades(op);
            }
            break;
        }

    } while (*op != 3);
}

// MENU ENTIDADES
void menuEntidades(int *op){
    do{
        cout << "\n-----MENU ENTIDADES-----\n";
        cout << "1.- Nueva entidad\n";
        cout << "2.- Consulta entidad\n";
        cout << "3.- Elimina entidad\n";
        cout << "4.- Modifica entidad\n";
        cout << "5.- Menu atributos\n";
        cout << "6.- Menu datos\n";
        cout << "7.- Regresar\n";

        *op = leerEntero();

        switch (*op){
        case 1: creaEntidad(); break;
        case 2: consultaEntidades(); break;
        case 3: eliminaEntidad(); break;
        case 4: modificaEntidadM(); break;
        case 5: menuAtributos(op); break;
        case 6: menuDatos(op); break;
        }

    } while (*op != 7);
}

// MENU ATRIBUTOS
void menuAtributos(int *op){
    do{
        cout << "\n-----MENU ATRIBUTOS-----\n";
        cout << "1.- Nuevo atributo\n";
        cout << "2.- Consulta atributos\n";
        cout << "3.- Elimina atributos\n";
        cout << "4.- Modifica atributos\n";
        cout << "5.- Regresar\n";

        *op = leerEntero();

        switch (*op){
        case 1: creaAtributo(); break;
        case 2: consultaAtributos(); break;
        case 3: eliminaAtributos(); break;
        case 4: modificaAtributo(); break;
        }

    } while (*op != 5);
}

// MENU DATOS
void menuDatos(int *op){
    do{
        cout << "\n-----MENU DATOS-----\n";
        cout << "1.- Nuevo registro\n";
        cout << "2.- Consulta registro\n";
        cout << "3.- Elimina registro\n";
        cout << "4.- Modifica registro\n";
        cout << "5.- Regresar\n";

        *op = leerEntero();

        switch (*op){
        case 1: creaRegistro(); break;
        case 2: consultaRegistro(); break;
        case 3: eliminaRegistro(); break;
        case 4: modificaRegistro(); break;
        }

    } while (*op != 5);
}