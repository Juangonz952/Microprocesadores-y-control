#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define CANTIDAD (uint8_t) 5
#define DIGITOS (uint8_t) 3

uint8_t Es_Numero(char caracter);
uint8_t potencia(uint8_t x,uint8_t n);

int main(){
    int vec[CANTIDAD];
    int f=0;
    float prom;
    char c;
    int num=0; 
    int signo; 

    printf("Ingrese %d numeros enteros, signados y de maximo %d digitos que esten separados por coma:\n ",CANTIDAD, DIGITOS);
    c = fgetc(stdin);
    while(f < CANTIDAD && Es_Numero(c) == (uint8_t) 1){
        if (c !=',' && c != '\n'){
            if (c != '-'){
                num = 10*num + (c - '0');
            }
            if (c == '-'){
                signo = -1;
            }
        }
        if (c == ',' || c == '\n'){
            vec[f] = num*signo;
            if (f > CANTIDAD){
                printf("Superaste la cantidad de numeros requeridos (%d)\nFin de Programa",CANTIDAD);
            }
            if ( vec[f]> potencia(10,DIGITOS) - 1 || vec[f] < -(potencia(10,DIGITOS)-1)){
                printf("Alguno de los numeros esta fuera del rango de %d digitoss \nFin del Programa",DIGITOS);
                return 2;
            }
            num = 0;
            f++;
            signo = 1;
            
            
        }
        
        c = fgetc(stdin);
        }
        
    if (Es_Numero(c) != 1){
        printf("Alguno de los valores introducidos no es un numero \nfin de programa");
        return 1;
    }
    for(int i=0; i<CANTIDAD; i++){
        prom += vec[i];
    }
    prom = prom/CANTIDAD;
    printf("el promedio es %f\n", prom);
    for(int i=0; i<CANTIDAD; i++){
        for(int j=i+1; j<CANTIDAD; j++){
            if(vec[i]>vec[j]){
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

uint8_t Es_Numero(char c){
    if((c<='9' && c >= '0' )|| c == '-' || c == ',' || c == '\n'){
        return (uint8_t) 1;
    }
    else { 
    return (uint8_t) 0;}
}

uint8_t potencia(uint8_t x,uint8_t n){
    uint8_t y=1;
    for(int i=0;i<n;i++){
        y *= x;
    }
    return y;
}
