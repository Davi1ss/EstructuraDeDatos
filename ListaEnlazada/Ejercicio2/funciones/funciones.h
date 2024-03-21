#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Estructura del nodo de la lista enlazada simple
typedef struct NodoSimple {
    char palabra[20]; // Suponemos que cada palabra tiene como máximo 20 caracteres
    struct NodoSimple *next;
} NodoSimple;

// Estructura de la lista enlazada simple
typedef struct ListaSimple {
    NodoSimple *head; // Puntero al primer nodo
    NodoSimple *tail; // Puntero al último nodo
    int size; // Tamaño de la lista
} ListaSimple;

// Función para agregar un nodo al principio de la lista
void AddHead(ListaSimple *lista, char palabra[]) {
    NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));
    strcpy(nuevo->palabra, palabra);
    nuevo->next = lista->head;

    lista->head = nuevo;

    if (lista->tail == NULL) {
        lista->tail = nuevo;
    }

    lista->size++;
}

// Función para imprimir la lista
void PrintList(ListaSimple *lista) {
    NodoSimple *actual = lista->head;
    while (actual != NULL) {
        printf("%s -> ", actual->palabra);
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

void ContarFrecuencia(ListaSimple *lista) {
    NodoSimple *actual = lista->head;
    while (actual != NULL) {
        int frecuencia = 1;
        NodoSimple *siguiente = actual->next;
        while (siguiente != NULL) {
            if (strcmp(actual->palabra, siguiente->palabra) == 0) {
                frecuencia++;
            }
            siguiente = siguiente->next;
        }
        printf("Palabra: %s - Frecuencia: %d\n", actual->palabra, frecuencia);
        actual = actual->next;
    }
}