#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones/funciones.h"

int main() {
    struct Nodo* lista = NULL;

    FILE *archivo = leerArchivo();
    char renglon[20];

    while(fgets(renglon, sizeof(renglon), archivo) != NULL){  
        struct Nodo* sublista = NULL;
        for (int i = 0; renglon[i] != '\0'; i++) {
            agregarDigito(&sublista, renglon[i]);
        }
        agregarLista(&lista, sublista);
    }

    while (lista->siguiente != NULL)
    {
        struct Pila* nuevaPila = (struct Pila*)malloc(sizeof(struct Pila));
        while (lista->renglon->digito != NULL)
        {
            pushPila(nuevaPila, lista->renglon);            
            popDigito(lista->renglon);
        }
        verificarEspacios(nuevaPila);
        popSublista(lista);
    }   

    fclose(archivo);
    return 0;
}

/*  -como primer paso debo de usar cada linea del archivo.txt en una lista enlazada.
    -luego cada lista enlazada de una por una la voy agregar en la pila.
    -Despues tengo que hacer pop en cada lista enlazada y verificar si el numero ingresado en la linea es valido o invalido.
    -Si el numero de telefono no tiene espacios(123-456-7891) el numero de telefono es valido.
    -Si el numero de telefono tiene 1 espacio((123) 456-7891) el numero de telefono es valido.
    -Pero si el numero de telefono tiene 2 o mas espacios(111 111 1111) el numero de telefono es invalido.*/
