#ifndef APP_H
#define APP_H

#include "Sistema.h"

class App {

private:

    //Puntero al sistema
    Sistema* sistema;
    //otras funciones
    static void menu();
    static void menu2();
    static std::string preguntar(const std::string& pregunta);
    std::string esValidoTipo();
    static void print(const std::string& mensaje);
    void opcion1();
    static void menu3();
    std::string verificarId();
    void opcion5();
    std::string esValidoMaterial(std::string materialesDisponibles);
    std::string esValidoIsbnMaterialDevolver(const std::string & idUsuario);
    void opcion4();
    std::string esValidoTipoDeBusqueda();
    void opcion3();
public:
    App();
    void cargarDatos();
    void ejecutar();
    void guardarDatos();


};

#endif // APP_H
