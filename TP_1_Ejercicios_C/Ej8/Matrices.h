#ifndef MATRICES_H
#define MATRICES_H

#include <stdio.h>

#define DIM 3

typedef struct Matriz{
    int Matrix[DIM][DIM];
    void (*Imprimir)(struct Matriz *M);
    int (*Traza)(struct Matriz *M);
    int (*Determinante)(struct Matriz *M);
    struct Matriz (*Traspuesta)(struct Matriz *M);
    struct Matriz (*Escalar)(struct Matriz*M,int lambda);
    struct Matriz (*Suma)(struct Matriz*M1,struct Matriz*M2);
    struct Matriz (*Resta)(struct Matriz*M1,struct Matriz *M2);
    struct Matriz (*Multiplicacion)(struct Matriz *M1,struct Matriz *M2);
    struct Matriz(*Potencia)(struct Matriz *M,int pow);
}matriz_t;

matriz_t Inicializar_matriz(int M[DIM][DIM]);



#endif