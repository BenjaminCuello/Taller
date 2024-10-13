#include "App.h"
#include <iostream>
#include <string>

// constructor
App::App() {
    sistema = Sistema::obtenerInstancia();
}

//Cargar Datos a txt
void App::cargarDatos() {
    sistema->cargarBiblioteca();
    sistema->cargarUsuarios();
}

//Guardar datos en txt
void App::guardarDatos() {
    sistema->guardarBiblioteca();
    sistema->guardarUsuarios();
}

//Menu principal
void App::menu() {
    print("1) Agregar Material a la Biblioteca\n"
      "2) Mostrar Informacion de los Materiales\n"
      "3) Buscar Material\n"
      "4) Prestar y Devolver Material\n"
      "5) Gestion de Usuarios\n"
      "6) Salir\n");
}

//Metodo para imprimir mas facil
void App::print(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}

//Metodo para preguntar
std::string App::preguntar(const std::string& pregunta) {
    std::string respuesta;
    print(pregunta);
    std::cout << "> ";
    std::getline(std::cin, respuesta);
    return respuesta;
}

//Metodo para agregar un Material a la biblioteca
void App::opcion1() {
    std::string nombre = preguntar(" ¿Cual es el nombre del material?");
    std::string isbn = preguntar("¿Cual es el isbn del material?");
    if (sistema->verificarIsbn(isbn) == true) {
        print("El material ingresado ya se encuentra en el sistema");
    }
    else {
        std::string autor = preguntar("¿Cual es el autor del material?");
        std::string tipo = esValidoTipo();
        if (tipo == "libro") {
            std::string fecha = preguntar("¿Cual fue la fecha de publicacion?");
            std::string resumen = preguntar("¿Cual es su resumen?");
            print(sistema->agregarLibro(nombre,isbn,autor,false,tipo,fecha,resumen));
        }
        else if (tipo == "revista") {
            std::string numeroEdicion = preguntar("¿Cual es el numero de edicion?");
            std::string mesPublicacion = preguntar("¿Cual fue su mes de publicacion?");
            print(sistema->agregarRevista(nombre,isbn,autor,false,tipo,numeroEdicion,mesPublicacion));
        }
        else {
            print("Ocurrio un error al verificar el tipo de material");
        }
    }

}

//Metodo para verificar si el tipo de busqueda a realizar es valido
std::string App::esValidoTipoDeBusqueda() {
    std::string respuestaTipoBusqueda;
    bool valido = false;
    do {
        respuestaTipoBusqueda = preguntar("Ingrese como desea buscar el material\n"
                                          "1.- Titulo\n"
                                          "2.- Autor : ");
        if (respuestaTipoBusqueda == "1" || respuestaTipoBusqueda == "2") {
            valido = true;
        } else {
            print("Ingrese una opcion valida");
        }
    } while (valido == false);
    if (respuestaTipoBusqueda == "1") {
        respuestaTipoBusqueda = "titulo";
    }
    else if (respuestaTipoBusqueda == "2") {
        respuestaTipoBusqueda = "autor";
    }
    print("Tipo de busqueda valido: " + respuestaTipoBusqueda);
    return respuestaTipoBusqueda;
}

//Metodo para buscar un material
void App::opcion3() {
    std::string tipoBusqueda = esValidoTipoDeBusqueda();
    if (tipoBusqueda == "titulo") {
        std::string tituloABuscar = preguntar("Ingrese el titulo a buscar:");
        print(sistema->buscarMaterialPorTitulo(tituloABuscar));
    }
    else if (tipoBusqueda == "autor") {
        std::string autorABuscar = preguntar("Ingrese el nombre del autor a buscar:");
        print(sistema->buscarMaterialPorAutor(autorABuscar));
    }
    else {
        print("Ocuurio un error con el tipo de busqueda");
    }
}

//Metodo para prestar o devolver un material
void App::opcion4() {
    std::string idUsuario = preguntar("Ingrese su id para continuar:");
    bool valido = sistema->comprobarId(idUsuario);
    if (valido ==  true) {
        print("Usuario encontrado");
        std::string opcion4 = "";
        do {
            menu2();
            opcion4 = preguntar("Ingrese la opcion que desea realizar:");
            if (opcion4 == "1") {
                int cantMateriales = sistema->materialesDispoonibles();
                if (cantMateriales == 0) {
                    print("No hay materiales disponibles para prestar :C");
                }
                else {
                    print("Hay " + std::to_string(cantMateriales) + "Material/es disponibles para prestar: ");
                    std::string materialesDisponibles = sistema->mostrarMateriales();
                    std::string isbnMaterial = esValidoMaterial(materialesDisponibles);
                    print(sistema->prestarMaterial(isbnMaterial, idUsuario));
                }
            }
            else if (opcion4 == "2") {
                if (sistema->comprobarMaterialesPrestados(idUsuario) == true) {
                    std::string isbnMaterialADevolver = esValidoIsbnMaterialDevolver(idUsuario);
                    print(sistema->devolverMaterial(isbnMaterialADevolver,idUsuario));
                }
                else {
                    print("El usuario ingresado no tiene libros por devolver");
                }
            }
            else if (opcion4 == "3") {
                print("Saliendo del submenu");
            }
            else {
                print("Opcion invalida");
            }
        } while (opcion4 != "3");
    }
    else {
        print("Usuario inexistente, recuerde registrarse primero");
    }
}

