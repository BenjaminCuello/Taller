#include "MaterialBibliografico.h"
#include <iostream>
#include "MaterialBibliografico.h"

// constructor
MaterialBibliografico::MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string tipo)
    : nombre(nombre), isbn(isbn), autor(autor), prestado(prestado), tipo(tipo) {
}

//Metodo virtual para mostrar la informacion del material
std::string MaterialBibliografico::mostrarInformacion() {
    std::string esPrestado;
    if (prestado) {
        esPrestado = "Si";
    } else {
        esPrestado = "No";
    }
    return "Nombre: " + nombre + "\n" +
           "Autor: " + autor + "\n" +
           "ISBN: " + isbn + "\n" +
            "Tipo: " + tipo + "\n" +
           "Prestado: " + esPrestado + "\n";
}

//gets
std::string MaterialBibliografico::getNombre() const {
    return nombre;
}
std::string MaterialBibliografico::getIsbn() const {
    return isbn;
}
std::string MaterialBibliografico::getAutor() const {
    return autor;
}
bool MaterialBibliografico::getPrestado() const {
    return prestado;
}
std::string MaterialBibliografico::getTipo() const {
    return tipo;
}
std::string MaterialBibliografico::getPrestadoString() const {
    if (prestado == true) {
        return "Prestado";
    }
    else if (prestado == false) {
        return "No Prestado";
    }
    else {
        return "Error";
    }
}
std::string MaterialBibliografico::getDatosTxt() {
    return getNombre() + "," + getIsbn() + "," + getAutor() + "," + getPrestadoString() + "," + getTipo();
}

// sets
void MaterialBibliografico::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}
void MaterialBibliografico::set_isbn(const std::string& isbn) {
    this->isbn = isbn;
}
void MaterialBibliografico::setAutor(const std::string& autor) {
    this->autor = autor;
}
void MaterialBibliografico::setPrestado(bool prestado) {
    this->prestado = prestado;
}

//Destructor
MaterialBibliografico::~MaterialBibliografico() {
}
