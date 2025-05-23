#include <iostream>
#include <fstream>
#include <memory>

class IMediciones{
public:
    virtual void serializar(std::ofstream& out) const = 0;
    virtual void deserializar(std::ifstream& in) = 0;
    virtual ~IMediciones() = default;
};

class MedicionBase : public IMediciones{
public:
    MedicionBase(float tiempoMedicion); //unique_ptr
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    float getTiempo() const;
    virtual void imprimir() const; 
    virtual ~MedicionBase() = default;
protected:
   std::unique_ptr<float> tiempoMedicion;
};

class Presion : public MedicionBase{
public:
    Presion(); //constructor con parametros predeterminados para deserializar
    Presion(float p, float q, float t);
    float presionEstatica;//p
    float presionDinamica;//q
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};

class Posicion: public MedicionBase{
public:
    Posicion(); //constructor con parametros predeterminados para deserializar
    Posicion(float lat, float lon, float alt, float t);
    float latitud;
    float longitud;
    float altitud;
    void serializar(std::ofstream& out) const override;
    void deserializar(std::ifstream& in) override;
    void imprimir() const override;
};

class SaveFlightData{
public:
SaveFlightData(const std::shared_ptr<Posicion>& p, const std::shared_ptr<Presion>& q);
std::shared_ptr<Posicion> p;
std::shared_ptr<Presion> q;
void serializar(std::ofstream& out) const;
void deserializar(std::ifstream& in);
void imprimir() const;
};