//Metodo para la gestion de Usuarios
void App::opcion5() {
    std::string opcion5 = "";
    do {
        menu3();
        opcion5 = preguntar("Ingrese la opcion que desea realizar:");
        if (opcion5 == "1") {
            std::string nombreNuevo = preguntar("Ingrese su nombre: ");
            std::string idNuevo = verificarId();
            print(sistema->registrarUsuario(nombreNuevo,idNuevo));

        }
        else if (opcion5 == "2") {
            std::string idABuscar = preguntar("Ingrese el id a buscar:");
            if (sistema->comprobarId(idABuscar) == true) {
                print(sistema->mostrarDatosUsuario(idABuscar));
            }
            else {
                print("El usuario ingresado no esta en el sistema");
            }
        }
        else if (opcion5 == "3") {
            std::string idAEliminar = preguntar("Ingrese el id del usuario a eliminar:");
            if (sistema->comprobarId(idAEliminar) == true) {
                print(sistema->eliminarUsuario(idAEliminar));
            }
            else {
                print("El usuario ingresado no esta en el sistema");
            }
        }
        else if (opcion5 == "4") {
            print("Saliendo del submenu");
        }
        else {
            print("Opcion invalida");
        }
    } while (opcion5 != "4");
}

//Metodo para verificar si el tipo de material ingresado es valido
std::string App::esValidoTipo() {
    std::string respuestaTipo;
    bool valido = false;
    do {
        respuestaTipo = preguntar("Ingrese el tipo de material que es \n"
                                  "1.- libro\n"
                                  "2.- revista) : ");
        if (respuestaTipo == "1" || respuestaTipo == "2") {
            valido = true;
        } else {
            print("Ingrese una opcion valida ");
        }
    } while (valido == false);
    if (respuestaTipo == "1") {
        respuestaTipo = "libro";
    }
    else if (respuestaTipo == "2") {
        respuestaTipo = "revista";
    }
    print("Tipo de material valido: " + respuestaTipo);
    return respuestaTipo;
}

//Metodo para verificar que el isbn del material es valido
std::string App::esValidoMaterial(std::string materialesDisponibles) {
    std::string isbnDelMaterial;
    bool valido = false;
    do {
        print(materialesDisponibles);
        isbnDelMaterial = preguntar("Ingrese el Isbn del Material que desea: ");
        if (sistema->verificarIsbn(isbnDelMaterial) == true) {
            valido = true;
        } else {
            print("El Isbn es invalido, revise");
        }
    } while (valido == false);
    print("Isbn valido ");
    return isbnDelMaterial;
}

//Metodo para verificar la disponibilidad del id
std::string App::verificarId() {
    std::string idAUsar;
    bool valido = false;
    do {
        idAUsar = preguntar("Ingrese su id a usar: ");
        if (sistema->verificarDisponiblidadId(idAUsar) == true) {
            valido = true;
        } else {
            print("El id se encuentra en uso, intente con otro");
        }
    } while (valido == false);
    print("id valido ");
    return idAUsar;
}

//Metodo para verificar que el isbn del material ingresado a devolver es valido
std::string App::esValidoIsbnMaterialDevolver(const std::string &idUsuario) {
    std::string opciones = sistema->mostrarMaterialesPrestados(idUsuario);
    std::string respuesta;
    bool valido = false;
    do {
        print(opciones);
        respuesta = preguntar("Ingrese el isbn del material que desea devolver: ");
        if (sistema->verificarIsbnADevolver(respuesta, idUsuario) == true) {
            valido = true;
        }
        else {
            print("El Isbn es invalido, o no corresponde a los materiales prestados por este usuario, revise");
        }
    } while (valido == false);
    return respuesta;
}

//Metodo que imprime un submenu
void App::menu2() {
    print("1) Realizar un prestamo\n"
      "2) Realizar una devolucion\n"
      "3) Volver al menu principal\n");
}

//Metodo que imprime un submenu 2
void App::menu3() {
    print("1) Registrar un usuario\n"
    "2) Buscar un usuario\n"
    "3) Eliminar un usuario\n"
    "4) Volver al menu principal\n");
}

//Metodo donde se ejecuta el menu principal
void App::ejecutar() {
    print("Bienvenido");
    print("-----------");
    std::string opcion = "";
    do {
        menu();
        opcion = preguntar("Ingrese la opcion que desea realizar");
        if (opcion == "1") {
            if (sistema->getCantidadMateriales() < 100) {
                opcion1();
            }
            else {
                print("La biblioteca esta llena de libros :/ ");
            }
        }
        else if (opcion == "2") {
            if (sistema->getCantidadMateriales() != 0) {
                print(sistema->mostrarBiblioteca());
            }
            else {
                print("La biblioteca no tiene libros disponibles :/ ");
            }
        }
        else if (opcion == "3") {
            opcion3();
        }
        else if (opcion == "4") {
            opcion4();
        }
        else if (opcion == "5") {
            opcion5();
        }
        else if (opcion == "6") {
            print("Cerrando app");
        }
        else {
            print("Opcion invalida, intentelo de nuevo" );
        }
    } while (opcion != "6");
    print("Saliendo del programa...");
}
