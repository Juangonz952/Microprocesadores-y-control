#include "Fifo.h"

#define size(a,b) (a-b+1)

int main(void){
    int a=1;
    fifo_t f;
    f = inicializar_FIFO(a);
    imprimir_FIFO(&f);
    agregar_valor(&f,3);
    imprimir_FIFO(&f);
    return 0;
}