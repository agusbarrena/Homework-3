#include <iostream>
#include <vector>
#include <string>

using vectorDT = std::pair<std::string, std::vector<double>>;
using palabrasDT = std::pair<std::string, std::vector<std::string>>;
using listasDT = std::pair<std::string, std::vector<std::vector<int>>>;

class generarData{
private:
 vectorDT vec_doubles = {"vec_doubles", {}};
 palabrasDT palabras = {"palabras", {}};
 listasDT listas = {"listas",{}};

public:
 template<typename T>
 void agregarValores(const T& valor){
    if constexpr (std::is_same<T, double>::value){
        vec_doubles.second.push_back(valor);
    }
    else if constexpr (std::is_same<T, std::string>::value){
        palabras.second.push_back(valor);
    }
    else if constexpr (std::is_same<T, std::vector<int>>::value){
        listas.second.push_back(valor);
    }else{
        static_assert(std::is_same<T, double>::value && std::is_same<T, std::string>::value && std::is_same<T, int>::value, "Tipo no soportado, solo se acepta double, string o int."); //Chequea que se cumpla la condicion, si no cumple, como es estatico no va a compilar y tira el error
    }
 }

 const vectorDT& getVec_double() const {return vec_doubles;}
 const palabrasDT& getPalabras() const {return palabras;}
 const listasDT& getListas() const {return listas;}
 ~generarData() = default;
};

class crearJSON{
private:
 const generarData& datos;
public:
 crearJSON(const generarData& datos);
 void imprimir() const;
 ~crearJSON() = default;
};

