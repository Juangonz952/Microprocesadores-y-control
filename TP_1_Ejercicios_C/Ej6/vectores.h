#ifndef VECTORES_H
#define VECTORES_H

#include "vectores.c"
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


typedef struct vector_t{
    int x;
    int y;
    int z;    
}vector_t;


operaciones_t operaciones = {
    .norma_2 = norma_2,
    .Adicion = Adicion,
    .Producto_Interno = Producto_Interno,
    .Producto_Externo = Producto_Externo
};

typedef struct{
    double (*norma_2) (vector_t	*v1);
    vector_t (*Adicion) (vector_t *v1, vector_t *v2,int suma_o_resta);
    int (*Producto_Interno) (vector_t *v1, vector_t *v2);
    vector_t (*Producto_Externo) (vector_t *v1,vector_t *v2);
}operaciones_t;


/* prototipos */
double norma_2(vector_t *vec);
vector_t Adicion(vector_t *vec1, vector_t *vec2,int suma_o_resta);
int Producto_Interno(vector_t *v1, vector_t *v2);
vector_t Producto_Externo(vector_t *v1,vector_t *v2);
/* funciones */

#endif /* VECTORES_H */