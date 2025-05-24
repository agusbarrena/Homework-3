#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <type_traits>

template<typename T>
class generarData { //clase 1
private:
    std::vector<T> datos; //solo vector tipo T generico

public:
    void agregar(const T& valor) {
        datos.push_back(valor);
    }

    std::string procesar() const { //procesa el contenedor con constexpr, chequea el tipo de dato T, genera el string que quiero devolver
        std::ostringstream oss;

        if constexpr (std::is_same<T, std::string>::value) {
            oss << "[";
            for (size_t i = 0; i < datos.size(); ++i) {
                oss << "\"" << datos[i] << "\"";
                if (i + 1 < datos.size()) oss << ", ";
            }
            oss << "],";
        }
        else if constexpr (std::is_same<T, double>::value) {
            oss << "[";
            for (size_t i = 0; i < datos.size(); ++i) {
                oss << datos[i];
                if (i + 1 < datos.size()) oss << ", ";
            }
            oss << "],";
        }
        else if constexpr (std::is_same<T, std::vector<int>>::value) {
           oss << "[\n";
            for (size_t i = 0; i < datos.size(); ++i) {
                oss <<"    [";
                for (size_t j = 0; j < datos[i].size(); ++j) {
                    oss << datos[i][j];
                    if (j + 1 < datos[i].size()) oss << ", ";
                }
                oss << "]";
                if (i + 1 < datos.size()) oss << ",";
                oss << "\n";
            }
            oss <<"    ]";
        }
        else {
            static_assert(std::is_same<T, std::string>::value || std::is_same<T, double>::value || std::is_same<T, std::vector<int>>::value, "Tipo no soportado");
        }

        return oss.str();
    }
};

class crearJSON { //clase 2
private:
    std::pair<std::string, std::string> resultado;

public:
    template<typename T>
    crearJSON(const std::string& key, const generarData<T>& data) { resultado = {key, data.procesar()};} //recibe una key ("vec_doubles", "palabras", "listas") y recibe un contenedor de la clase 1. Los guarda en el pair

    void imprimir() const{
    std::cout << "\"" << resultado.first << "\": " << resultado.second << std::endl;
    }

    const std::pair<std::string, std::string>& get() const{
    return resultado;
    }
};
