#include <stdio.h>
#include <string.h>

typedef struct NodoBinario
{
void ∗dato ;
struct NodoBinario ∗izq;
struct NodoBinario ∗der;
}NodoBinario;

void ingresarElementoArbol (NodoBinario ∗∗raiz , void ∗dato , int (∗comparar) (void∗, void∗)){ 
NodoSimple *nuevo = (NodoSimple *)malloc(sizeof(NodoSimple));// crear el nodo nuevo
// asignar el dato de nodo nuevo a el dato a ingresar 
// poner el nodo izquierdo del nodo nuevo en nulo
// poner el nodo derecho del nodo nuevo en nulo
ingresarNodo (raiz, nuevo, comparar);
}

void ingresarNodo (NodoBinario ∗∗raiz, NodoBinario ∗nuevo, int (∗comparar) (void∗ , void∗)){ 
if(raiz==NULL){
// raiz = nuevo  
return;
}
// si comparar ((∗raiz)−>dato , nuevo−>dato ) menor a 0
ingresarNodo (&(∗raiz)−> izq, nuevo, comparar); 
// de lo contrario
ingresarNodo (&(∗raiz)−> der, nuevo, comparar);
}

void imprimirPreOrden (NodoBinario ∗const raiz, void (∗print)(void∗)){
// si raiz es nula
return;
// imprimir dato usando la funcion dada por parametro
// llamar imprimirPreOrden pero con el nodo izquierdo
// llamar imprimirPreOrden pero con el nodo derecho
}

void imprimirInOrden (NodoBinario ∗const raiz, void(∗print)(void∗)){
// si raiz es nula
return;
// llamar imprimirInOrden pero con el nodo izquierdo
// imprimir dato usando la funcion dada por parametro
// llamar imprimirInOrden pero con el nodo derecho
}

void imprimirPostOrden (NodoBinario ∗const raiz, void (∗print)(void ∗)){
// si raiz es nula
return;
// imprimir dato usando la funcion dada por parametro
// llamar imprimirPostOrden pero con el nodo derecho
// llamar imprimirPostOrden pero con el nodo izquierdo
}

void imprimirNivelOrden (NodoBinario ∗const arbol, void (∗print)(void∗))
{
// si arbol == NULO
return;
// crear e inicializar cola auxiliar
// push arbol a cola auxiliar
// mientras cola auxiliar no esta vacia
// pop a cola auxiliar para obtener el nodo
// print (nodo−>data ) usando la funcion del parametro
// si existe nodo−>izq
// push a cola auxiliar nodo−>izq
// si existe nodo−>der
// push a cola auxiliar nodo−>der
}
