/*
 * Chaves periodicas
 * Disciplina: Matematica Discreta 2
 * Autor: Gustavo Xavier Evangelista - 241025247
 */
#include <stdio.h>

// Funcao MDC (maximo divisor comum)
int mdc(int a, int b) {
    while (b != 0) {                         // Loop ate b ser 0        
        int t = b;                           // Swap       
        b = a % b;              
        a = t;
    }
    return a;
}

// Funcao MMC (minimo multiplo comum)
int mmc(int a, int b) {
    return (a * b) / mdc(a, b);             // MMC(a, b) = (a*b)/MDC(a,b)
}

int main() {
    int N, i, ciclos[10];
    int resultado;

    printf("Digite o numero de chaves: ");
    scanf("%d", &N);

    printf("\n");
    for (i = 0; i < N; i++) {
        printf("Ciclo %d: ", i + 1);
        scanf("%d", &ciclos[i]);
    }

    // MMC acumulado
    resultado = ciclos[0];
    for (i = 1; i < N; i++) {
        resultado = mmc(resultado, ciclos[i]);  // Atualiza resultado com o MMC atual       
    }

    if (resultado > 50) {
        printf("\nNao e possivel sincronizar todas as chaves dentro do limite de 50 anos.\n");
    } else {
        printf("\n%d\n", resultado);
    }

    return 0;
}