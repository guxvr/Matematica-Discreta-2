/*
 * Sistema RSA com fatoração ρ de Pollard e aplicação de teoremas modulares
 * Disciplina: Matemática Discreta 2
 * Autor: Gustavo Xavier Evangelista - 241025247
 * 
 * Implementa:
 * - Fatoração interativa usando método ρ de Pollard
 * - MDC com Algoritmo de Euclides
 * - Inverso modular com Euclides Estendido
 * - Geração de chaves RSA
 * - Exponenciação modular (Fermat, Euler, Euclidiana)
 * - Codificação/decodificação de mensagem
 * - Impressão passo a passo de todos os processos
 */

#include <stdio.h>
#include <stdlib.h>

// --------- Prototipos ----------
int mdc(int a, int b);
int pollard_rho(int N);
int euclides_estendido(int a, int b, int* x, int* y);
int mod_inverse(int e, int z);
int is_prime(int n);
int totiente(int p, int q);
void gera_chaves(int p, int q, int* n, int* z, int* e, int* d);
int exponenciacao_modular(int base, int exp, int mod, int *teorema);
int codifica_caractere(char c);
char decodifica_numero(int n);
void codifica_mensagem(const char* msg, int* codificada, int* tam);
void decodifica_mensagem(const int* codificada, int tam, char* msg);

// --------- Função Principal ----------
int main() {
    int N1, N2, p, q;
    int n, z, e, d;
    char mensagem[256];
    int codificada[256];
    int cifrada[256];
    int decifrada[256];
    int tam;
    int i, teorema;

    printf("=== Sistema RSA com Fatoração ρ de Pollard ===\n");
    printf("Digite N1 (3 ou 4 dígitos, produto de primos distintos): ");
    scanf("%d", &N1);
    printf("Digite N2 (3 ou 4 dígitos, produto de primos distintos): ");
    scanf("%d", &N2);

    // Etapa 1: Fatoração
    printf("\n-- Fatoração de N1 --\n");
    p = pollard_rho(N1);
    printf("Fator encontrado para N1: p = %d\n", p);

    printf("\n-- Fatoração de N2 --\n");
    q = pollard_rho(N2);
    printf("Fator encontrado para N2: q = %d\n", q);

    // Etapa 2: Geração de Chaves RSA
    gera_chaves(p, q, &n, &z, &e, &d);
    printf("\nChave pública: (n=%d, e=%d)\n", n, e);
    printf("Chave privada: (n=%d, d=%d)\n", n, d);

    // Etapa 3: Codificação e Criptografia
    printf("\nDigite a mensagem (apenas letras e espaços): ");
    getchar(); // Limpar buffer
    fgets(mensagem, 256, stdin);

    codifica_mensagem(mensagem, codificada, &tam);

    printf("\nMensagem codificada: ");
    for(i=0; i<tam; i++) printf("%02d ", codificada[i]);

    // Criptografando
    printf("\n\n-- Criptografia --\n");
    for(i=0; i<tam; i++) {
        cifrada[i] = exponenciacao_modular(codificada[i], e, n, &teorema);
        printf("Cifra(%02d) = %d [teorema %d]\n", codificada[i], cifrada[i], teorema);
    }

    // Descriptografando
    printf("\n-- Descriptografia --\n");
    for(i=0; i<tam; i++) {
        decifrada[i] = exponenciacao_modular(cifrada[i], d, n, &teorema);
        printf("Decifra(%d) = %02d [teorema %d]\n", cifrada[i], decifrada[i], teorema);
    }

    // Reconversão numérica para texto
    char mensagem_decifrada[256];
    decodifica_mensagem(decifrada, tam, mensagem_decifrada);
    printf("\nMensagem decifrada: %s\n", mensagem_decifrada);

    // Verificação
    printf("\nConfirmação: %s\n", strcmp(mensagem, mensagem_decifrada)==0 ? "Ok" : "Diferente");

    return 0;
}

// --------- Implementações (exemplo de estrutura, implementar cada uma depois) ----------

// Algoritmo de Euclides para MDC (passo a passo)
int mdc(int a, int b) {
    printf("Calculando MDC(%d, %d):\n", a, b);
    while(b != 0) {                             // Loop até b ser 0
        printf("a = %d, b = %d\n", a, b);       // Imprime estado atual
        int t = b;                              // Swap
        b = a % b;                 
        a = t;             
    }
    printf("Resultado MDC: %d\n", a);
    return a;                                  // Retorna o MDC
}

