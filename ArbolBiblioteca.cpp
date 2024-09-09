#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de un libro
typedef struct {
    char titulo[100];
    char autor[100];
    int fechaPublicacion;
} Libro;

// Nodo del �rbol binario
typedef struct Nodo {
    Libro libro;
    struct Nodo *izq;
    struct Nodo *der;
} Nodo;

// Funci�n para crear un nuevo nodo
Nodo* crearNodo(Libro libro) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->libro = libro;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;
    return nuevoNodo;
}

// Funci�n para insertar un libro en el �rbol binario (por t�tulo)
Nodo* insertar(Nodo* raiz, Libro libro) {
    if (raiz == NULL) {
        return crearNodo(libro);
    }

    // Comparar los t�tulos para decidir la inserci�n
    if (strcmp(libro.titulo, raiz->libro.titulo) < 0) {
        raiz->izq = insertar(raiz->izq, libro);
    } else if (strcmp(libro.titulo, raiz->libro.titulo) > 0) {
        raiz->der = insertar(raiz->der, libro);
    }

    return raiz;
}

// Funci�n para buscar un libro por t�tulo
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

// Funci�n para mostrar el �rbol en orden (alfab�tico por t�tulo)
void mostrarEnOrden(Nodo* raiz) {
    if (raiz != NULL) {
        mostrarEnOrden(raiz->izq);
        printf("Titulo: %s, Autor: %s, Fecha de Publicacion: %d\n", raiz->libro.titulo, raiz->libro.autor, raiz->libro.fechaPublicacion);
        mostrarEnOrden(raiz->der);
    }
}

// Funci�n principal
int main() {
    Nodo* raiz = NULL;

    // Crear algunos libros
    Libro libro1 = {"El principito", "Antoine de Saint Exupery", 1943};
    Libro libro2 = {"Cien anios de soledad", "Gabriel Garcia Marquez", 1967};
    Libro libro3 = {"Don Quijote de la Mancha", "Miguel de Cervantes", 1605};

    // Insertar libros en el �rbol
    raiz = insertar(raiz, libro1);
    raiz = insertar(raiz, libro2);
    raiz = insertar(raiz, libro3);

    // Mostrar los libros en orden alfab�tico
    printf("Catalogo de libros:\n");
    mostrarEnOrden(raiz);

    // Buscar un libro por t�tulo
    char tituloBusqueda[100] = "Cien anios de soledad";
    Nodo* resultado = buscar(raiz, tituloBusqueda);
    if (resultado != NULL) {
        printf("\nLibro encontrado: %s, Autor: %s, Fecha de Publicacion: %d\n", resultado->libro.titulo, resultado->libro.autor, resultado->libro.fechaPublicacion);
    } else {
        printf("\nLibro no encontrado\n");
    }

    return 0;
}

