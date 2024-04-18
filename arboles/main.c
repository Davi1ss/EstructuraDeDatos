#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    NodoBinario *arbol = NULL;

    float numeros[10];
    
    for (int i = 0; i < 10; i++)
    {
        numeros[i] = 1 + (rand()/(float)(RAND_MAX))*(20-1);
        ingresarElementoArbol(&arbol, &numeros[i], comparar);
    }

    printf("El numero mas chico es: ");
    encontrarMinimo(arbol, imprimir);
    printf("\n");

    printf("El numero mas grande es: ");
    encontrarMaximo(arbol, imprimir);
    printf("\n");

    printf("El Recorrido en Preorden es: ");
    imprimirPreOrden(arbol, imprimir);
    printf("\n");

    printf("El Recorrido en Inorden es: ");
    imprimirInOrden(arbol, imprimir);
    printf("\n");

    printf("El Recorrido en Postorden es: ");
    imprimirPostOrden(arbol, imprimir);
    printf("\n");

    printf("El Recorrido en Nivelorden es: ");
    imprimirNivelOrden(arbol, imprimir);
    printf("\n");

    return 0;
}
