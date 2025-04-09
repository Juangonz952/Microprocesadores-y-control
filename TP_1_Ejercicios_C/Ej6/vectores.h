#ifndef VECTORES_H
#define VECTORES_H


#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define SUMA 1
#define RESTA -1


typedef struct vector_s{
    int x;
    int y;
    int z;
    double (*norma)(int x, int y, int z);      
}vector_t;

vector_t inicializar_vector(int x,int y,int z);
void imprimir_vector(vector_t *v);
/* prototipos */
double norma_2(vector_t *vec);
vector_t Adicion(vector_t *vec1,int suma_o_resta, vector_t *vec2);
int Producto_Interno(vector_t *v1, vector_t *v2);
vector_t Producto_Externo(vector_t *v1,vector_t *v2);
/* funciones */

#endif /* VECTORES_H */