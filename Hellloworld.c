#include <stdio.h>
int main() {
    int vector[5] = {0,0,0,0,0};
    int vec_pos[4];
    char secuencia[25];
    int j = 0;
    int tamaño;
    int inicio = 0;
    int fin = 0;
    printf("Introdusca la secuencia de numeros espaciados por una coma de maximo 3 digitos y signados: ");   
    scanf("%s", secuencia);
    for(int i = 0; i < 25; i++) {
        if(secuencia[i] == ',') {
            vec_pos[j] = i;
            printf("vec_pos[%d]: %d\n", j, vec_pos[j]);
            j++;
        }
    }
    
    fin = vec_pos[0];
    tamaño = fin - inicio;
    printf("tamaño: %d\n", tamaño);
    for(int k=0; k<5; k++){
        for(int i = fin; i-tamaño>=inicio; i--) {
            if (secuencia[i] == '-'){
                vector[k]*=-1;
            }
            if(secuencia[i] != '-'){
                printf("secuencia[%d]: %d\n", i, secuencia[i]-'0');
                vector[k] += (secuencia[i]-'0')*10^(fin-i);
            }
            
        }
        inicio = vec_pos[k];
        fin = vec_pos[k+1];
        printf("vector[%d]: %d\n", k, vector[k]);
        tamaño = fin - inicio;
        printf("tamaño: %d\n", tamaño);
    }
    for(int i = 0; i<5; i++){
        printf("%d\n", vector[i]);
    }
    return 0;
}