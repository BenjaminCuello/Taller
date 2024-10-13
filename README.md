
# Taller de estructura :
Este proyecto consiste en implementar un sistema de gestión bibliográfica que permite la creación y gestión de objetos como libros, revistas y usuarios.
En los txt, no vienen ningun objeto tipo libro, revista o usuario por defecto, pero siguen esta estructura al guardar o cargar en los txt:
Material bibliografico:
nombreLibro,isbnLibro,Autor,estado(prestado o no),libro,fecha,resumen
nombrerevista,isbn2,autor2,estado(prestado o no),revista,numEdicion,mes
Usuario:
nombreUsuario,idUsuario,0
nombreUsuario,idUsuario,n,isbn1,isbn2,...,isbnN

# Información del equipo de trabajo:
  - Benjamín Ignacio Cuello Cuello
  - RUT: 21.682.135-1
  - Correo institucional: benjamin.cuello@alumnos.ucn.cl
  - Paralelo: C1

Requisitos:

- Compilador C++ (g++)

## Compilación y Ejecución

Para compilar el código:
```bash
g++ main.cpp App.cpp Libro.cpp Revista.cpp Sistema.cpp Usuario.cpp -o PROYECTOS_UCN_C__.exe
