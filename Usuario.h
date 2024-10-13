//
// Created by Cuello on 18-09-2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include "MaterialBibliografico.h"


class Usuario {
private:
    std::string nombre;
    std::string id;
    MaterialBibliografico* materialesPrestados[5];
    int numPrestados;

public:
    Usuario(std::string nombre, std::string id);
    ~Usuario();
    std::string prestarMaterial(MaterialBibliografico* material);
    int buscarMaterial(MaterialBibliografico * material);
    std::string devolverMaterial(MaterialBibliografico *material);
    std::string mostrarMaterialesPrestados();
    std::string getNombre() const;
    void setNombre(const std::string& nombre);
    int getnumPrestados() const;
    std::string getId() const;
    void setId(const std::string& id);
    std::string mostarDatos();
    std::string mostrarMaterialesDeUsuario();
    bool comprobarIsbnMaterial(const std::string & isbnAComprobar);
    std::string getIsbnMateriales();
    std::string getDatosTxt();
};
#endif //USUARIO_H
