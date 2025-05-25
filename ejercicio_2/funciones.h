#include <iostream>
#define PI 3.14159

class Punto{
private:
 float x;
 float y;
public:
 Punto(float x, float y);
 float getX() const;
 float getY() const;
 void setX(float value);
 void setY(float value);
 ~Punto() = default;
};

class Circulo{
private:
 Punto centro;
 float radio;
public:
 Circulo( Punto centro, float r);
 Punto getCentro() const;
 float getRadio() const;
 void setCentro(Punto& nuevoCentro);
 void setRadio(float value);
 ~Circulo() = default;
};

class Elipse{
private:
Punto centro;
float b;
float a;
public:
Elipse( Punto centro, float b, float a);
Punto getCentro() const;
float getSemiejeMenor() const;
float getSemiejeMayor() const;
void setCentro(Punto& nuevoCentro);
void setSemiejeMenor(float value);
void setSemiejeMayor(float value);
~Elipse() = default;
};

class Rectangulo{
private:
 Punto vertice;
 float ancho;
 float largo;
public:
Rectangulo(Punto vertice, float ancho, float largo);
Punto getVertice() const;
float getAncho() const;
float getLargo() const;
void setVertice(Punto& nuevoVertice);
void setAncho(float value);
void setLargo(float value);
};

//caso generico
template<typename T>
class ProcesadorFigura{
public:
   void calcularArea(const T& figura){ 
   std::cout<<"No se puede calcular el area de la figura"<<std::endl;
 }
};

//caso especializado para punto 
template<>
class ProcesadorFigura<Punto>{
public:
   double calcularArea(const Punto& punto){
      return 0;
   }
};

//caso especializado para circulo
template<>
class ProcesadorFigura<Circulo>{
public:
  double calcularArea(const Circulo& circulo){
    return PI * (circulo.getRadio())* (circulo.getRadio());
 }
};

//caso especializado para elipse
template<>
class ProcesadorFigura<Elipse>{
public:
 double calcularArea(const Elipse& elipse){
    return PI * (elipse.getSemiejeMayor()) * (elipse.getSemiejeMenor());
 }
};

//caso especializado para rectangulo
template<>
class ProcesadorFigura<Rectangulo>{
public:
 double calcularArea(const Rectangulo& rect){
    return (rect.getAncho()) * (rect.getLargo());
 }
};



