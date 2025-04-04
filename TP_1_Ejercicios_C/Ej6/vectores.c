/* Creo una libreria de vectores */

/* librerias */
#include "vectores.h"
#include <math.h>
#include <stdio.h>


/* funciones */
double norma_2(vector_t *vec){
    return sqrt(pow(vec->x,2) + pow(vec->y,2) + pow(vec->z,2));
}
vector_t Adicion(vector_t *vec1, vector_t *vec2, int suma_o_resta){
    vector_t vec_resultado;
    vec_resultado.x = vec1->x + (vec2->x)*(suma_o_resta);
    vec_resultado.y = vec1->y + (vec2->y)*(suma_o_resta);
    vec_resultado.z = vec1->z + (vec2->z)*(suma_o_resta);
    return vec_resultado;
}

int Producto_Interno(vector_t *v1, vector_t *v2){
    return (v1->x)*(v2->x) + (v2->y)*(v1->y) + (v1->z)*(v2->z);
}

vector_t Producto_Externo(vector_t *v1,vector_t *v2){
    vector_t vec_resultante;
    vec_resultante.x = (v1->y)*(v2->z) - (v1->z)*(v2->y);
    vec_resultante.y = (v1->x)*(v2->z) - (v1->z)*(v2->x);
    vec_resultante.z = (v1->x)*(v2->y) - (v2->x)*(v1->y);
    return vec_resultante;
}


