#include "Sistema.h"

#include <complex.h>
#include <fstream>
#include <iostream>

// Instancia Estatica (singleton
Sistema* Sistema::instancia = nullptr; // PUNTERO TIPO SISTEMA , que crea variable instancia que pertenece a la clase sistema y es estatica

// Constructor privado
Sistema::Sistema() : cantidadMateriales(0) {
    for (int i = 0; i < 100; ++i) {
        biblioteca[i] = nullptr;
        usuariosBiblioteca[i] = nullptr;
    }
}

//Destructor
Sistema::~Sistema() {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i] != nullptr) {
            delete biblioteca[i];
        }
    }
    std::cout << "Sistema destruido" << std::endl;
}

// Metodo para obtener la instancia
Sistema* Sistema::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new Sistema();
    }
    return instancia;
}

//Metodo para agregar libros a la biblioteca
std::string Sistema::agregarLibro(const std::string &nombre, const std::string &isbn, const std::string &autor, const bool &prestado, const std::string &tipo, const std::string &fecha, const std::string &resumen) {
    Libro* nuevoLibro = new Libro(nombre, isbn, autor, prestado, tipo,  fecha, resumen);
    biblioteca[cantidadMateriales] = nuevoLibro;
    cantidadMateriales++;
    return "Libro '" + nombre + "' agregado a la biblioteca correctamente.";

}

//Metodo para agregar revistas a la biblioteca
std::string Sistema::agregarRevista(const std::string &nombre, const std::string & isbn, const std::string & autor, const bool &prestado, const std::string & tipo, const std::string & numeroEdicion, const std::string & mes_publicacion) {
    Revista* nuevaRevista = new Revista(nombre, isbn, autor, prestado, numeroEdicion,  tipo, mes_publicacion);
    biblioteca[cantidadMateriales] = nuevaRevista;
    cantidadMateriales++;
    return "Revista '" + nombre + "' agregado a la biblioteca correctamente.";

}

//Metodo para mostrar los materiales de la biblioteca
std::string Sistema::mostrarBiblioteca() const {
    std::string resultado = "Materiales registrados en la biblioteca:\n";
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i] != nullptr) {
            resultado += biblioteca[i]->mostrarInformacion() + "\n";
        }
    }
    return resultado;
}

//Metodo para buscar material por titulo
std::string  Sistema::buscarMaterialPorTitulo(const std::string & tituloABuscar) {
    std::string resultado = "";
    bool encontrado = false;
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getNombre() == tituloABuscar) {
            resultado += "El Material fue encontrado:\n " + biblioteca[i]->mostrarInformacion();
            encontrado = true;
        }
    }
    if (encontrado == true) {
        return resultado;
    }
    return "El material no fue encontrado, revise que este bien escrito";
}

//Metodo para buscar material por autor
std::string  Sistema::buscarMaterialPorAutor(const std::string & autorABuscar) {
    std::string resultado = "";
    bool encontrado = false;
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getAutor() == autorABuscar) {
            resultado += "El Material fue encontrado:\n " + biblioteca[i]->mostrarInformacion();
            encontrado = true;
        }
    }
    if (encontrado == true) {
        return resultado;
    }
    return "El material no fue encontrado, revise que este bien escrito";
}

//Metodo para comprobar que el id exista en el sistema
bool Sistema::comprobarId(const std::string &idUsuario) {
    for (int i = 0; i < cantUsuarios; ++i) {
        if (idUsuario == usuariosBiblioteca[i]->getId()) {
            return true;
        }
    }
    return false;
}

//Metodo para mostrar los materiales disponibles (no prestados)
int Sistema::materialesDispoonibles() {
    int materialesNoPrestados = 0;
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getPrestado() == false) {
            materialesNoPrestados +=1;
        }
    }
    return materialesNoPrestados;
}

//Metodo para mostrar los materiales
std::string Sistema::mostrarMateriales() {
    std::string resultado = "";
    for (int i = 0; i < cantidadMateriales; ++i) {
        resultado += "- Isbn: " + biblioteca[i]->getIsbn() +  biblioteca[i]->getNombre() + "del autor " + biblioteca[i]->getAutor() + "\n";
    }
    return resultado;

}

