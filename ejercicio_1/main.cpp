#include <iostream>
#include <memory>
#include "funciones.h"

int main(){
    //datos
    std::shared_ptr<Posicion> posicion = std::make_shared<Posicion>(-34.6f, -58.4f, 950.0f, 5.3);
    std::shared_ptr<Presion> presion = std::make_shared<Presion>(101.3f, 5.8f, 6.1f);

    SaveFlightData original(posicion, presion);

    //serializar todas las mediciones del archivo
    std::ofstream out("mediciones.dat", std::ios::binary);
        if(out.is_open()){
            original.serializar(out);
            out.close();
        }
    

    //deserializar todas las mediciones desde el archivo

    SaveFlightData cargado;
    std::ifstream in("mediciones.dat", std::ios::binary);
        if(in.is_open()){
            cargado.deserializar(in);
            in.close();
        }
    

    //Imprimo los resultados
    std::cout<< "Datos originales: \n";
    original.imprimir();

    std::cout<< "Datos cargados: \n";
    cargado.imprimir();

}