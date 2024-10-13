//Benjamin Cuello
#include "App.h"

int main() {

    //Instancia app

    App app;

    //Cargar datos de los txt
    app.cargarDatos();

    //Ejecutar el programa
    app.ejecutar();

    //Guardar los datos en txt
    app.guardarDatos();
    return 0;
}
