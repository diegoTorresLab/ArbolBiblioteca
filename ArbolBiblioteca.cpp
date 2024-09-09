#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de un libro
typedef struct {
    char titulo[100];
    char autor[100];
    int fechaPublicacion;
} Libro;

// Nodo del árbol binario
typedef struct Nodo {
    Libro libro;
    struct Nodo *izq;
    struct Nodo *der;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(Libro libro) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->libro = libro;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

// Función para insertar un libro en el árbol binario (por título)
Nodo* insertar(Nodo* raiz, Libro libro) {
    if (raiz == NULL) {
        return crearNodo(libro);
    }

    // Comparar los títulos para decidir la inserción
    if (strcmp(libro.titulo, raiz->libro.titulo) < 0) {
        raiz->izq = insertar(raiz->izq, libro);
    } else if (strcmp(libro.titulo, raiz->libro.titulo) > 0) {
        raiz->der = insertar(raiz->der, libro);
    }

    return raiz;
}

// Función para buscar un libro por título
Nodo* buscar(Nodo* raiz, char* titulo) {
    if (raiz == NULL || strcmp(raiz->libro.titulo, titulo) == 0) {
        return raiz;
    }

    if (strcmp(titulo, raiz->libro.titulo) < 0) {
        return buscar(raiz->izq, titulo);
    } else {
        return buscar(raiz->der, titulo);
    }
}

// Función para mostrar el árbol en orden (alfabético por título)
void mostrarEnOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarEnOrden(raiz->izq);
        printf("Titulo: %s, Autor: %s, Fecha de Publicacion: %d\n", raiz->libro.titulo, raiz->libro.autor, raiz->libro.fechaPublicacion);
        mostrarEnOrden(raiz->der);
    }
}

// Función principal
int main() {
    Nodo* raiz = NULL;

    // Crear algunos libros
    Libro libro1 = {"El principito", "Antoine de Saint Exupery", 1943};
    Libro libro2 = {"Cien anios de soledad", "Gabriel Garcia Marquez", 1967};
    Libro libro3 = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1605};

    // Insertar libros en el árbol
    raiz = insertar(raiz, libro1);
    raiz = insertar(raiz, libro2);
    raiz = insertar(raiz, libro3);

    // Mostrar los libros en orden alfabético
    printf("Catalogo de libros:\n");
    mostrarEnOrden(raiz);

    // Buscar un libro por título
    char tituloBusqueda[100] = "Cien anios de soledad";
    Nodo* resultado = buscar(raiz, tituloBusqueda);
    if (resultado != NULL) {
        printf("\nLibro encontrado: %s, Autor: %s, Fecha de Publicacion: %d\n", resultado->libro.titulo, resultado->libro.autor, resultado->libro.fechaPublicacion);
    } else {
        printf("\nLibro no encontrado\n");
    }

    return 0;
}

