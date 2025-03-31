#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define CANTIDAD (uint8_t) 5
#define DIGITOS (uint8_t) 3
#define TRUE (uint8_t) 1
#define FALSE (uint8_t) 0


uint8_t Es_Valido(char caracter);

int main(){
    int vec[CANTIDAD] = {0};
    int f=0;
    float prom =0;
    char c = '0';
    int num=0; 
    int signo = 1;
    int dig =0; 

    printf("Ingrese %d numeros enteros, signados y de maximo %d digitos que esten separados por coma:\n",CANTIDAD, DIGITOS);
    c = fgetc(stdin);
    while( Es_Valido(c) == TRUE && f < CANTIDAD){
        if (c == '-' ){
            if(dig != 0){
                printf("Ha ingresado un caracter no valido\n*****Fin del Programa*****\n");
                return 1;
                }
            else{
                signo = -1;
                c = fgetc(stdin);
            }
            
        }
        if(c != '-' && c!= ','){
            num = 10*num + (c-'0');
            c = fgetc(stdin);
            dig++;
        }
        if (c == ','){
            vec[f] = signo*num;
            if (vec[f] > pow(10,DIGITOS)-1 || vec[f] < -(pow(10,DIGITOS) -1)){
                printf("%d ha excedido la cantidad de %d digitos admitidos\n*******Fin del programa*******\n",vec[f],DIGITOS);
                return 1;
            }
            signo = 1;
            num = 0;
            f++;
            dig = 0;
            c = fgetc(stdin);
        }
    }
    if(c == ','){
        printf("Ha intentado ingresar mas de %d valores, solo los primeros %d valores seran tenidos en cuenta\n",CANTIDAD,CANTIDAD);
    }
    if( Es_Valido(c) == FALSE && c!= '\n'){
        printf("Ha ingresado un caracter no valido \nFin del Programa");
        return 1;
    }    
    if( c == '\n'){
        vec[f] = signo*num;
        if (vec[f] > pow(10,DIGITOS)-1 || vec[f] < -(pow(10,DIGITOS) -1)){
            printf("%d ha excedido la cantidad de %d digitos admitidos\n*******Fin del programa*******\n",vec[f],DIGITOS);
            return 1;
        }
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

uint8_t Es_Valido(char c){
    if((c<='9' && c >= '0' )|| c == '-' || c == ','){
        return TRUE;
    }
    else { 
    return FALSE;}
}