//Metodo para verificar el isbn en la biblioteca
bool Sistema::verificarIsbn(const std::string &isbn) {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getIsbn() == isbn) {
            return true;
        }
    }
    return false;
}

//Metodo para prestar un material
std::string Sistema::prestarMaterial(const std::string &isbnLibro, const std::string &id_usuario) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id_usuario);
    MaterialBibliografico* materialAPrestar = buscarYEncontrarMateriaIsbn(isbnLibro);
    if (usuarioIngresado == nullptr || materialAPrestar == nullptr) {
        return "A ocurrido un error en la busqueda de usuario o al buscar el material :C";
    }
    if (usuarioIngresado->getnumPrestados() >= 5) {
        return "El usuario no puede pedir prestado mas de 5 materiales";
    }
    return usuarioIngresado->prestarMaterial(materialAPrestar);
}

//Metodo para buscar y encontrar un usuario con el id
Usuario* Sistema::buscarYEncontrarUsuarioId(const std::string &idUsuario) {
    for (int i = 0; i < cantUsuarios; ++i) {
        if (idUsuario == usuariosBiblioteca[i]->getId()) {
            return usuariosBiblioteca[i];
        }
    }
    return nullptr;

}

//Metodo para buscar y encontrar un material con el Isbn
MaterialBibliografico *Sistema::buscarYEncontrarMateriaIsbn(const std::string &isbnLibro) {
    for (int i = 0; i < cantidadMateriales; ++i) {
        if (biblioteca[i]->getIsbn() == isbnLibro) {
            return biblioteca[i];
        }
    }
    return nullptr;
}

//Metodo para registrar un usuario
std::string Sistema::registrarUsuario(const std::string &nombre, const std::string &id ) {
    if (cantUsuarios< 100) {
        Usuario* usuarioNuevo = new Usuario(nombre, id);
        usuariosBiblioteca[cantUsuarios] = usuarioNuevo;
        cantUsuarios++;
        return "Usuario '" + nombre + "' agregado al sistema correctamente.";
    }
    else {
        return "Lo sentimos, no hay mas capacidad en el sistema para mas usuarios";
    }
}

//Metodo para verificar la disponibilidad de id
bool Sistema::verificarDisponiblidadId(const std::string &id) {
    for (int i = 0; i < cantUsuarios; ++i) {
        if (usuariosBiblioteca[i]->getId() == id) {
            return false;
        }
    }
    return true;
}

//Metodo para mostrar datos del usuario
std::string Sistema::mostrarDatosUsuario(const std::string &id) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id);
    return usuarioIngresado->mostarDatos();

}

//Metodo para eliminar un usuario
std::string Sistema::eliminarUsuario(const std::string &id) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id);
    int posicionUsuario = devolverPosicionUsuario(id);
    if (usuarioIngresado->getnumPrestados() != 0) {
        return "El usuario no se puede eliminar, le falta devolver libros";
    }
    else {
        delete usuarioIngresado;
        for (int j = posicionUsuario; j < cantUsuarios - 1; ++j) {
            usuariosBiblioteca[j] = usuariosBiblioteca[j + 1];
        }
        cantUsuarios--;
        return "Usuario eliminado correctamente.";
    }
}

//Metodo para que devuelva la posicion del usuario
int Sistema::devolverPosicionUsuario(const std::string &id) {
    for (int i = 0; i < cantUsuarios; ++i) {
            if (id == usuariosBiblioteca[i]->getId()) {
                return i;
            }
    }
    return 0;


}

//Metodo para comprobar los materiales prestados por un usuario
bool Sistema::comprobarMaterialesPrestados(const std::string &id) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id);
    if (usuarioIngresado->getnumPrestados() > 0) {
        return true;
    }
    return false;
}

//Metodo para mostrar los materiales prestados por el usuario
std::string Sistema::mostrarMaterialesPrestados(const std::string &id) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id);
    return usuarioIngresado->mostrarMaterialesDeUsuario();
}

