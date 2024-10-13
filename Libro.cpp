#include "Libro.h"
#include <iostream>

// Constructor
Libro::Libro(std::string nombre, std::string isbn, std::string autor,bool prestado,std::string tipo, std::string fechaPublicacion, std::string resumen)
    : MaterialBibliografico(nombre, isbn, autor, prestado, tipo), fechaPublicacion(fechaPublicacion), resumen(resumen) {
}

//Metodo para mostrar la informacion del libro
std::string Libro::mostrarInformacion() {
    return MaterialBibliografico::mostrarInformacion() +
           "Fecha de Publicacion: " + fechaPublicacion + "\n" +
           "Resumen: " + resumen + "\n";
}

//gets
std::string Libro::getResumen() const
{
    return this->resumen;
}
std::string Libro::getFechaPublicacion() const
{
    return this->fechaPublicacion;
}
std::string Libro::getDatosTxt() {
    return MaterialBibliografico::getDatosTxt() + "," + getFechaPublicacion() + "," + getResumen();
}

//sets
void Libro::setFechaPublicacion(const std::string& fechaPublicacion) {
    this->fechaPublicacion = fechaPublicacion;
}
void Libro::setResumen(const std::string& resumen) {
    this->resumen = resumen;
}
