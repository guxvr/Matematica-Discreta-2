# Questão 3: A Razão de Eficiência de um Número

**Autor:** Gustavo Xavier Evangelista - 241025247  
**Disciplina:** Matemática Discreta 2  
**Engenharia de Software - UnB**

---

## Descrição do Problema

Este programa calcula a **Razão de Eficiência** de um número inteiro N, que é definida como a média aritmética de todos os seus divisores.

### Conceito Matemático

A Razão de Eficiência é calculada como:
```
Razão = σ(N) / τ(N)
```

Onde:
- **τ(N)** = Número total de divisores de N
- **σ(N)** = Soma de todos os divisores de N

### Fórmulas Utilizadas

Para um número com fatoração prima **N = p₁^e₁ × p₂^e₂ × ... × pₖ^eₖ**:

1. **Função Tau (número de divisores):**
   ```
   τ(N) = (e₁ + 1) × (e₂ + 1) × ... × (eₖ + 1)
   ```

2. **Função Sigma (soma dos divisores):**
   ```
   σ(N) = [(1 + p₁ + p₁² + ... + p₁^e₁)] × [(1 + p₂ + p₂² + ... + p₂^e₂)] × ...
   ```
   
   Para cada fator primo pᵢ:
   ```
   σ(pᵢ^eᵢ) = (pᵢ^(eᵢ+1) - 1) / (pᵢ - 1)
   ```

---

## Funcionalidades

1. **Fatoração Prima por Divisão de Tentativas**
   - Algoritmo Trial Division até √N
   - Otimizado para números até 10⁵

2. **Cálculo de τ(N)**
   - Produto dos expoentes incrementados
   - Exibição passo a passo

3. **Cálculo de σ(N)**
   - Soma geométrica para cada fator primo
   - Evita overflow usando `unsigned long long`

4. **Cálculo da Razão de Eficiência**
   - Divisão σ(N) / τ(N)
   - Resultado com 2 casas decimais

---

## Como compilar e executar

### Passo 1: Navegar até o diretório do projeto
A partir da raiz do repositório, entre na pasta da questão 3:
```bash
cd exercicios/questao3
```

### Passo 2: Compilar o código
Compile o arquivo `razao_eficiencia.c`:
```bash
gcc -Wall -Wextra -O2 razao_eficiencia.c -o razao_eficiencia
```

**Explicação dos parâmetros:**
- `-Wall -Wextra`: Habilita warnings para detectar possíveis problemas
- `-O2`: Otimização de código para melhor desempenho
- `razao_eficiencia.c`: Arquivo fonte
- `-o razao_eficiencia`: Nome do executável gerado

### Passo 3: Executar o programa
```bash
./razao_eficiencia
```

### Compilação alternativa (uma linha, a partir da raiz do repositório)
```bash
gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia && exercicios/questao3/razao_eficiencia
```

**Dependências:** stdio.h (biblioteca padrão C)

---

## Exemplos de Uso

### Exemplo 1: N = 12
```
Insira um numero inteiro N (1 <= N <= 10^5): 12
=== Razao de Eficiencia de um Numero ===
N = 12
Fatores primos (p^e): 2^2 * 3^1
Calculo de tau(N):
tau = (2+1) * (1+1) = 6
Calculo de sigma(N):
Termo para p=2, e=2: 1 + 2 + 4 = 7
Termo para p=3, e=1: 1 + 3 = 4
sigma = produto dos termos acima = 28
Razao de Eficiencia (sigma/tau) = 4.67
```

**Explicação:**
- 12 = 2² × 3¹
- Divisores de 12: {1, 2, 3, 4, 6, 12} → 6 divisores (τ=6)
- Soma dos divisores: 1+2+3+4+6+12 = 28 (σ=28)
- Razão: 28/6 = 4.67

### Exemplo 2: N = 1 (caso especial)
```
Insira um numero inteiro N (1 <= N <= 10^5): 1
=== Razao de Eficiencia de um Numero ===
N = 1
Fatores primos: (nenhum), pois 1 nao tem fatoracao prima convencional.
Calculo de tau(N): tau(1) = 1
Calculo de sigma(N): sigma(1) = 1
Razao de Eficiencia (sigma/tau) = 1.00
```

### Exemplo 3: N = 28 (número perfeito)
```
Insira um numero inteiro N (1 <= N <= 10^5): 28
=== Razao de Eficiencia de um Numero ===
N = 28
Fatores primos (p^e): 2^2 * 7^1
Calculo de tau(N):
tau = (2+1) * (1+1) = 6
Calculo de sigma(N):
Termo para p=2, e=2: 1 + 2 + 4 = 7
Termo para p=7, e=1: 1 + 7 = 8
sigma = produto dos termos acima = 56
Razao de Eficiencia (sigma/tau) = 9.33
```

**Nota:** Para números perfeitos, σ(N) = 2N (a soma dos divisores próprios = N)

### Exemplo 4: Número Primo (N = 17)
```
Insira um numero inteiro N (1 <= N <= 10^5): 17
=== Razao de Eficiencia de um Numero ===
N = 17
Fatores primos (p^e): 17^1
Calculo de tau(N):
tau = (1+1) = 2
Calculo de sigma(N):
Termo para p=17, e=1: 1 + 17 = 18
sigma = produto dos termos acima = 18
Razao de Eficiencia (sigma/tau) = 9.00
```

**Explicação:** Números primos têm apenas 2 divisores (1 e ele mesmo)

---

## Estrutura do Código

```c
typedef struct {
    int p;   // primo
    int e;   // expoente
} Factor;

int factorize(int n, Factor fac[], int maxf)     // Fatoração por Trial Division
unsigned long long geometric_sum(int p, int e)   // Soma 1+p+p²+...+p^e
int main(void)                                     // Função principal
```

---

## Características Técnicas

- **Tipo de dados:** `unsigned long long` para evitar overflow
- **Intervalo válido:** 1 ≤ N ≤ 100.000
- **Algoritmo de fatoração:** Trial Division (divisão por tentativa)
- **Complexidade:** O(√N) para fatoração

---

## Validações

- ✅ Entrada fora do intervalo [1, 100000] é rejeitada
- ✅ Caso especial N=1 tratado separadamente
- ✅ Números primos identificados corretamente
- ✅ Prevenção de overflow com `unsigned long long`

---

## Observações

- Programa educacional para demonstrar funções aritméticas τ(N) e σ(N)
- Exibição detalhada de todos os cálculos intermediários
- Implementação própria sem bibliotecas matemáticas externas
- Formato de saída com 2 casas decimais para a razão final
