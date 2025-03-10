#include <stdio.h>

int main(){
    int vec[5];
    int f=0;
    float prom;
    scanf("%d,%d,%d,%d,%d,%d", &vec[0], &vec[1], &vec[2], &vec[3], &vec[4], &f);
    if(f != 0){
        printf("Error: la cantidad de numeros ingresados es incorrecta (maximo 5 numeros) \n");
        return 0;
    }
    if(vec[0]>999 || vec[0]<-999 || vec[1]>999 || vec[1]<-999 || vec[2]>999 || vec[2]<-999 || vec[3]>999 || vec[3]<-999 || vec[4]>999 || vec[5]<-999){
        printf("Error: los numeros deben tener maximo 3 digitos\n");
        return 0;
    }
    
    prom = prom/5;
    printf("%f\n", prom);
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(vec[i]<vec[j]){
                int aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    for(int i=0; i<5; i++){
        printf("%d\n", vec[i]);
    }
    return 0;
}