// Pollard Rho interativo (passo a passo)
int pollard_rho(int N) {
    int x = 2, y = 2, d = 1, i = 1;
    printf("Iteracao | x | y | d\n");
    while(d == 1) {                          // Loop até encontrar fator                       
        x = (x*x + 1) % N;                   // Função f(x) = (x^2 + 1) mod N
        y = (y*y + 1) % N;                   // Função f(y) = (y^2 + 1) mod N
        y = (y*y + 1) % N;                   // y avança duas vezes
        d = mdc(abs(x-y), N);               // Calcula MDC
        printf("%8d | %2d | %2d | %2d\n", i, x, y, d);      // Imprime estado atual
        i++;                                                // Proxima iteraçao
        if(i > 100) break; // Prevenir loop infinito
    }
    if(d == N) return 0; // Falha
    return d;
}

// Algoritmo de Euclides Estendido (passo a passo)
int euclides_estendido(int a, int b, int* x, int* y) {
    if(a == 0) {                                            // Caso base
        *x = 0; *y = 1;                                     // Coeficientes
        return b;                                         
    }
    int x1, y1;                                       // Variáveis temporárias  
    int gcd = euclides_estendido(b % a, a, &x1, &y1);   // Chamada recursiva
    *x = y1 - (b/a)*x1;                                 // atualiza x e y
    *y = x1;
    return gcd;                                   // Retorna o MDC                              
}

// Inverso modular via Euclides Estendido
int mod_inverse(int e, int z) {
    int x, y;                               
    int g = euclides_estendido(e, z, &x, &y);   // Chama Euclides Estendido
    if(g != 1) return -1;                     // Inverso não existe se mdc != 1
    else return (x % z + z) % z;          // Garante positivo
}

// Totiente de Euler
int totiente(int p, int q) {                // p e q são primos
    return (p-1)*(q-1);                     // φ(n) = (p-1)(q-1)
}

// Geração de chaves RSA
void gera_chaves(int p, int q, int* n, int* z, int* e, int* d) {       
    *n = p * q;                             // n = p * q
    *z = totiente(p, q);                   // z = φ(n)
    // Encontrar e tal que mdc(e, z) == 1   
    for(*e = 2; *e < *n; (*e)++) {  
        if(mdc(*e, *z) == 1) break;         // e encontrado
    }
    *d = mod_inverse(*e, *z);            // d = e^(-1) mod z
    printf("Chaves geradas passo a passo.\n");
}

// Exponenciação modular (com decisão de teorema)
int exponenciacao_modular(int base, int exp, int mod, int *teorema) {
    // Decisão do teorema (simplificado, implementar lógica completa)
    if(is_prime(mod)) {
        *teorema = 1; // Fermat
        printf("Usando Teorema de Fermat\n");
    } else if(mdc(base, mod) == 1) {
        *teorema = 2; // Euler
        printf("Usando Teorema de Euler\n");
    } else {
        *teorema = 3; // Divisão Euclidiana
        printf("Usando Divisão Euclidiana\n");
    }
    int result = 1;               
    base = base % mod;                     // Atualiza base se maior que mod
    while(exp > 0) {
        if(exp % 2 == 1) result = (result * base) % mod;    // Se exp é ímpar
        base = (base * base) % mod;     // base = base^2 mod mod
        exp /= 2;             // exp = exp // 2
    }
    return result;
}

// Funções de codificação numérica de letras
int codifica_caractere(char c) {
    if(c == ' ') return 0;                                // Espaço (impresso como 00 com %02d)
    if(c >= 'A' && c <= 'Z') return 10 + (c - 'A' + 1);   // A=11, B=12, ..., Z=36
    if(c >= 'a' && c <= 'z') return 10 + (c - 'a' + 1);   // a=11, b=12, ..., z=36
    return 99; // Indefinido
}

char decodifica_numero(int n) {
    if(n == 0) return ' ';                       // Espaço (impresso como 00 com %02d)
    if(n >= 11 && n <= 36) return 'A' + (n - 11);   // A=11, B=12, ..., Z=36
    return '?'; // Indefinido
}

void codifica_mensagem(const char* msg, int* codificada, int* tam) {    
    int i;
    for(i = 0; msg[i] != '\0' && msg[i] != '\n'; i++) {    
        codificada[i] = codifica_caractere(msg[i]);     // Codifica caractere
    }
    *tam = i;                                           // Tamanho da mensagem codificada
}

void decodifica_mensagem(const int* codificada, int tam, char* msg) {
    int i;
    for(i = 0; i < tam; i++) {
        msg[i] = decodifica_numero(codificada[i]);  // Decodifica número
    }
    msg[tam] = '\0';                               // Finaliza string
}

// Verificação de primalidade (simples)
int is_prime(int n) {
    if(n < 2) return 0;
    for(int i=2; i*i<=n; i++)   // Testa divisores até √n
        if(n % i == 0) return 0;    // Não é primo
    return 1; // É primo
}