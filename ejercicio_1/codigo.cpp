#include "funciones.h"
#include <iostream>
#include <memory>
#include <fstream>

MedicionBase::MedicionBase(float tiempoMedicion) : tiempoMedicion(std::make_unique<float>(tiempoMedicion)) {}

void MedicionBase::serializar(std::ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase::deserializar(std::ifstream& in){
    tiempoMedicion = std::make_unique<float>(0.0f); //se asigna memoria
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

float MedicionBase::getTiempo() const{
    return *tiempoMedicion; 
}

void MedicionBase::imprimir() const{
    std::cout<<"Tiempo en que se tomo la medicion: " << getTiempo() << " minutos"<< std::endl;
}

Presion::Presion(float p, float q, float t) : presionEstatica(p), presionDinamica(q), MedicionBase(t) {}

void Presion::serializar(std::ofstream& out) const{
    MedicionBase::serializar(out); //serializacion de la clase base (MedicionBase)
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::deserializar(std::ifstream& in){
    MedicionBase::deserializar(in); //deserializacion de la clase base (MedicionBase)
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion::imprimir() const{
    MedicionBase::imprimir();
    std::cout<< "Presion estatica: " << presionEstatica << ", Presion Dinamica: " << presionDinamica << std::endl;
}

Posicion::Posicion(float lat, float lon, float alt, float t) : latitud(lat), longitud(lon), altitud(alt), MedicionBase(t) {}

void Posicion::serializar(std::ofstream& out) const{
    MedicionBase::serializar(out);
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion::deserializar(std::ifstream& in){
    MedicionBase::deserializar(in);
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion::imprimir() const {
    MedicionBase::imprimir();
    std::cout<< "Latitud: "<< latitud << ", Longitud: "<< longitud << ", Altitud: "<< altitud <<std::endl;
}

SaveFlightData::SaveFlightData(const std::shared_ptr<Posicion>& p, const std::shared_ptr<Presion>& q) : p(p), q(q) {}

void SaveFlightData::serializar(std::ofstream& out) const{
    if(p) p->serializar(out);
    if(q) q->serializar(out); 
}

void SaveFlightData::deserializar(std::ifstream& in){
    p = std::make_shared<Posicion>();
    if(p) p->deserializar(in);

    q = std::make_shared<Presion>();
    if(q) q->deserializar(in);
}

void SaveFlightData::imprimir() const{
    if(p) p->imprimir();
    if(q) q->imprimir();
}

//Explicacion de por que no se necesita hacer std::move:
//El unique_ptr no se copia, sino que se serializa su contenido y luego se reconstruye con make_unique en el proceso de deserializacion
//Las clases derivadas Presion y Posicion, deserializan primero los datos de la clase base(MedicionBase) y luego sus propios miembros.La clase SaveFlight data, deserializa primero los datos de Posicion y Presion. Se pasan  como shared_ptr porque ambas tienen una relacion de agregacion con esta clase.
//Por lo tanto, no se necesita usar std::move porque no se transfiere el ownership de objetos.En lugar de eso se crea un nuevo objeto a partir de los datos deserializados.