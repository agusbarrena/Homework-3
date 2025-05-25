 #include <iostream>
 #include "funciones.h"

Punto::Punto(float x, float y) : x(x), y(y) {}

float Punto::getX() const{
   return x;
}

float Punto::getY() const{
   return y;
}

void Punto::setX(float value){
   x = value;
}

void Punto::setY(float value){
   y = value;
}

Circulo::Circulo( Punto centro, float r) : centro(centro), radio(r) {}

Punto Circulo::getCentro() const{
   return centro;
}
 
float Circulo::getRadio() const{
   return radio;
}

void Circulo::setCentro(Punto& nuevoCentro){
   centro = nuevoCentro;
}

void Circulo::setRadio(float value){
   radio = value;
}

Elipse::Elipse( Punto centro, float b, float a) : centro(centro), b(b), a(a) {}

Punto Elipse::getCentro() const{
   return centro;
}

float Elipse::getSemiejeMenor() const{
   return b;
}

float Elipse::getSemiejeMayor() const{
   return a;
}

void Elipse::setCentro(Punto& nuevoCentro){
   centro = nuevoCentro;
}

void Elipse::setSemiejeMenor(float value){
   b = value;
}

void Elipse::setSemiejeMayor(float value){
   a = value;
}

Rectangulo::Rectangulo(Punto vertice, float ancho, float largo) : vertice(vertice), ancho(ancho), largo(largo) {}
Punto Rectangulo::getVertice() const{
   return vertice;
}

float Rectangulo::getAncho() const{
   return ancho;
}

float Rectangulo::getLargo() const{
   return largo;
}

void Rectangulo::setVertice(Punto& nuevoVertice){
   vertice = nuevoVertice;
}

void Rectangulo::setAncho(float value){
   ancho = value;
}

void Rectangulo::setLargo(float value){
   largo = value;
}