
#include "vectores.h"


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
    printf("El Producto Externo de los vectores 31231 es: (%d,%d,%d)\n",vec.x,vec.y,vec.z);
    
    return 0;
}