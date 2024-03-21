#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
    char digito;
    struct Nodo* renglon; 
    struct Nodo* siguiente;
};

typedef struct Pila{
    struct Nodo* top;
};

struct FILE* leerArchivo() {
    FILE* archivo;

    archivo = fopen("numeros_telefono.txt", "r");

    if(archivo == NULL){
        perror("Error al abrir el archivo");
        return 1;
    }

    return archivo;
};

void pushPila(struct Pila* pila, struct Nodo* elemento) {
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->digito = elemento->digito;
    if (pila->top == NULL) {
        pila->top = nuevoNodo;
    } else {
        nuevoNodo->siguiente = pila->top;
        pila->top = nuevoNodo;
    }
}

void agregarLista(struct Nodo** lista, struct Nodo* data){
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->renglon = data;
    nuevoNodo->siguiente = *lista;
    *lista = nuevoNodo;
}

void agregarDigito(struct Nodo** lista, char digito){
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->renglon = NULL;
    nuevoNodo->siguiente = *lista;
    nuevoNodo->digito = digito;
    *lista = nuevoNodo;
}

int isListaVacia(struct Nodo* lista) {
    return (lista->renglon == NULL);
}

void popSublista(struct Nodo* lista) {
    if (isListaVacia(lista)) {
        printf("Error: La pila está vacía.\n");
        exit(EXIT_FAILURE);
    }
    struct Nodo* temp = lista->siguiente;
    struct Nodo* data = temp->renglon;
    lista->siguiente = temp->siguiente;
    lista->renglon = data;
    free(temp);
}

void popDigito(struct Nodo* renglon) {
    if (renglon->digito == '\0' || renglon->siguiente == NULL) {
        renglon->digito = NULL;
        return;
    }
    struct Nodo* temp = renglon->siguiente; // 3
    char digito = temp->digito; // 3
    renglon->siguiente = temp->siguiente; // 0
    renglon->digito = digito; // 3
    free(temp);
}

void imprimirCaracteres(struct Pila* cabeza){
    struct Nodo* actual = cabeza->top;
    
    while (actual != NULL){
        printf("%c", actual->digito);
        actual = actual->siguiente;
    }
}


void verificarEspacios(struct Pila* cabeza){
    struct Nodo* actual = cabeza->top;
    int contadorEspacios = 0;

    while (actual->siguiente != NULL){
        if(actual->digito == ' '){
            contadorEspacios++;
        }
        actual = actual->siguiente;
    }

    if (contadorEspacios == 0){
        printf("Número válido: \n");
    }else if (contadorEspacios > 1){
        printf("Número inválido: \n");
    }else{
        printf("Número válido: \n");
    }
    imprimirCaracteres(cabeza);
    printf("\n");
}