//Metodo para obtener la cantidad de materiales prestados por el usuario
int Sistema::obtenerCantMateriales(const std::string &id) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id);
    return usuarioIngresado->getnumPrestados();
}

//Metodo para verificar el isbn del material a devolver
bool Sistema::verificarIsbnADevolver(const std::string &isbnADevolver, const std::string &id_usuario) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id_usuario);
    if (usuarioIngresado->comprobarIsbnMaterial(isbnADevolver)) {
        return true;
    }
    return false;
}

//Metodo para devolver el material
std::string Sistema::devolverMaterial(const std::string &isbnADevolver, const std::string &id_usuario) {
    Usuario* usuarioIngresado = buscarYEncontrarUsuarioId(id_usuario);
    MaterialBibliografico* materialADevolver = buscarYEncontrarMateriaIsbn(isbnADevolver);
    if (usuarioIngresado == nullptr || materialADevolver == nullptr) {
        return "A ocurrido un error en la busqueda de usuario o al buscar el material :C";
    }
    return usuarioIngresado->devolverMaterial(materialADevolver);
}

//Metodo para guardar datos en txt
void Sistema::guardarBiblioteca() {
    std::ofstream archivo("biblioteca.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < cantidadMateriales; ++i) {
            if (biblioteca[i] != nullptr) {
                    archivo << biblioteca[i]->getDatosTxt() << "\n";
            }
        }
        archivo.close();
    } else {
    }
}

//Metodo para cargar datos en txt
void Sistema::cargarBiblioteca() {
    std::ifstream archivo("biblioteca.txt");
    if (archivo.is_open()) {
        std::string linea;

        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string nombre, isbn, autor, prestado, tipo;
            std::getline(iss, nombre, ',');
            std::getline(iss, isbn, ',');
            std::getline(iss, autor, ',');
            std::getline(iss, prestado, ',');
            std::getline(iss, tipo, ',');
            bool prestadoMaterial = false;
            if (prestado == "Prestado") {
                prestadoMaterial = true;
            }
            if (prestado == "No Prestado") {
                prestadoMaterial = false;
            }
            if (tipo == "libro") {
                std::string fechaPublicacion, resumen;
                std::getline(iss, fechaPublicacion, ',');
                std::getline(iss, resumen, ',');

                agregarLibro(nombre, isbn, autor,prestadoMaterial, tipo, fechaPublicacion, resumen);
            } else if (tipo == "revista") {
                std::string numeroEdicion, mesPublicacion;
                std::getline(iss, numeroEdicion, ',');
                std::getline(iss, mesPublicacion, ',');
                agregarRevista(nombre, isbn, autor,prestadoMaterial, tipo, numeroEdicion, mesPublicacion);
            }
        }
        archivo.close();
    } else {

    }
}

//Metodo para cargar usuarios en txt
void Sistema::cargarUsuarios() {
    std::ifstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::istringstream iss(linea);
            std::string nombre, id, numPrestadoString;
            std::getline(iss, nombre, ',');
            std::getline(iss, id, ',');
            std::getline(iss, numPrestadoString, ',');
            int numPrestados = numPrestadoString[0] - '0';


            registrarUsuario(nombre, id);


            Usuario* usuario = buscarYEncontrarUsuarioId(id);
            for (int i = 0; i < numPrestados; ++i) {
                std::string isbnMaterial;
                std::getline(iss, isbnMaterial, ',');

                MaterialBibliografico* material = buscarYEncontrarMateriaIsbn(isbnMaterial);
                if (material != nullptr) {
                    usuario->prestarMaterial(material);
                }
            }
        }
        archivo.close();
    }
}

//Metodo para guardar usuarios en txt
void Sistema::guardarUsuarios() {
    std::ofstream archivo("usuarios.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < cantUsuarios; ++i) {
            if (usuariosBiblioteca[i] != nullptr) {
                std::cout << usuariosBiblioteca[i]->getnumPrestados()<< std::endl;
                archivo << usuariosBiblioteca[i]->getDatosTxt() << "\n";
            }
        }
        archivo.close();
    }
}

//gets
int Sistema::getCantidadMateriales() const {
    return cantidadMateriales;
}