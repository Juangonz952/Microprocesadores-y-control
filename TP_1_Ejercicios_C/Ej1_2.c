#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CANTIDAD (uint8_t) 5
uint8_t Es_Numero(char caracter);
int main(){
    int vec[CANTIDAD];
    int f=0;
    float prom;
    
    printf("Ingrese %d numeros enteros, signados y de maximo 3 digitos que esten separados por coma: ",CANTIDAD);

    for (int i=0; i<CANTIDAD ;i++){
        if(vec[i]>999 || vec[i]<-999){
            printf("Error: los numeros deben tener maximo 3 digitos\n");
            return 0;
        }
    }
    for(int i=0; i<CANTIDAD; i++){
        prom += vec[i];
    }
    prom = prom/CANTIDAD;
    printf("el promedio es %f\n", prom);
    for(int i=0; i<CANTIDAD; i++){
        for(int j=i+1; j<CANTIDAD; j++){
            if(vec[i]<vec[j]){
                int aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    printf("Los numeros ordenados de menor a mayor son: ");
    for(int i=0; i<CANTIDAD; i++){
        printf("%d ", vec[i]);
    }
    printf("\n");
    return 0;
}

uint8_t Es_Numero(char caracter){
    if(caracter>='0' && caracter<='9' || caracter == '-' || caracter == ','){
        return 1;
    }
    return 0;
}