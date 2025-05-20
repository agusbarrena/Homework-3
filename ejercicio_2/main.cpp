#include <iostream>
#include "funciones.h"

int main(){
    Punto<int> p(3,4);
    std::cout<< "Area del punto: "<< ProcesadorFigura<Punto<int>>::calcularArea(p) <<std::endl;

    Circulo<int,float> c(p, 3.5f);
    std::cout<< "Area del Circulo: "<< ProcesadorFigura<Circulo<int,float>>::calcularArea(c) <<std::endl;

    Elipse<int,double> e(p, 2.26, 7.95);
    std::cout<<"Area de la Elipse: "<< ProcesadorFigura<Elipse<int,double>>::calcularArea(e) <<std::endl;

    Rectangulo<int,int> r(p, 5, 8);
    std::cout<<"Area del rectangulo: "<< ProcesadorFigura<Rectangulo<int,int>>::calcularArea(r)<<std::endl;

    return 0;
}