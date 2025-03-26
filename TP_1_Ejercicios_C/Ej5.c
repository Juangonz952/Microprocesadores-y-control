#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define CANTIDAD (uint8_t)10
#define BUFFER (uint8_t)20

uint8_t Es_Valido(char c[BUFFER]);

int main(){
    char c[BUFFER] = {0};
    int vec[CANTIDAD] = {0};
    float promedio = 0;
    while(strcmp(c,"EXIT") != 0){
        printf("Ingrese numeros enteros y se calculara el promedio de los ultimos %d numeros ingresados\n", CANTIDAD);
        printf("Para salir ingrese EXIT\n");
        fgets(c, BUFFER, stdin);
        for(int i=0; i<BUFFER; i++){
            if(c[i] == '\n'){
                c[i] = '\0';
            }
        }
        while(Es_Valido(c) == 1){
            printf("Ha ingresado un caracter no valido y no sera tenido en cuenta.\nPor favor vuelva a ingresar valores o EXIT: \n");
            fgets(c,BUFFER,stdin);
            for(int i=0; i<BUFFER; i++){
                if(c[i] == '\n'){
                    c[i] = '\0';
                }
            }
            
        }
        if(Es_Valido(c)== 0){
            for(int i= 0;i < CANTIDAD;i++){
                vec[i] = vec[i+1];
            }
            vec[CANTIDAD] = atoi(c);
            promedio = promedio - (float)vec[0]/CANTIDAD + (float)vec[CANTIDAD]/CANTIDAD;
            printf("El promedio es: %f \n",promedio);
        }

    }
    if(strcmp(c,"EXIT") == 0 ){
        printf("Se ha seleccionado EXIT \n**** Fin del Programa ****");
    }
    return 0;
}

uint8_t Es_Valido(char c[BUFFER]){
    int index;
    for(index = 0; index < BUFFER && c[index] != '\0'; index++){
        if((c[index] < '0' || c[index] > '9') && strcmp(c,"EXIT") !=0 && (c[index] == '-' && index !=0)){
            return (uint8_t) 1;
        }
    }
    return (uint8_t) 0;
}