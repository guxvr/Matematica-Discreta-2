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
#include <string.h>

// Variável global para registrar φ(n) (totiente) para logs e reduções (Euler)
static int g_phi_n = -1;

// --------- Prototipos ----------
int mdc(int a, int b);
int pollard_rho(int N);
int euclides_estendido(int a, int b, int* x, int* y);
int mod_inverse(int e, int z);
int is_prime(int n);
int isqrt(int n);
int is_perfect_square(int n);
int trial_division(int N);
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

    printf("=== Sistema RSA com Fatoracao Rho de Pollard ===\n");
    printf("Digite N1 (3 ou 4 digitos, produto de primos distintos): ");
    if (scanf("%d", &N1) != 1) {
        fprintf(stderr, "Entrada inválida para N1.\n");
        return 1;
    }
    if (N1 < 100 || N1 > 9999) {
        fprintf(stderr, "N1 fora da faixa [100, 9999].\n");
        return 1;
    }
    printf("Digite N2 (3 ou 4 digitos, produto de primos distintos): ");
    if (scanf("%d", &N2) != 1) {
        fprintf(stderr, "Entrada inválida para N2.\n");
        return 1;
    }
    if (N2 < 100 || N2 > 9999) {
        fprintf(stderr, "N2 fora da faixa [100, 9999].\n");
        return 1;
    }
    if (N1 == N2) {
        fprintf(stderr, "N1 e N2 devem ser distintos.\n");
        return 1;
    }
    // Limpar resto da linha após os scanf (consumir até '\n')
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    // Etapa 1: Fatoracao
        printf("\n-- Fatoracao de N1 --\n");
    // Validar se N1 e quadrado perfeito antes de tentar fatorar
    if (is_perfect_square(N1)) {
        int root = isqrt(N1);
        fprintf(stderr, "N1=%d e quadrado perfeito (%d^2). Deve ser produto de primos distintos.\n", N1, root);
        return 1;
    }
    p = pollard_rho(N1);
    printf("Fator encontrado para N1: p = %d\n", p);
    if (p <= 1 || p == N1) { // valida retorno
        fprintf(stderr, "Falha ao fatorar N1 (p=%d). Tente outro N1 composto.\n", p);
        return 1;
    }
    // Validar que N1 = p * p_co com p e p_co primos distintos; preferir o maior
    int p_co = N1 / p;
    if (!is_prime(p) || !is_prime(p_co) || p == p_co) {
        fprintf(stderr, "N1 invalido: deve ser produto de dois primos distintos. Fatores: %d e %d.\n", p, p_co);
        return 1;
    }
    if (p_co > p) {
        printf("Usando maior fator de N1: %d (em vez de %d)\n", p_co, p);
        p = p_co;
    }

    printf("\n-- Fatoracao de N2 --\n");
    // Validar se N2 e quadrado perfeito antes de tentar fatorar
    if (is_perfect_square(N2)) {
        int root = isqrt(N2);
        fprintf(stderr, "N2=%d e quadrado perfeito (%d^2). Deve ser produto de primos distintos.\n", N2, root);
        return 1;
    }
    q = pollard_rho(N2);
    printf("Fator encontrado para N2: q = %d\n", q);
    if (q <= 1 || q == N2) { // valida retorno
        fprintf(stderr, "Falha ao fatorar N2 (q=%d). Tente outro N2 composto.\n", q);
        return 1;
    }
    // Validar que N2 = q * q_co com q e q_co primos distintos; preferir o maior
    int q_co = N2 / q;
    if (!is_prime(q) || !is_prime(q_co) || q == q_co) {
        fprintf(stderr, "N2 invalido: deve ser produto de dois primos distintos. Fatores: %d e %d.\n", q, q_co);
        return 1;
    }
    if (q_co > q) {
        printf("Usando maior fator de N2: %d (em vez de %d)\n", q_co, q);
        q = q_co;
    }
    // Evitar p == q (N1 e N2 não devem compartilhar o mesmo primo)
    if (p == q) {
        fprintf(stderr, "Erro: N1 e N2 compartilham o mesmo fator primo (%d). Escolha N1 e N2 sem fatores em comum.\n", p);
        return 1;
    }
    

    // --------------------Etapa 2: Geração de Chaves RSA------------------------------//
    gera_chaves(p, q, &n, &z, &e, &d);
    printf("\nChave pública: (n=%d, e=%d)\n", n, e);
    printf("Chave privada: (n=%d, d=%d)\n", n, d);
    // Validar que n suporta o alfabeto (0 e 11..36)
    if (n <= 36) {
        fprintf(stderr, "Erro: n=%d <= 36. Escolha N1 e N2 com fatores maiores para obter n>36.\n", n);
        return 1;
    }

    // ----------------------Etapa 3: Codificacao e Criptografia------------------------//
    printf("\nDigite a mensagem (apenas letras MAIUSCULAS e espacos): ");
    if (fgets(mensagem, sizeof(mensagem), stdin) == NULL) {
        fprintf(stderr, "Falha ao ler a mensagem.\n");
        return 1;
    }
    // Remover '\n' final, se presente, para comparação correta
    size_t len = strlen(mensagem);
    if (len > 0 && mensagem[len-1] == '\n') mensagem[len-1] = '\0';

    // Validar que a mensagem contem apenas letras maiusculas e espacos
    for (i = 0; mensagem[i] != '\0'; i++) {
        char c = mensagem[i];
        if (c != ' ' && (c < 'A' || c > 'Z')) {
            fprintf(stderr, "Erro: mensagem contem caractere invalido '%c'. Use apenas letras MAIUSCULAS (A-Z) e espacos.\n", c);
            return 1;
        }
    }

    codifica_mensagem(mensagem, codificada, &tam);
    // Verificar que todos os simbolos sao menores que n (para evitar reducao modular)
    for (i = 0; i < tam; i++) {
        if (codificada[i] >= n) {
            fprintf(stderr, "Erro: simbolo %02d >= n (%d). Gere chaves com n maior.\n", codificada[i], n);
            return 1;
        }
    }

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

    // Reconversao numerica para texto
    char mensagem_decifrada[256];
    decodifica_mensagem(decifrada, tam, mensagem_decifrada);
    printf("\nMensagem decifrada: %s\n", mensagem_decifrada);

    // Verificacao
    printf("\nConfirmacao: %s\n", strcmp(mensagem, mensagem_decifrada)==0 ? "Ok" : "Diferente");

    return 0;
}

