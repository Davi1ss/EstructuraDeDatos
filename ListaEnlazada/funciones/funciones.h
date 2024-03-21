#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo de la lista enlazada simple
typedef struct NodoSimple {
    void *data;
    struct NodoSimple *next;
} NodoSimple;

// Estructura de la lista enlazada simple
typedef struct ListaSimple {
    NodoSimple *head; // Puntero al primer nodo
    NodoSimple *tail; // Puntero al último nodo
    int size; // Tamaño de la lista
} ListaSimple;

void AddTail(ListaSimple *lista, int *dato) {
    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
    nuevo->data = dato;
    nuevo->next = NULL;

    if (lista->tail == NULL) {
        lista->head = nuevo;
        lista->tail = nuevo;
    } else {
        lista->tail->next = nuevo;
        lista->tail = nuevo;
    }

    lista->size++;
}

void AddHead(ListaSimple *lista, void *dato) {
    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
    nuevo->data = dato;
    nuevo->next = lista->head;

    lista->head = nuevo;

    if (lista->tail == NULL) {
        lista->tail = nuevo;
    }

    lista->size++;
}

void InsertAt(ListaSimple *lista, void *dato, int posicion) {
    if (posicion < 0 || posicion > lista->size) {
        printf("Error: La posición está fuera de rango.\n");
        return;
    }

    if (posicion == 0) {
        AddHead(lista, dato);
        return;
    }

    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
    nuevo->data = dato;

    NodoSimple *actual = lista->head;
    for (int i = 0; i < posicion - 1; i++) {
        actual = actual->next;
    }

    nuevo->next = actual->next;
    actual->next = nuevo;

    if (posicion == lista->size) {
        lista->tail = nuevo;
    }

    lista->size++;
}

void DeleteNode(ListaSimple *lista, int posicion) {
    if (posicion < 0 || posicion >= lista->size) {
        printf("Error: La posición está fuera de rango.\n");
        return;
    }

    NodoSimple *eliminar;
    if (posicion == 0) {
        eliminar = lista->head;
        lista->head = lista->head->next;

        if (lista->head == NULL) {
            lista->tail = NULL;
        }
    } else {
        NodoSimple *actual = lista->head;
        for (int i = 0; i < posicion - 1; i++) {
            actual = actual->next;
        }

        eliminar = actual->next;
        actual->next = eliminar->next;

        if (actual->next == NULL) {
            lista->tail = actual;
        }
    }

    free(eliminar);
    lista->size--;
}

void PrintList(ListaSimple *lista) {
    NodoSimple *actual = lista->head;
    while (actual != NULL) {
        printf("%s -> ", actual->data); // Imprimir la dirección de memoria del dato
        actual = actual->next;
    }
    printf("NULL\n");
}

// Función para destruir la lista y liberar la memoria
void DestroyList(ListaSimple *lista) {
    NodoSimple *actual = lista->head;
    while (actual != NULL) {
        NodoSimple *temp = actual;
        actual = actual->next;
        free(temp);
    }

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
}
