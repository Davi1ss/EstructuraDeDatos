#include <stdio.h>
#include <stdlib.h>

typedef struct NodoBinario
{
    void *dato;
    struct NodoBinario *izq;
    struct NodoBinario *der;
} NodoBinario;

void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *));
void imprimirPreOrden(const NodoBinario *raiz, void (*print)(void *));
void imprimirInOrden(const NodoBinario *raiz, void (*print)(void *));
void imprimirPostOrden(const NodoBinario *raiz, void (*print)(void *));
void imprimirNivelOrden(NodoBinario *arbol, void (*print)(void *));
int eliminarNodo(NodoBinario **raiz, void *dato, int (*comparar)(void *, void *));
NodoBinario** BuscarNodo(NodoBinario** raiz, void* dato, int (*comparar)(void*, void*));
NodoBinario** BuscarMinimo(NodoBinario** raiz);

void ingresarElementoArbol(NodoBinario **raiz, void *dato, int (*comparar)(void *, void *))
{
    NodoBinario *nuevo = (NodoBinario *)malloc(sizeof(NodoBinario));
    nuevo->dato = dato;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    ingresarNodo(raiz, nuevo, comparar);
}

void ingresarNodo(NodoBinario **raiz, NodoBinario *nuevo, int (*comparar)(void *, void *))
{
    if (*raiz == NULL)
    {
        *raiz = nuevo;
        return;
    }
    if (comparar((*raiz)->dato, nuevo->dato) < 0)
        ingresarNodo(&((*raiz)->izq), nuevo, comparar);
    else
        ingresarNodo(&((*raiz)->der), nuevo, comparar);
}

void imprimirPreOrden(const NodoBinario *raiz, void (*print)(void *))
{
    if (raiz == NULL)
        return;
    print(raiz->dato);
    imprimirPreOrden(raiz->izq, print);
    imprimirPreOrden(raiz->der, print);
}

void imprimirInOrden(const NodoBinario *raiz, void (*print)(void *))
{
    if (raiz == NULL)
        return;
    imprimirInOrden(raiz->izq, print);
    print(raiz->dato);
    imprimirInOrden(raiz->der, print);
}

void imprimirPostOrden(const NodoBinario *raiz, void (*print)(void *))
{
    if (raiz == NULL)
        return;
    imprimirPostOrden(raiz->izq, print);
    imprimirPostOrden(raiz->der, print);
    print(raiz->dato);
}

void imprimirNivelOrden(NodoBinario *arbol, void (*print)(void *))
{
    if (arbol == NULL)
        return;
    NodoBinario **cola = (NodoBinario **)malloc(sizeof(NodoBinario *));
    int frente = 0, trasero = -1;
    cola[++trasero] = arbol;

    while (frente <= trasero)
    {
        NodoBinario *nodoActual = cola[frente++];
        print(nodoActual->dato);
        if (nodoActual->izq != NULL)
            cola[++trasero] = nodoActual->izq;
        if (nodoActual->der != NULL)
            cola[++trasero] = nodoActual->der;
    }

    free(cola);
}

int eliminarNodo(NodoBinario **raiz, void *dato, int (*comparar)(void *, void *)) {
    // Buscar el nodo a borrar usando cualquier recorrido 
    NodoBinario **nborrar = BuscarNodo(raiz, dato, comparar);

    // Si no se encontró el nodo, regresar 0
    if (!(*nborrar))
        return 0;

    // Caso 1: no tiene hijos el nodo a borrar
    if ((*nborrar)->izq == NULL && (*nborrar)->der == NULL) {
        free(*nborrar);
        *nborrar = NULL;
        return 1;
    }
    // Caso 2: tiene hijo derecho
    else if ((*nborrar)->izq == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->der;
        free(temporal);
        temporal = NULL;
        return 1;
    }
    // Caso 3: tiene hijo izquierdo
    else if ((*nborrar)->der == NULL) {
        NodoBinario *temporal = *nborrar;
        *nborrar = (*nborrar)->izq;
        free(temporal);
        temporal = NULL;
        return 1;
    }
    // Caso 4: tiene ambos hijos
    else {
        // Buscar el nodo con valor mínimo del subárbol derecho al borrar
        NodoBinario **minimo = BuscarMinimo(&((*nborrar)->der));
        (*nborrar)->dato = (*minimo)->dato;
        return eliminarNodo(&((*nborrar)->der), (*minimo)->dato, comparar);
    }
}

NodoBinario** BuscarNodo(NodoBinario** raiz, void* dato, int (*comparar)(void*, void*)) {
    // Comenzamos desde la raíz del árbol
    NodoBinario** actual = raiz;

    // Mientras no lleguemos a un nodo nulo
    while (*actual != NULL) {
        // Comparamos el dato actual con el dato que estamos buscando
        int comparacion = comparar((*actual)->dato, dato);

        // Si encontramos el dato, devolvemos la dirección del puntero al nodo
        if (comparacion == 0) {
            return actual;
        }
        // Si el dato actual es mayor que el dato que buscamos, nos movemos al hijo izquierdo
        else if (comparacion > 0) {
            actual = &((*actual)->izq);
        }
        // Si el dato actual es menor que el dato que buscamos, nos movemos al hijo derecho
        else {
            actual = &((*actual)->der);
        }
    }

    // Si no se encontró el dato, devolvemos un puntero nulo
    return NULL;
}

NodoBinario** BuscarMinimo(NodoBinario** raiz) {
    // Comenzamos desde la raíz del subárbol
    NodoBinario** actual = raiz;

    // Mientras haya hijos izquierdos, seguimos avanzando
    while ((*actual)->izq != NULL) {
        actual = &((*actual)->izq);
    }

    // Devolvemos la dirección del puntero al nodo mínimo
    return actual;
}

// Función para imprimir un entero
void imprimir(void *dato)
{
    printf("%1.2f ", *(float *)dato);
}

int comparar(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

void encontrarMinimo(const NodoBinario *raiz, void (*print)(void *)) {
    if (raiz == NULL) {
        return; 
    }

    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }

    print(raiz->dato);
}

// Función para encontrar el número más grande en un árbol binario
void encontrarMaximo(const NodoBinario *raiz, void (*print)(void *)) {
    if (raiz == NULL) {
        return;
    }
    while (raiz->der != NULL) {
        raiz = raiz->der;
    }

    print(raiz->dato);
}