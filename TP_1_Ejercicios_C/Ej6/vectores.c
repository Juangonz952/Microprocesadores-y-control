/* Creo una libreria de vectores */

/* librerias */

#include <math.h>

/* defino la dimension de los vectores */
#define DIM unsigned int 3

/* Defino tipo de datos */
typedef struct vector_t{
    int x;
    int y;
    int z;
    double (*norma_2) (int x, int y, int z);
}vector_t;

/* prototipos */
double norma_2(int x, int y, int z);

/* funciones */

double norma_2(int x, int y, int z){
    return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}