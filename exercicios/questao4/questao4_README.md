
## Teste de Verificação

**Entrada:** H=7, G=3, Zn=11, x=10, n1=13

**Passo 1:** Divisão modular
- inverso(3, 11) = 4 (pois 3 × 4 ≡ 1 mod 11)
- a = (7 × 4) % 11 = 28 % 11 = **6**

**Passo 2:** Potência modular
- n1=13 é primo → aplica Fermat
- 6^10 mod 13 = ?
- φ(13) = 12, então 6^10 ≡ 6^10 (mod 13)
- Calculando: 6^10 = 60466176 ≡ **4** (mod 13)

**Saída esperada:** `Valor final da congruência: 4` 

# Questão 4: Análise de Código - Divisão Modular e Teoremas

**Autor:** Gustavo Xavier Evangelista  
**Disciplina:** Matemática Discreta 2

---

## Código Analisado

```c
int inversoModular(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    while (m != 0) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
        x1 += m0;
    return x1;
}
```

O código realiza:
1. Cálculo da divisão modular: **H ÷ G (mod Zn)**
2. Computação de: **a^x mod n1**
3. Aplicação do Pequeno Teorema de Fermat ou Teorema de Euler conforme a natureza de n1

---

## Classificação das Afirmativas

### **(V) O algoritmo de Euclides estendido é utilizado para calcular o inverso modular de um número.**

 **VERDADEIRO**

O código implementa claramente o Algoritmo de Euclides Estendido:
- Calcula simultaneamente o MDC e os coeficientes de Bézout (x0, x1)
- Atualiza `x0` e `x1` a cada iteração: `x0 = x1 - q * x0`
- Retorna o coeficiente que representa o inverso modular

---

### **(F) Se mdc(G, Zn) ≠ 1, o programa ainda consegue encontrar o inverso de G em Zn.**

 **FALSO**

**Justificativa:**
- O inverso modular de G em Zn **só existe** se mdc(G, Zn) = 1
- O código **não valida** essa condição prévia
- Se mdc(G, Zn) ≠ 1, o programa retornará um valor incorreto/sem significado matemático
- Falta validação: `if (mdc != 1) return -1; // erro`

---

### **(V) A operação (H * inverso) % Zn representa a divisão modular de H por G.**

 **VERDADEIRO**

**Demonstração:**
- Divisão modular: H ÷ G (mod Zn)
- É equivalente a: H × G⁻¹ (mod Zn)
- Onde G⁻¹ é o inverso modular de G em Zn
- Logo: `(H * inverso) % Zn` é exatamente a divisão modular

**Exemplo:**
- H = 7, G = 3, Zn = 11
- inverso = 4 (pois 3 × 4 ≡ 1 mod 11)
- (7 × 4) % 11 = 28 % 11 = 6
- Verificação: 3 × 6 ≡ 18 ≡ 7 (mod 11) ✓

---

### **(V) Se n1 for primo, o código aplica o Pequeno Teorema de Fermat para simplificar o cálculo de a^x mod n1.**

 **VERDADEIRO**

**Pequeno Teorema de Fermat:**
- Se **p é primo** e mdc(a, p) = 1, então: a^(p-1) ≡ 1 (mod p)
- Permite reduzir o expoente: a^x ≡ a^(x mod (p-1)) (mod p)

**Aplicação no código:**
- Quando n1 é primo, usa-se Fermat para otimizar
- Quando n1 é composto, usa-se Euler

---

### **(F) A função powMod implementa o cálculo de potência modular utilizando multiplicações diretas sem otimização.**

 **FALSO**

**Justificativa:**
- O enunciado menciona "algoritmo eficiente"
- Implementações típicas de `powMod` usam **exponenciação binária** (square-and-multiply)
- Complexidade: O(log x) em vez de O(x)
- **É otimizado**, não usa multiplicações diretas ingênuas

**Algoritmo típico:**
```c
int powMod(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;  // exp ímpar
        base = (base * base) % mod;  // square
        exp >>= 1;  // divide por 2
    }
    return result;
}
```

---

### **(V) Quando o resultado do inverso é negativo, o código ajusta o valor somando o módulo m0.**

 **VERDADEIRO**

**Código explícito:**
```c
if (x1 < 0)
    x1 += m0;
return x1;
```

**Justificativa:**
- O Euclides Estendido pode retornar coeficientes negativos
- Para garantir o inverso no intervalo [0, m-1], soma-se m0 (módulo original)
- Propriedade: se x é inverso, então x + m também é (mod m)

---

### **(V) O cálculo de φ(n1) (função totiente de Euler) é utilizado apenas quando n1 não é primo.**

 **VERDADEIRO**

**Teoremas aplicáveis:**

| Caso | Teorema | Usa φ(n1)? |
|------|---------|-----------|
| n1 primo | Fermat: a^(n1-1) ≡ 1 (mod n1) | ❌ NÃO |
| n1 composto, mdc(a,n1)=1 | Euler: a^φ(n1) ≡ 1 (mod n1) | ✅ SIM |

**Justificativa:**
- **n1 primo:** φ(n1) = n1 - 1 (trivial, não precisa calcular)
- **n1 composto:** φ(n1) deve ser calculado (ex.: φ(15) = φ(3×5) = 2×4 = 8)

---

## Resposta Final

```
V F V V F V V
```