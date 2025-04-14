#ifndef FIFO_H
#define FIFO_H

#include <stdlib.h>
#include <stdio.h>

#define FIFO_SIZE 4
#define size(a,b) (a-b+1)

typedef struct FIFOs{
    int vec[FIFO_SIZE];
    int *cabeza;
    int *cola;
    int elementos;
    void (*imprimir_FIFO)(struct FIFOs *f);    
}fifo_t;

fifo_t inicializar_FIFO(int a);
void imprimir_FIFO(fifo_t *f);
void agregar_valor(fifo_t *f, int a);



#endif