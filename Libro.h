//
// Created by Cuello on 18-09-2024.
//

#ifndef LIBRO_H
#define LIBRO_H
#include "MaterialBibliografico.h"


class Libro : public MaterialBibliografico{
private:
    std::string fechaPublicacion;
    std::string resumen;
public:

    Libro(std::string nombre, std::string isbn, std::string autor,bool prestado,std::string tipo, std::string fechaPublicacion, std::string resumen);

    std::string mostrarInformacion() override;

    //gets
    std::string getFechaPublicacion() const;
    std::string getResumen() const;
    std::string getDatosTxt() override;

    // set
    void setFechaPublicacion(const std::string& fechaPublicacion);
    void setResumen(const std::string& resumen);
};

#endif //LIBRO_H
