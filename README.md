# Homework-3
Diferentes ejercicios aplicando serialization y templates.

## Organización
El repositorio contiene 3 carpetas, cada una con el número del ejercicio desarrollado en la misma. Cada carpeta consta de un archivo funciones.h que contiene las firmas de las  funciones utilizadas para la resolucion del ejercicio, un archivo codigo.cpp el cual contiene el desarrollo de dichas funciones y un archivo main.cpp para compilar y ejecutar el programa, mostrando así el resultado. La carpeta "ejercicio_3" solo contiene los archivos "funciones.h" y "main.cpp" porque al una de las clases ser una plantilla y la otra usar un constructor con plantilla, conviene definirlas completamente en el mismo archivo donde las declaro.

Con respecto a conclusiones escritas pedidas por la consigna o incluso aclaraciones hechas por mí acerca de la implementación de mi código, todas se encontrarán dentro de estos archivos como comentarios dentro del código.

## Instalacion
En necesidad de clonar el repositorio adjunto el link:
    ```bash
    git clone https://github.com/agusbarrena/Homework-3.git

## Compilar los ejercicios
Como mencioné anteriormente, las primeras dos carpetas contienen los tres mismos tipos de archivo, nombrados de la misma manera simplemente que contienen ejercicios diferentes, por eso se correran con el mismo comando. Por otro lado la tercer carpeta, al tener solo un archivo para compilar, utilizará otro comando. Tener en cuenta que para poder compilar debe tener instalado **G++** (compilador de C++) en su sistema.

### Instalación de G++

- **Ubuntu**: `sudo apt install g++`
- **macOS**: `brew install gcc`
- **Windows**: usa MinGW o WSL

Ya con el compilador instalado, abrir la terminal y ubicarse en la carpeta de dicho ejercicio a revisar (hacer esto con el comando "cd nombre_de_la_carpeta"). Para el ejercicio_1 y ejercicio_2 ingrese el siguiente comando : g++ main.cpp codigo.cpp -Wall -g -o main y por último ingresar: ./main para que se ejecute. Para el ejercicio_3 ingrese el siguiente comando: g++ main.cpp -Wall -g -o main y por último ingresar: ./main para que se ejecute.