// --------- Implementações (exemplo de estrutura, implementar cada uma depois) ---------- /

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

// Pollard Rho interativo (passo a passo) com tentativas múltiplas
int pollard_rho(int N) {
    // Tentar com diferentes sementes e constantes
    int seeds[] = {2, 3, 5, 7};
    int constants[] = {1, 2, 3};
    
    for (int s_idx = 0; s_idx < 4; s_idx++) {
        for (int c_idx = 0; c_idx < 3; c_idx++) {
            int x0 = seeds[s_idx];
            int c = constants[c_idx];
            
            if (s_idx > 0 || c_idx > 0) {
                printf("\nTentativa com semente x0=%d, constante c=%d\n", x0, c);
            }
            
            int x = x0, y = x0, d = 1, i = 1;
            printf("Iteracao | x | y | d\n");
            
            while(d == 1 && i <= 200) {  // Aumentado limite para 200
                x = ((long long)x*x + c) % N;
                y = ((long long)y*y + c) % N;
                y = ((long long)y*y + c) % N;
                d = mdc(abs(x-y), N);
                printf("%8d | %2d | %2d | %2d\n", i, x, y, d);
                i++;
            }
            
            if (d > 1 && d < N) {
                printf("Fator encontrado com x0=%d, c=%d\n", x0, c);
                return d;
            }
        }
    }
    
    // Todas as tentativas falharam; usar fallback
    printf("\nPollard Rho falhou apos multiplas tentativas.\n");
    return trial_division(N);
}

// Algoritmo de Euclides Estendido (passo a passo)
int euclides_estendido(int a, int b, int* x, int* y) {
    printf("EE: chamada com a=%d, b=%d\n", a, b);
    if(a == 0) {                                            // Caso base
        *x = 0; *y = 1;                                     // Coeficientes
        printf("EE: base -> gcd=%d, x=%d, y=%d\n", b, *x, *y);
        return b;                                         
    }
    int x1, y1;                                       // Variaveis temporarias  
    int gcd = euclides_estendido(b % a, a, &x1, &y1);   // Chamada recursiva
    *x = y1 - (b/a)*x1;                                 // atualiza x e y
    *y = x1;
    printf("EE: retorna para a=%d, b=%d -> gcd=%d, x=%d, y=%d\n", a, b, gcd, *x, *y);
    return gcd;                                   // Retorna o MDC                              
}

// Inverso modular via Euclides Estendido
int mod_inverse(int e, int z) {
    int x, y;                               
    int g = euclides_estendido(e, z, &x, &y);   // Chama Euclides Estendido
    if(g != 1) return -1;                     // Inverso nao existe se mdc != 1
    else return (x % z + z) % z;          // Garante positivo
}

// Totiente de Euler
int totiente(int p, int q) {                // p e q são primos
    return (p-1)*(q-1);                     // φ(n) = (p-1)(q-1)
}

// Geracao de chaves RSA
void gera_chaves(int p, int q, int* n, int* z, int* e, int* d) {       
    *n = p * q;                             // n = p * q
    *z = totiente(p, q);                   // z = phi(n)
    g_phi_n = *z;                          // Registrar phi(n) globalmente para logs de Euler
    // Encontrar e tal que mdc(e, z) == 1   
    for(*e = 2; *e < *n; (*e)++) {  
        if(mdc(*e, *z) == 1) break;         // e encontrado
    }
    *d = mod_inverse(*e, *z);            // d = e^(-1) mod z
    printf("Chaves geradas passo a passo.\n");
}

