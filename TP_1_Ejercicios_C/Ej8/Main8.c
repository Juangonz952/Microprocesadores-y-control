#include "Matrices.h"


#include "matrices.h"

int main() {
    // Datos de prueba
    int datosA[DIM][DIM] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    int datosB[DIM][DIM] = {
        {7, 8, 9},
        {1, 0, 2},
        {3, 4, 5}
    };

    // Inicializar matrices
    matriz_t A = Inicializar_matriz(datosA);
    matriz_t B = Inicializar_matriz(datosB);

    // Imprimir A
    printf("Matriz A:");
    A.Imprimir(&A);

    // Imprimir B
    printf("\n\nMatriz B:");
    B.Imprimir(&B);

    // Suma A + B
    matriz_t S = A.Suma(&A, &B);
    printf("\n\nSuma A + B:");
    S.Imprimir(&S);

    // Resta A - B
    matriz_t R = A.Resta(&A, &B);
    printf("\n\nResta A - B:");
    R.Imprimir(&R);

    // Producto A * B
    matriz_t P = A.Multiplicacion(&A, &B);
    printf("\n\nProducto A * B:");
    P.Imprimir(&P);

    // Traza de A
    printf("\n\nTraza de A: %d\n", A.Traza(&A));

    // Determinante de A
    printf("Determinante de A: %d\n", A.Determinante(&A));

    // Traspuesta de A
    matriz_t T = A.Traspuesta(&A);
    printf("\nTraspuesta de A:");
    T.Imprimir(&T);

    // Potencia A^2
    matriz_t A2 = A.Potencia(&A, 2);
    printf("\n\nA al cuadrado (A^2):");
    A2.Imprimir(&A2);

    printf("\n");

    return 0;
}
