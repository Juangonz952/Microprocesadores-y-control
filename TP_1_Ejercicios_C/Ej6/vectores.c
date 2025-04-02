/* Creo una libreria de vectores */

/* librerias */

#include <math.h>
#include "vectores.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
/* definiciones */

#define SUMA int 1
#define RESTA int -1 

/* prototipos */
vector_t Adicion(vector_t *vec1, vector_t *vec2,int suma_o_resta);
int Producto_Interno(vector_t *v1, vector_t *v2);
vector_t Producto_Externo(vector_t *v1,vector_t *v2);
/* pruebas*/

int main(){
    vector_t v1,v2,vec; 
    v1.x = 1;
    v1.y =5;
    v1.z = 13;
    v2.x = -5;
    v2.y = 7;
    v2.z = -1;
    vec = Adicion(&v1,&v2,1);
    printf("La suma de los vectores es: (%d,%d,%d)\n",vec.x,vec.y,vec.z);
    printf("Producto Interno %d",Producto_Interno(&v1,&v2));
    vec = Producto_Externo(&v1,&v2);
    printf("La suma de los vectores es: (%d,%d,%d)\n",vec.x,vec.y,vec.z);
    return 0;
}
/* funciones */

vector_t Adicion(vector_t *vec1, vector_t *vec2, int suma_o_resta){
    vector_t vec_resultado;
    vec_resultado.x = vec1->x + (vec2->x)*(suma_o_resta);
    vec_resultado.y = vec1->y + (vec2->y)*(suma_o_resta);
    vec_resultado.z = vec1->z + (vec2->z)*(suma_o_resta);
    vec_resultado.norma_2 = norma_2;
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
    vec_resultante.norma_2 = norma_2;
    return vec_resultante;
}