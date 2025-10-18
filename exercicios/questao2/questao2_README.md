# Questão 2: Chaves Periódicas

**Autor:** Gustavo Xavier Evangelista - 241025247  
**Disciplina:** Matemática Discreta 2  
**Engenharia de Software - UnB**

---

## Descrição do Problema

Este programa calcula o **Mínimo Múltiplo Comum (MMC)** dos ciclos de múltiplas chaves para determinar quando todas as chaves estarão sincronizadas simultaneamente.

### Conceito Matemático
- O MMC de múltiplos números representa o menor valor que é múltiplo de todos eles
- Para calcular o MMC de vários números, usamos a fórmula: MMC(a, b) = (a × b) / MDC(a, b)
- O MMC é calculado de forma acumulativa para todos os ciclos

---

## Funcionalidades

1. **Cálculo do MDC (Máximo Divisor Comum)**
   - Implementado usando o Algoritmo de Euclides
   - Base para o cálculo do MMC

2. **Cálculo do MMC (Mínimo Múltiplo Comum)**
   - Usa a relação: MMC(a,b) = (a × b) / MDC(a,b)
   - Aplicado iterativamente para múltiplas chaves

3. **Validação de Limite**
   - Verifica se o resultado excede 50 anos
   - Exibe mensagem apropriada quando não é possível sincronizar

---

## Como compilar e executar

### Passo 1: Navegar até o diretório do projeto
A partir da raiz do repositório, entre na pasta da questão 2:
```bash
cd exercicios/questao2
```

### Passo 2: Compilar o código
Compile o arquivo `chaves_periodicas.c`:
```bash
gcc -Wall -Wextra -O2 chaves_periodicas.c -o chaves_periodicas
```

**Explicação dos parâmetros:**
- `-Wall -Wextra`: Habilita warnings para detectar possíveis problemas
- `-O2`: Otimização de código para melhor desempenho
- `chaves_periodicas.c`: Arquivo fonte
- `-o chaves_periodicas`: Nome do executável gerado

### Passo 3: Executar o programa
```bash
./chaves_periodicas
```

### Compilação alternativa (uma linha, a partir da raiz do repositório)
```bash
gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas && exercicios/questao2/chaves_periodicas
```

**Dependências:** stdio.h (biblioteca padrão C)

---

## Exemplos de Uso

### Exemplo 1: Sincronização possível
```
Digite o numero de chaves: 3

Ciclo 1: 4
Ciclo 2: 6
Ciclo 3: 8

24
```

**Explicação:**
- MMC(4, 6, 8) = 24
- As chaves se sincronizam a cada 24 anos

### Exemplo 2: Sincronização impossível
```
Digite o numero de chaves: 2

Ciclo 1: 30
Ciclo 2: 40

Nao e possivel sincronizar todas as chaves dentro do limite de 50 anos.
```

**Explicação:**
- MMC(30, 40) = 120
- Como 120 > 50, a sincronização não ocorre dentro do limite

### Exemplo 3: Ciclos coprimos
```
Digite o numero de chaves: 3

Ciclo 1: 5
Ciclo 2: 7
Ciclo 3: 11

Nao e possivel sincronizar todas as chaves dentro do limite de 50 anos.
```

**Explicação:**
- MMC(5, 7, 11) = 385 (números primos entre si)
- Resultado muito acima do limite de 50 anos

---

## Estrutura do Código

```c
int mdc(int a, int b)          // Calcula MDC usando Algoritmo de Euclides
int mmc(int a, int b)          // Calcula MMC usando a relação com MDC
int main()                     // Função principal com entrada/saída
```

---

## Limitações

- Suporta até 10 chaves (limitação do array)
- Valores de ciclo devem ser inteiros positivos
- Limite máximo de sincronização: 50 anos

---

## Observações

- Programa educacional focado em demonstrar conceitos de MMC e MDC
- Implementação própria dos algoritmos (sem bibliotecas matemáticas externas)
- Formato de entrada interativo com prompts numerados para cada ciclo
