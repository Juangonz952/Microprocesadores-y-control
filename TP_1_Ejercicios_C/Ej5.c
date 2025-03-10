#include <stdio.h>

int main(){
    int vec[10] = {0};
    char exit;
    int f=0;
    while(exit != 'q'){
        for(f=0; f<10; f++){
            scanf("%c,%d",&exit, &vec[f]);

    }}
    for(int i=0; i<10; i++){
        printf("%d\n", vec[i]);
    }
    return 0;
}