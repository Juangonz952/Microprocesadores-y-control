#include <stdio.h>
#include <stdlib.h>

int M2D[][5] = {
    {1, 2, 3, 4},
    {5,6, 7, 8},
    {9, 10, 11, 12},
};

int *p0 = M2D[0]; 
int *p1 = M2D[1]; 

int main(void){
    
    printf("S0 = %d\n", p0[4]);
    printf("S1 = %d\n", p1[5]);
    
    return 0;
}