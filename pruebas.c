#include <stdio.h>
#include <stdlib.h>


int main(void){
    int vec[4] = {0};
    int *head,*tail;
    head = &vec[1];
    tail = &vec[3];
    vec[3] = 7;
    printf("indice de la cabeza: %ld \n",-(&vec[0]-head));
    printf("indice de la cola %d \n", vec[tail - &vec[0]]);
    return 0;
}