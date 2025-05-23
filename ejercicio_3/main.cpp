#include <iostream>
#include "funciones.h"

int main(){
    generarData datos;
    //agrego valores al vector vec_doubles
    datos.agregarValores(1.3);
    datos.agregarValores(2.1);
    datos.agregarValores(3.2);
    //agrego strings al vector palabras
    datos.agregarValores(std::string("Hola"));
    datos.agregarValores(std::string("Mundo"));
    //agrego vectores al vector listas
    datos.agregarValores(std::vector<int>{1,2});
    datos.agregarValores(std::vector<int>{3,4});
    
    crearJSON JSON(datos);

    JSON.imprimir();

    return 0;
}