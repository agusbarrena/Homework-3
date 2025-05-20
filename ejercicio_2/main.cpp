#include <iostream>
#include "funciones.h"

int main(){
    Punto p(3.0f,4.0f);
    ProcesadorFigura<Punto> procesadorPunto;
    std::cout<< "Area del Punto: "<< procesadorPunto.calcularArea(p) <<std::endl;

    Circulo c(p, 3.5f);
    ProcesadorFigura<Circulo> procesadorCirculo;
    std::cout<< "Area del Circulo: "<< procesadorCirculo.calcularArea(c) <<std::endl;

    Elipse e(p, 2.26f, 7.95f);
    ProcesadorFigura<Elipse> procesadorElipse;
    std::cout<<"Area de la Elipse: "<< procesadorElipse.calcularArea(e) <<std::endl;

    Rectangulo r(p, 5.0f, 8.0f);
    ProcesadorFigura<Rectangulo> procesadorRectangulo;
    std::cout<<"Area del Rectangulo: "<< procesadorRectangulo.calcularArea(r)<<std::endl;

    return 0;
}