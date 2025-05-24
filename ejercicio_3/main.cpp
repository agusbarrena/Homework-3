#include <iostream>
#include "funciones.h"


int main() {
    generarData<double> doubles;
    doubles.agregar(1.3);
    doubles.agregar(2.1);
    doubles.agregar(3.2);

    generarData<std::string> palabras;
    palabras.agregar("Hola");
    palabras.agregar("Mundo");

    generarData<std::vector<int>> listas;
    listas.agregar({1,2});
    listas.agregar({3,4});

    crearJSON cj1("vec_doubles", doubles);
    crearJSON cj2("palabras", palabras);
    crearJSON cj3("listas", listas);

    std::cout<< "{"<<std::endl;
    cj1.imprimir(); 
    cj2.imprimir(); 
    cj3.imprimir(); 
    std::cout<< "}"<<std::endl;
    return 0;
}

