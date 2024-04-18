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

int eliminarNodo (NodoBinario ∗∗raiz, void ∗dato, int (∗comparar)(void∗,void∗))
{
//buscar el nodo a borrar usando cualquier recorrido 
NodoBinario ∗∗ nborrar = BuscarNodo(raiz , dato , comparar);
// si no se encontro el nodo
// regresar0;
/* caso 1, no tiene hijos el nodo a borrar */
// si (∗nborrar)−>izq y (∗nborrar)−>der son nulos
// liberar(∗nborrar)
// hacer nulo (∗nborrar)
// regresar1 ;
/* caso 2, tiene hijo derecho*/
// si(∗nborrar)−>izq es nulo entonces
// crear apuntador NodoBinario temporal e igualarlo a ∗nborrar
// (∗nborrar) es igual a (∗nborrar)−>der
// liberar temporal
// temporal hacer nulo
// regreresa1
/* caso 2, tiene hijo izquierdo */
// si no si (∗nborrar)−>der, es nulo entonces
(∗ nborrar)−>izq
// liberar temporal
// temporal hacer nulo
// regresa1
/* caso 3, tiene ambos hijos*/
// buscar el nodo con valor minimo del sub arbol derecho alborrar
// usando cualquier  recorrido NodoBinario ∗∗minimo = BuscarMinimo ((∗nborra r )−>de r , comparar ) ;
(∗ nborrar)−>dato = (∗ minimo)−>dato;
// intercambiar ligas y eliminar
return eliminarNodo (&(∗nborrar)−>der,(∗minimo)−>dato,comparar) ;
}

char ∗InfixToPostInfix(char ∗expresion) −> char∗ :
//crear copia con malloc o calloc
char ∗ copia = (char ∗) malloc (sizeof ( char)∗ strlen (expresion));
// crear la pila
int c =0;
// para cada token en expresion hacer :
// si token es operando :
// copia [ c ] = token
// incrementa c
// sino si token es ’ ( ’ :
// pushh a pila el token
// sino si token es ’ ) ’ :
// mientras pila no vacia y pila peek no es ’ ( ’ :
// copia [ c ] = pila pop
// incrementa c
// pila pop para saca r ’ ( ’
// si no:
// mientras pila no vacia y Jerarqui a (token , pila peek) es menor o igual:
// copia [ c ] = pila pop
// incrementa c
// hacer push al token
// mientras pila no vacia
//copia [ c ] = pila pop
//incrementa c
return copia;
