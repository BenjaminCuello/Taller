#include "Usuario.h"
#include <iostream>

// constructor
Usuario::Usuario(std::string nombre, std::string id)
    : nombre(nombre), id(id), numPrestados(0) {
    for (int i = 0; i < 5; ++i) {
        materialesPrestados[i] = nullptr;
    }
}

//destructor
Usuario::~Usuario() {
    for (int i = 0; i < 5; ++i) {
        if (materialesPrestados[i] != nullptr) {
            delete materialesPrestados[i];
        }
    }
}

//Metodo para prestar un material
std::string Usuario::prestarMaterial(MaterialBibliografico* material) {
    materialesPrestados[numPrestados] = material;
    numPrestados++;
    material->setPrestado(true);
    return "El Usuario " + this->nombre + "pidio prestado un libro, lleva " + std::to_string(this->numPrestados) + "materiales prestados";
}

//Metodo para devolver un material
std::string Usuario::devolverMaterial(MaterialBibliografico *material) {
    int posicionMaterial = buscarMaterial(material);
    std::cout << posicionMaterial << std::endl;
    for (int i = 0; i < numPrestados; ++i) {
        std::cout << material->getIsbn() << std::endl;
        if (materialesPrestados[i] == material) {
            std::cout << materialesPrestados[i]<< std::endl;
            for (int j = posicionMaterial; j < numPrestados - 1; ++j) {
                std::cout << "se ejcuta for"<< std::endl;
                materialesPrestados[j] = materialesPrestados[j + 1];
            }
            materialesPrestados[i] = nullptr;
            numPrestados--;
            material->setPrestado(false);

            return "El material fue devuelto correctamente, gracias :D";
        }
    }
    return "Ocurrio un error, no se pudo devolver el material";
}

//Metodo para mostrar la informacion de los materiales prestados
std::string Usuario::mostrarMaterialesPrestados() {
    std::string resultado = "Materiales prestados:\n";
    for (int i = 0; i < numPrestados; ++i) {
        if (materialesPrestados[i] != nullptr) {
            resultado += materialesPrestados[i]->mostrarInformacion() + "\n";
        }
    }
    return resultado;
}

//Metodo para mostrar los datos del usuario
std::string Usuario::mostarDatos() {
    if (numPrestados == 0) {
        return "Nombre: " + nombre + "\n" +
              "ID: " + id + "\n" +
              "Cant de libros prestados: " + std::to_string(numPrestados) + "\n" ;
    }
    else {
        return "Nombre: " + nombre + "\n" +
               "ID: " + id + "\n" +
               "Cant de libros prestados: " + std::to_string(numPrestados) + "\n" +
                "Libros Prestados: " + mostrarMaterialesPrestados()+ "\n" ;
    }

}

//Metodo para mostrar los materiales prestados del usuario
std::string Usuario::mostrarMaterialesDeUsuario() {
    std::string resultado = "Materiales prestados:\n";
    for (int i = 0; i < numPrestados; ++i) {
        if (materialesPrestados[i] != nullptr) {
            resultado += std::to_string(i+1) + ") " +  materialesPrestados[i] ->getNombre() + " " + materialesPrestados[i] ->getIsbn() + "\n";
        }
    }
    return resultado;
}

//Metodo para comprobar el isbn del material
bool Usuario::comprobarIsbnMaterial(const std::string &isbnAComprobar) {
    for (int i = 0; i < numPrestados; ++i) {
        if (materialesPrestados[i]->getIsbn() == isbnAComprobar) {
            return true;
        }
    }
    return false;
}

//Metodo para buscar un material prestado
int Usuario::buscarMaterial(MaterialBibliografico *material) {
    for (int i = 0; i < numPrestados; ++i) {
        if (materialesPrestados[i] == material) {
            return i;
        }
    }
    return -1;
}


//Gets
std::string Usuario::getNombre() const {
    return nombre;
}
int Usuario::getnumPrestados() const {
    return numPrestados;
}
std::string Usuario::getId() const {
    return id;
}
std::string Usuario::getDatosTxt() {
    if (numPrestados == 0) {
        return getNombre() + "," + getId() + "," + std::to_string(getnumPrestados());
    }
    return getNombre() + "," + getId() + "," + std::to_string(getnumPrestados()) + getIsbnMateriales();
}
std::string Usuario::getIsbnMateriales() {
    std::string materiales = "";
    for (int i = 0; i < numPrestados; ++i) {
        materiales += "," + materialesPrestados[i]->getIsbn();
    }
    return materiales;
}

//Sets
void Usuario::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}
void Usuario::setId(const std::string& id) {
    this->id = id;
}

