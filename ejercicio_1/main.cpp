#include <iostream>
#include <memory>
#include "funciones.h"
#include <vector>

int main(){
    //datos
    auto pos = std::make_shared<Posicion>(-34.6f, -58.4f, 950.0f, 5.3f);
    auto pres = std::make_shared<Presion>(101.3f, 5.8f, 6.1f);
    SaveFlightData datos(pos, pres);

    //mustro informacion antes de serializar
    std::cout<<"Antes de serializar: \n";
    datos.imprimir();
    
    //serializacion: serializo todos los datos a un archivo
    std::ofstream out("vuelo.dat", std::ios::binary);
    if(out.is_open()){
        datos.serializar(out);
        out.close();
    }

    //deserializacion : creo objetos vacios para deserializar desde el archivo
    auto posDes = std::make_shared<Posicion>(0.0f, -0.0f, 0.0f, 0.0f);
    auto presDes = std::make_shared<Presion>(0.0f, 0.0f, 0.0f);
    SaveFlightData datosDes(posDes, presDes);
    std::ifstream in("vuelo.dat", std::ios::binary);
    if(in.is_open()){
        datosDes.deserializar(in);
        in.close();    
    }

    //muestra la informacion obtenida
    std::cout<< "\nDespues de deserializar: \n";
    datosDes.imprimir();

    return 0;
}