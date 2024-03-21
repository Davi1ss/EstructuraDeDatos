
#include "funciones/funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Crear una lista enlazada simple
    ListaSimple lista;
    lista.head = NULL;
    lista.tail = NULL;
    lista.size = 0;

    // Agregar elementos a la lista
    char dato1[1][10] = {"manzana"};
    char dato2[1][10] = {"naranja"};
    char dato3[1][10] = {"mango"};

    AddTail(&lista, dato1[0]);
    AddTail(&lista, dato2[0]);
    AddHead(&lista, dato3[0]);

    // Imprimir la lista
    printf("Lista después de agregar elementos:\n");
    PrintList(&lista);

    // Eliminar un nodo de la lista
    DeleteNode(&lista, 1);

    // Imprimir la lista después de eliminar un nodo
    printf("\nLista después de eliminar el segundo nodo:\n");
    PrintList(&lista);

    // Insertar un nodo en una posición específica
    char dato4[1][10] = {"banana"};
    InsertAt(&lista, dato4[0], 1);

    // Imprimir la lista después de insertar un nodo en la posición 1
    printf("\nLista después de insertar un nodo en la posición 1:\n");
    PrintList(&lista);

    DestroyList(&lista);

}    
