#include "Fifo.h"


fifo_t inicializar_FIFO(int a){
    fifo_t f;
    f.vec[0] = a;
    f.cabeza = &f.vec[0];
    f.cola = f.cabeza;
    f.elementos = size(f.cabeza,f.cola);
    return f;
} 

void imprimir_FIFO(fifo_t *f){
    printf("Cola FIFO de %d elementos: ",f->elementos);
    for(int i=0;i<f->elementos;i++){
        printf(" %d", f->vec[i]); 
    }
    printf("\n");
    printf("El valor cabeza es %d y se encuentra en la posicion %d",*f->cabeza,f->cabeza);
    printf("\n");
    printf("El valor cola es %d y se encuentra en la posicion %d",*f->cola,f->cola);
}

void agregar_valor(fifo_t *f,int a){
    int *aux;
    if (f->elementos >= FIFO_SIZE){
        printf("Cola llena, tenes que eliminar un valor antes de agregar uno nuevo");
        return;
    }
    else{
        if(f->cola +4 <= &(f->vec[3])){
            f->vec[f->cola - &(f->vec[0])] = a;
            f->cola +=4;
            f->cola = &(f->vec[f->cola + 4 - &(f->vec[0])]);
        }
        else{
            f->vec[0] = a;
            f->cola = &f->vec[0];
        }
    }

}