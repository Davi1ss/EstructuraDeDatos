#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la cola
struct NodoCola{
    char caracter;
    struct NodoCola* siguiente;
};

// Estructura de la cola
struct Cola{
    struct NodoCola* frente;
    struct NodoCola* final;
};

// Función para inicializar una cola vacía
void inicializarCola(struct Cola* cola){
    cola->frente = NULL;
    cola->final = NULL;
}

// Función para encolar un elemento al final de la cola
void agregar(struct Cola* cola, char caracter){
    // Crear un nuevo nodo
    struct NodoCola* nuevoNodo = (struct NodoCola*)malloc(sizeof(struct NodoCola));

    if (nuevoNodo == NULL){
        perror("Error al asignar memoria para el nuevo nodo de la cola");
        exit(EXIT_FAILURE);
    }

    // Configurar los datos del nuevo nodo
    nuevoNodo->caracter = caracter;
    nuevoNodo->siguiente = NULL;

    // Si la cola está vacía, el nuevo nodo se convierte tanto en el frente como en el final
    if (cola->frente == NULL){
        cola->frente = nuevoNodo;
        cola->final = nuevoNodo;
    }else{
        // Enlazar el nuevo nodo al final de la cola y actualizar el puntero al final
        cola->final->siguiente = nuevoNodo;
        cola->final = nuevoNodo;
    }
}

// Función para desencolar el elemento en el frente de la cola
void eliminar(struct Cola* cola){
    if (cola->frente == NULL){
        // La cola está vacía, no se puede desencolar
        printf("La cola está vacía, no se puede desencolar.\n");
        return;
    }

    // Guardar el nodo que se va a desencolar
    struct NodoCola* nodoDesencolado = cola->frente;

    // Actualizar el frente de la cola al siguiente nodo
    cola->frente = nodoDesencolado->siguiente;

    // Si la cola queda vacía, también actualizar el puntero al final
    if (cola->frente == NULL){
        cola->final = NULL;
    }

    // Liberar la memoria del nodo desencolado
    free(nodoDesencolado);
}

// Imprimir los elementos de la cola
void imprimirCola(struct Cola* cola){
    struct NodoCola* actual = cola->frente;

    while (actual != NULL){
        printf("%c ", actual->caracter);
        actual = actual->siguiente;
    }
    

    printf("\n");
}

// Liberar la memoria de la cola
void liberarCola(struct Cola* cola) {
    struct NodoCola* actual = cola->frente;

    while (actual != NULL) {
        struct NodoCola* siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }

    // Reiniciar la cola después de liberar la memoria
    inicializarCola(cola);
}
