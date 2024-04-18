#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main() {
    struct Cola miCola;
    struct Cola colaEspera;
    int conta = 0;
    int n = 0;

    // Inicializar la cola
    inicializarCola(&miCola);
    inicializarCola(&colaEspera);

    // Insertar elementos
    agregar(&miCola, 'A');
    printf("Ejecutando: ");
    imprimirCola(&miCola);
    
    for(int i=0; i<=30; i++){
        
        agregar(&colaEspera, 'A'+i);
        printf("Ejecutando: ");
        imprimirCola(&colaEspera);
        
        conta+=1;
        
        if(conta==10){
            
            n+=1;
            
            agregar(&miCola, 'A'+n);
            
            conta = 0;
        }
    }

    // la cola antes de eliminar nodos
    printf("Contenido en cola de ejecucion: ");
    imprimirCola(&miCola);
    
    printf("Contenido de la cola de espera: ");
    imprimirCola(&colaEspera);

    // sacar nodos de la cola
    eliminar(&miCola);

    // Imprimir la cola
    printf("Contenido de la cola después de desencolar: ");
    imprimirCola(&miCola);

    // Liberar la memoria
    liberarCola(&miCola);

    return 0;
}