// Exponenciacao modular (com decisao de teorema)
int exponenciacao_modular(int base, int exp, int mod, int *teorema) {
    if (mod <= 1) {
        fprintf(stderr, "Erro: modulo invalido (%d) em exponenciacao_modular.\n", mod);
        if (teorema) *teorema = 3;
        return 0;
    }
    // Decisao do teorema e reducao de expoente
    int reduced_exp = exp;
    if(is_prime(mod)) {
        *teorema = 1; // Fermat
        printf("Usando Teorema de Fermat: como n e primo, reduzimos expoente por (n-1).\n");
        if (base % mod != 0) {
            int r = exp % (mod - 1);
            printf("Reducao de expoente: %d -> %d (mod %d)\n", exp, r, mod - 1);
            reduced_exp = r;
        } else {
            printf("Base multipla de n: reducao por Fermat nao se aplica.\n");
        }
    } else if(mdc(base, mod) == 1) {
        *teorema = 2; // Euler
        printf("Usando Teorema de Euler: mdc(base,n)=1, reduzimos expoente por phi(n).\n");
        if (g_phi_n > 0) {
            int r = exp % g_phi_n;
            printf("Reducao de expoente: %d -> %d (mod phi(n)=%d)\n", exp, r, g_phi_n);
            reduced_exp = r;
        } else {
            printf("phi(n) nao disponivel para reducao numerica; seguindo sem reduzir.\n");
        }
    } else {
        *teorema = 3; // Divisao Euclidiana
        printf("Usando Divisao Euclidiana: sem condicoes para Fermat/Euler; exponenciacao binaria direta.\n");
    }
    // Exponenciacao rapida com rastreamento
    int result = 1;               
    int step = 0;
    base = base % mod;                     // Atualiza base se maior que mod
    printf("Passos da exponenciacao: base=%d, expoente=%d, mod=%d\n", base, reduced_exp, mod);
    while(reduced_exp > 0) {
        printf("  passo %d: result=%d, base=%d, exp=%d\n", step, result, base, reduced_exp);
        if(reduced_exp % 2 == 1) {
            result = (result * base) % mod;    // Se exp e impar
            printf("    -> exp impar, result = (result*base) mod n = %d\n", result);
        }
        base = (base * base) % mod;     // base = base^2 mod mod
        reduced_exp /= 2;             // exp = exp // 2
        step++;
    }
    printf("Resultado final da potencia modular: %d\n", result);
    return result;
}

// Funcoes de codificacao numerica de letras (apenas maiusculas)
int codifica_caractere(char c) {
    if(c == ' ') return 0;                                // Espaco (impresso como 00 com %02d)
    if(c >= 'A' && c <= 'Z') return 10 + (c - 'A' + 1);   // A=11, B=12, ..., Z=36
    return -1; // Caractere invalido
}

char decodifica_numero(int n) {
    if(n == 0) return ' ';                       // Espaco (impresso como 00 com %02d)
    if(n >= 11 && n <= 36) return 'A' + (n - 11);   // A=11, B=12, ..., Z=36
    return '?'; // Indefinido
}

void codifica_mensagem(const char* msg, int* codificada, int* tam) {    
    int i;
    for(i = 0; msg[i] != '\0' && msg[i] != '\n'; i++) {    
        int cod = codifica_caractere(msg[i]);           // Codifica caractere
        if (cod == -1) {                                // Validacao adicional
            fprintf(stderr, "Erro: caractere invalido '%c' na posicao %d.\n", msg[i], i);
            *tam = 0;
            return;
        }
        codificada[i] = cod;
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

// Verificacao de primalidade (simples)
int is_prime(int n) {
    if(n < 2) return 0;
    for(int i=2; i*i<=n; i++)   // Testa divisores ate raiz(n)
        if(n % i == 0) return 0;    // Nao e primo
    return 1; // E primo
}

// Raiz quadrada inteira (metodo de Newton) - implementacao propria
int isqrt(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    if (n == 1) return 1;
    
    // Chute inicial
    int x = n;
    int y = (x + 1) / 2;
    
    // Itera ate convergir
    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }
    return x;
}

// Verifica se N e quadrado perfeito (usando raiz propria)
int is_perfect_square(int n) {
    if (n < 0) return 0;
    int root = isqrt(n);
    return root * root == n;
}

// Fatoracao por divisao por tentativa (fallback)
int trial_division(int N) {
    printf("Usando divisao por tentativa como fallback...\n");
    if (N % 2 == 0) return 2;
    for (int i = 3; i * i <= N; i += 2) {
        if (N % i == 0) return i;
    }
    return N; // N e primo
}