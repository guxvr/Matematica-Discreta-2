/*
 * A Razão de Eficiência de um Número
 * Disciplina: Matemática Discreta 2
 * Autor: Gustavo Xavier Evangelista - 241025247
 */
#include <stdio.h>

typedef unsigned long long u64;

typedef struct {
    int p;   // primo
    int e;   // expoente
} Factor;

// Fatoração por divisão de tentativas (Trial Division) até sqrt(n)
int factorize(int n, Factor fac[], int maxf) {
    int count = 0;
    int x = n;

    // fator 2
    if (x % 2 == 0) {
        int e = 0;
        while (x % 2 == 0) { x /= 2; e++; }
        if (count < maxf) { fac[count].p = 2; fac[count].e = e; count++; }
    }
    // ímpares
    for (int d = 3; (long long)d * d <= x; d += 2) {
        if (x % d == 0) {
            int e = 0;
            while (x % d == 0) { x /= d; e++; }
            if (count < maxf) { fac[count].p = d; fac[count].e = e; count++; }
        }
    }
    // se sobrou um primo > 1
    if (x > 1) {
        if (count < maxf) { fac[count].p = x; fac[count].e = 1; count++; }
    }
    return count;
}

// soma geométrica 1 + p + p^2 + ... + p^e (evita overflow de potências grandes)
u64 geometric_sum(int p, int e) {
    u64 sum = 1, term = 1;
    for (int i = 1; i <= e; i++) {
        term *= (u64)p;
        sum += term;
    }
    return sum;
}

int main(void) {
    int N;
    printf("Insira um numero inteiro N (1 <= N <= 10^5): ");
    if (scanf("%d", &N) != 1) return 0;

    if (N < 1 || N > 100000) {
        printf("N fora do intervalo permitido (1 <= N <= 10^5)\n");
        return 0;
    }

    printf("=== Razao de Eficiencia de um Numero ===\n");
    printf("N = %d\n", N);

    // Caso especial N = 1
    if (N == 1) {
        printf("Fatores primos: (nenhum), pois 1 não tem fatoracao prima convencional.\n");
        printf("Calculo de tau(N): tau(1) = 1\n");
        printf("Calculo de sigma(N): sigma(1) = 1\n");
        double razao = 1.0; // sigma(1)/tau(1)
        printf("Razao de Eficiencia (sigma/tau) = %.2f\n", razao);
        return 0;
    }

    // Fatoração
    Factor fac[16]; // suficiente para N <= 1e5
    int k = factorize(N, fac, 16);

    // Imprime fatores e expoentes
    printf("Fatores primos (p^e): ");
    for (int i = 0; i < k; i++) {
        printf("%d^%d", fac[i].p, fac[i].e);
        if (i + 1 < k) printf(" * ");
    }
    printf("\n");

    // Calculo de tau(N) = prod (e_i + 1)
    u64 tau = 1;
    printf("Calculo de tau(N):\n");
    printf("tau = ");
    for (int i = 0; i < k; i++) {
        u64 term = (u64)(fac[i].e + 1);
        tau *= term;
        printf("(%d+1)%s", fac[i].e, (i + 1 < k ? " * " : ""));
    }
    printf(" = %llu\n", tau);

    // Calculo de sigma(N) = prod (1 + p + p^2 + ... + p^e)
    u64 sigma = 1;
    printf("Calculo de sigma(N):\n");
    for (int i = 0; i < k; i++) {
        u64 sum = geometric_sum(fac[i].p, fac[i].e);
        sigma *= sum;
        printf("Termo para p=%d, e=%d: 1", fac[i].p, fac[i].e);
        u64 term = 1;
        for (int j = 1; j <= fac[i].e; j++) {
            term *= (u64)fac[i].p;
            printf(" + %llu", term);
        }
        printf(" = %llu\n", sum);
    }
    printf("sigma = produto dos termos acima = %llu\n", sigma);

    // Razao de eficiencia: media dos divisores = sigma/tau
    double razao = (double)sigma / (double)tau;
    printf("Razao de Eficiencia (sigma/tau) = %.2f\n", razao);

    // Saida final solicitada (apenas o numero com duas casas, se desejar padronizar):
    // printf("%.2f\n", razao);

    return 0;
}