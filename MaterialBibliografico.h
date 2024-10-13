#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>

class MaterialBibliografico {
private:
    std::string nombre;
    std::string isbn;
    std::string autor;
    std::string tipo;
    bool prestado;

public:
    MaterialBibliografico(std::string nombre, std::string isbn, std::string autor, bool prestado, std::string tipo);
    virtual std::string mostrarInformacion();
    virtual ~MaterialBibliografico();
    std::string getNombre() const;
    std::string getIsbn() const;
    std::string getAutor() const;
    bool getPrestado() const;
    std::string getTipo() const;
    std::string getPrestadoString() const;
    void setNombre(const std::string& nombre); // EL & ES PARA QUE NO SE CREE OTRA VARIABLE, ES DECIR NO OCUPE MAS MEMORIA
    void set_isbn(const std::string& isbn); // ASI SE TRABAJA CON LA VARIABLE ORIGINAL, SIN CREAR OTRA CON OTRO NOMBRE
    void setAutor(const std::string& autor);
    void setPrestado(bool prestado); // Aqui no se usa &, porque el bool no es tan grande como los strings, que pueden ocipar micho espacio
    virtual std::string getDatosTxt();
};

#endif //MATERIALBIBLIOGRAFICO_H
