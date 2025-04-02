#ifndef VECTORES_H
#define VECTORES_H

#include <math.h>


typedef struct vector_t{
    int x;
    int y;
    int z;
    double (*norma_2) (int x, int y, int z);
}vector_t;


/* prototipos */
static double norma_2(int x, int y, int z);

/* funciones */

static double norma_2(int x, int y, int z){
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}
#endif