#include <stdio.h>
#include <stdint.h> 
#include <string.h>
#include <stdlib.h>

int Es_Valido(char c[20]){
    int index;
    for(index = 0; index < 20 && c[index] != '\0'; index++){
        if(c[index] < '0' || c[index] > '9'){
            return 1;
        }
    }
    return 0;
}
int main(){
    char c[20];
    int a;
    fgets(c, 20, stdin);
    for(int i=0; i<20; i++){
        if(c[i] == '\n'){
            c[i] = '\0';
        }
    }
    for(int i= 0; i <20; i++){
        if( c[i]<'0' || c[i] > '9'){
            printf("no ingreso un numero");
            break;
        }
    }
    printf("%d",Es_Valido(c));
    printf("%s", c);
    if(strcmp(c,"EXIT") == 0){
        printf("Se ingreso EXIT\n");
    }
    else{
        printf("No se ingreso EXIT\n");
    }
    a = atoi(c);
    printf("%d\n", a);
    return 0;
}