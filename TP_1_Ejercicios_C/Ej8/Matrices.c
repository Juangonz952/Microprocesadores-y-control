#include "Matrices.h"

void Imprimir_M(matriz_t*M);
int Traza_M(matriz_t *M);
int Determinante_M(matriz_t *M);
matriz_t Traspuesta_M(matriz_t*M);
matriz_t Multiplicacion_M(matriz_t *M1,matriz_t *M2);
matriz_t Escalar_M(matriz_t *M, int lambda);
matriz_t Suma_M(matriz_t *M1, matriz_t *M2);
matriz_t Resta_M(matriz_t *M1, matriz_t *M2);
matriz_t Potencia_M(matriz_t *M,int pow);

matriz_t Inicializar_matriz(int M[DIM][DIM]){
    matriz_t Result;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            Result.Matrix[i][j]=M[i][j];
        }
    }
    Result.Imprimir=Imprimir_M;
    Result.Traza = Traza_M;
    Result.Determinante = Determinante_M;
    Result.Traspuesta=Traspuesta_M;
    Result.Multiplicacion=Multiplicacion_M;
    Result.Escalar = Escalar_M;
    Result.Suma = Suma_M;
    Result.Resta = Resta_M;
    Result.Potencia=Potencia_M;
    return Result;
}

void Imprimir_M(matriz_t *M){
    for(int i=0;i<DIM;i++){
        printf("\n");
        for(int j=0;j<DIM;j++){
            printf("%d ",M->Matrix[i][j]);
        }
    }
    return;
}
matriz_t Identidad(){
    matriz_t I;
    int Aux[DIM][DIM];
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            if(i==j){
                Aux[i][j] = 1;
            }
            if(i!=j){
                Aux[i][j] =0;
            }
        }
    }
    I = Inicializar_matriz(Aux);
    return I;
}
int Traza_M(matriz_t*M){
    int traza =0;
    for(int i =0;i<DIM;i++){
        traza+= M->Matrix[i][i];
    }
    return traza;
}

int Determinante_M(matriz_t *M){
    int det =0;
    det+=(M->Matrix[0][0])*(M->Matrix[1][1])*(M->Matrix[2][2]);
    det-=(M->Matrix[0][0])*(M->Matrix[1][2])*(M->Matrix[2][1]);
    det-=(M->Matrix[0][1])*(M->Matrix[1][0])*(M->Matrix[2][2]);
    det+=(M->Matrix[0][1])*(M->Matrix[1][2])*(M->Matrix[2][0]);
    det+=(M->Matrix[0][2])*(M->Matrix[1][0])*(M->Matrix[2][1]);
    det-=(M->Matrix[0][2])*(M->Matrix[1][1])*(M->Matrix[2][0]);
    return det;
}

matriz_t Traspuesta_M(matriz_t *M){
    int Aux[DIM][DIM];
    matriz_t Resultado;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            Aux[i][j] = M->Matrix[j][i];
        }
    }
    Resultado = Inicializar_matriz(Aux);
    return Resultado;
}

matriz_t Escalar_M(matriz_t * M, int lambda){
    int Aux[DIM][DIM];
    matriz_t Resultado;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            Aux[i][j] =lambda*(M->Matrix[i][j]);
        }
    }
    Resultado = Inicializar_matriz(Aux);
    return Resultado;
}

matriz_t Suma_M(matriz_t *M1,matriz_t *M2){
    int Aux[DIM][DIM];
    matriz_t Resultado;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            Aux[i][j] =M1->Matrix[i][j] + M2->Matrix[i][j];
        }
    }
    Resultado = Inicializar_matriz(Aux);
    return Resultado;
}

matriz_t Resta_M(matriz_t*M1,matriz_t*M2){
    matriz_t Aux;
    Aux = Escalar_M(M2,-1);
    return Suma_M(M1,&Aux);
}

matriz_t Multiplicacion_M(matriz_t *M1,matriz_t *M2){
    int Aux[DIM][DIM];
    int c=0;
    matriz_t Resultado;
    for(int i =0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            for(int k=0;k<DIM;k++){
                c+=(M1->Matrix[i][k])*(M2->Matrix[k][j]);
            }
        Aux[i][j] = c;
        c = 0;    
        }
    }
    Resultado=Inicializar_matriz(Aux);
    return Resultado;
}

matriz_t Potencia_M(matriz_t *M,int pow){
    matriz_t Resultado;
    Resultado =Identidad();
    for(int i =0;i<pow;i++){
        Resultado = Multiplicacion_M(&Resultado,M);
    }
    return Resultado;
}