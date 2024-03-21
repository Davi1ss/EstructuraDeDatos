
#include "funciones/funciones.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    char palabra[20];
    // Crear una lista enlazada simple
    ListaSimple lista;
    lista.head = NULL;
    lista.tail = NULL;
    lista.size = 0;

    FILE *archivo = fopen("texto.txt", "r");

    while (fscanf(archivo, "%s", palabra) == 1) {
        AddHead(&lista, palabra);
    }

    fclose(archivo);

    // Imprimir la lista
    //printf("Lista después de agregar elementos:\n");
    //PrintList(&lista);

    // Contar la frecuencia de cada palabra y mostrarla
    printf("\nFrecuencia de palabras:\n");
    ContarFrecuencia(&lista);

    DestroyList(&lista);
    


    return 0;
}    
