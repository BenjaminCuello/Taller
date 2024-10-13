//
// Created by Cuello on 18-09-2024.
//

#ifndef REVISTA_H
#define REVISTA_H
#include <string>

#include "MaterialBibliografico.h"


class Revista : public MaterialBibliografico{
private:
    std::string numeroEdicion;
    std::string mesPublicacion;

public:
    Revista(std::string nombre, std::string isbn, std::string autor,bool prestado, std::string numeroEdicion, std::string tipo, std::string mesPublicacion );
    std::string mostrarInformacion() override;
    std::string getMesPublicacion() const;
    std::string getNumEdicion() const;
    std::string getDatosTxt() override;
    void setMesPublicacion(const std::string& mesPublicacion);
};

#endif //REVISTA_H
