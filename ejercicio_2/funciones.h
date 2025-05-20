#include <iostream>
#define PI 3.14159

template <typename T>

class Punto{
private:
 T x;
 T y;
public:
 Punto(T x, T y) : x(x), y(y) {}
 T getX() const{
   return x;
 }
 T getY() const{
   return y;
 }
 void setX(T value){
   x = value;
 }
 void setY(T value){
   y = value;
 }
};

template<typename T, typename U>

class Circulo{
private:
 Punto<T> centro;
 U radio;
public:
 Circulo( Punto<T> centro, U r) : centro(centro), radio(r) {}
 Punto<T> getCentro() const{
   return centro;
 }
 U getRadio() const{
   return radio;
 }
 void setCentro(Punto<T>& nuevoCentro){
   centro = nuevoCentro;
 }
 void setRadio(U value){
   radio = value;
 }
};

template<typename T, typename U>

class Elipse{
private:
Punto<T> centro;
U b;
U a;
public:
Elipse( Punto<T> centro, U a, U b) : centro(centro), a(a), b(b) {}
Punto<T> getCentro() const{
   return centro;
}
U getSemiejeMenor() const{
   return b;
}
U getSemiejeMayor() const{
   return a;
}
void setCentro(Punto<T>& nuevoCentro){
   centro = nuevoCentro;
}
void setSemiejeMenor(U value){
   b = value;
}
void setSemiejeMayor(U value){
   a = value;
}
};

template<typename T, typename U>

class Rectangulo{
private:
 Punto<T> vertice;
 U ancho;
 U largo;
public:
Rectangulo(Punto<T> vertice, U ancho, U largo) : vertice(vertice), ancho(ancho), largo(largo) {}
Punto<T> getVertice() const{
   return vertice;
}
U getAncho() const{
   return ancho;
}
U getLargo() const{
   return largo;
}
void setVertice(Punto<T>& nuevoVertice){
   vertice = nuevoVertice;
}
void setAncho(U value){
   ancho = value;
}
void setLargo(U value){
   largo = value;
}
};

//caso generico
template <typename Figura>
class ProcesadorFigura{
public:
 static double calcularArea(const Figura& figura); //uso static para evitarme instanciar el Procesador
};

//caso especializado punto
template<typename T>
class ProcesadorFigura<Punto<T>>{
public:
 static int calcularArea(const Punto<T>& punto){ 
    return 0;
 }
};

//caso especializado circulo
template<typename T, typename U>
class ProcesadorFigura<Circulo<T, U>>{
public:
 static double calcularArea(const Circulo<T, U>& circulo){
    return PI * (circulo.getRadio())* (circulo.getRadio());
 }
};

//caso especializado elipse
template<typename T, typename U>
class ProcesadorFigura<Elipse<T, U>>{
public:
 static double calcularArea(const Elipse<T, U>& elipse){
    return PI * (elipse.getSemiejeMayor()) * (elipse.getSemiejeMenor());
 }
};

//caso especializado rectangulo
template<typename T, typename U>
class ProcesadorFigura<Rectangulo<T, U>>{
public:
 static double calcularArea(const Rectangulo<T, U>& rect){
    return (rect.getAncho()) * (rect.getLargo());
 }
};



