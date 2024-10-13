#include "Revista.h"
#include <iostream>

//Constructor
Revista::Revista(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string numeroEdicion, std::string tipo, std::string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor, prestado, tipo), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {
    std::cout << "Revista creada" << std::endl;
}
//Metodo para mostrar Informacion de la revista
std::string Revista::mostrarInformacion() {
    return MaterialBibliografico::mostrarInformacion() +
           "Numero de Edicion: " + numeroEdicion + "\n" +
           "Mes de Publicacion: " + mesPublicacion + "\n";
}

//Gets
std::string Revista::getMesPublicacion() const {
    return mesPublicacion;
}
std::string Revista::getNumEdicion() const {
    return numeroEdicion;
}
std::string Revista::getDatosTxt() {
    return MaterialBibliografico::getDatosTxt() + "," + getNumEdicion() + "," + getMesPublicacion();
}
//Sets
void Revista::setMesPublicacion(const std::string& mesPublicacion) {
    this->mesPublicacion = mesPublicacion;
}
