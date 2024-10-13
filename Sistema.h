#ifndef SISTEMA_H
#define SISTEMA_H
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"

// TODO SE IMPLEMENTA EN EL CPP

class Sistema {
private:
    static Sistema* instancia; // instancia
    MaterialBibliografico* biblioteca[100];
    Usuario* usuariosBiblioteca[100];
    int cantidadMateriales;
    int cantUsuarios;
    Sistema(); // constructor

public:
    ~Sistema(); // funcion de destructor
    std::string  agregarLibro(const std::string &nombre, const std::string &isbn, const std::string &autor, const bool &prestado, const std::string &tipo, const std::string &fecha, const std::string &resumen);
    std::string  agregarRevista(const std::string &nombre, const std::string & isbn, const std::string & autor, const bool &prestado, const std::string & tipo, const std::string & numeroEdicion, const std::string & mes_publicacion);
    std::string  buscarMaterialPorTitulo(const std::string & tituloABuscar);
    std::string  buscarMaterialPorAutor(const std::string & autorABuscar);
    bool comprobarId(const std::string &idUsuario);
    std::string  mostrarMateriales();
    int materialesDispoonibles();
    bool verificarIsbn(const std::string & isbn);
    Usuario* buscarYEncontrarUsuarioId(const std::string & idUsuario);
    MaterialBibliografico * buscarYEncontrarMateriaIsbn(const std::string & isbnLibro);
    std::string prestarMaterial(const std::string & isbnLibro, const std::string & id_usuario);
    std::string  registrarUsuario(const std::string & nombre, const std::string & id);
    bool verificarDisponiblidadId(const std::string & id);
    std::string  mostrarDatosUsuario(const std::string & id);
    int devolverPosicionUsuario(const std::string & id);
    std::string  eliminarUsuario(const std::string & id);
    bool comprobarMaterialesPrestados(const std::string & id);
    std::string  mostrarMaterialesPrestados(const std::string & id);
    int obtenerCantMateriales(const std::string & id);
    bool verificarIsbnADevolver(const std::string & isbnADevolver, const std::string & id_usuario);
    std::string  devolverMaterial(const std::string & isbnADevolver, const std::string & id_usuario);
    static Sistema* obtenerInstancia(); // obtener la instancia
    std::string mostrarBiblioteca() const;
    int getCantidadMateriales() const;
    void guardarBiblioteca();
    void cargarBiblioteca();
    void guardarUsuarios();
    void cargarUsuarios();
};






#endif // SISTEMA_H
