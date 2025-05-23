#include <iostream>
#include "funciones.h"
#include <vector>

crearJSON::crearJSON(const generarData& datos) : datos(datos) {}

void crearJSON::imprimir() const{
    std::cout<<"{";
    const auto& vec_double = datos.getVec_double();
    std::cout<< " \"" << vec_double.first<< "\" : [";
    for(const auto& num : vec_double.second){
        std::cout<< num <<",";
    }
    std::cout << "],\n";

    const auto& palabras =datos.getPalabras();
    std::cout<<" \""<< palabras.first << "\" : [";
    for(auto& palabra : palabras.second){
        std::cout<< "\"" << palabra << ",";
    }
    std::cout<<"],\n";

    const auto& listas = datos.getListas();
    std::cout<<" \"" << listas.first << "\" : [\n";
    for(size_t i = 0; i< listas.second.size(); i++){
        std::cout<<"    [";
        for(size_t j = 0; j <listas.second[i].size(); j++){
            std::cout<<  listas.second[i][j];
            if(j != listas.second[i].size()-1){
                std::cout<< ",";
            }
        }
        std::cout<<"]";
        if(i != listas.second.size() -1){
            std::cout<<",";
        }
        std::cout<<"\n";
    }
    std::cout<<"}\n";
}