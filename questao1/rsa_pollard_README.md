**Autor:**  
Gustavo Xavier Evangelista  - 241025247
Engenharia de Software - UnB

# RSA com Fatoração ρ de Pollard e Teoremas Modulares

Projeto didático em C que implementa um sistema completo de criptografia RSA com:
- Fatoração interativa via método ρ de Pollard (com logs passo a passo).
- Cálculo do MDC com Algoritmo de Euclides (próprio, detalhado).
- Inverso modular com Euclides Estendido (agora com logs detalhados).
- Geração das chaves RSA (n, e, d) com escolha do menor e coprimo a φ(n).
- Exponenciação modular com seleção automática de: Pequeno Teorema de Fermat, Teorema de Euler ou Divisão Euclidiana, incluindo:
  - Redução explícita do expoente (e mod φ(n), e mod n−1) quando aplicável.
  - Passo a passo da exponenciação binária (result, base, exp a cada iteração).
- Codificação/decodificação da mensagem no alfabeto: A=11, …, Z=36; espaço=00.
- Verificação final de integridade da mensagem (strcmp).

## Novidades nesta versão
- Validação de entrada: N1 e N2 devem estar em [100, 9999] e ser distintos.
- Preferência pelo maior fator primo de cada Ni para aumentar n.
- Garantias para a codificação:
  - n > 36 (para suportar o alfabeto 11..36 sem redução).
  - Cada símbolo codificado deve ser < n (validação antes de cifrar).
- Logs do Euclides Estendido (chamadas recursivas e recomposição de x, y).
- Exponenciação modular com:
  - Indicação do teorema escolhido.
  - Demonstração da redução do expoente (Fermat/Euler).
  - Iterações da exponenciação rápida (binária) passo a passo.
- Guardas numéricas (ex.: módulo inválido em exponenciação).

## Como compilar e executar (Linux)
```sh
gcc -Wall -Wextra -O2 rsa_pollard.c -o rsa_pollard
./rsa_pollard
```

Dependências: stdio.h, stdlib.h, string.h (todas padrão).

## Fluxo do programa
1. Entrada e validação:
   - Lê N1 e N2 (3 ou 4 dígitos), distintos.
   - Mensagens claras em caso de entrada inválida.
2. Etapa 1 — Fatoração (Pollard ρ):
   - g(x) = (x² + 1) mod N, semente x0 = 2, itera com “tartaruga e lebre”.
   - Exibe: “Iteracao | x | y | d” e o mdc detalhado em cada passo.
   - Define p de N1 e q de N2; prefere os maiores fatores primos.
3. Etapa 2 — Geração das chaves:
   - n = p×q, φ(n) = (p−1)(q−1).
   - Escolhe o menor e com 1 < e < n e mdc(e, φ(n)) = 1.
   - Calcula d = e⁻¹ mod φ(n) via Euclides Estendido, com logs.
   - Armazena φ(n) para logs de Euler.
4. Etapa 3 — Codificação, Criptografia e Descriptografia:
   - Codifica: espaço=00, A=11 … Z=36 (2 dígitos por símbolo).
   - Valida: n > 36 e cada símbolo < n (senão aborta com mensagem).
   - Cifra: C ≡ M^E (mod n); Decifra: M ≡ C^D (mod n).
   - Seleciona e mostra o teorema:
     - Fermat se n é primo (reduz expoente mod n−1).
     - Euler se mdc(M,n)=1 (reduz expoente mod φ(n)).
     - Divisão Euclidiana caso contrário (sem redução).
   - Exibe o passo a passo da exponenciação binária.
   - Decodifica números de volta para texto e confirma se é idêntica.

## Entradas aceitas
- Letras A–Z (maiúsculas/minúsculas tratadas como letras) e espaço.
- Caracteres fora do alfabeto podem ser mapeados para “?” na decodificação.

## Exemplo rápido
Sugestão de N1 e N2 (produtos de primos distintos) que garantem n > 36 e p ≠ q:
- N1 = 187 (11 × 17) → p=17
- N2 = 209 (11 × 19) → q=19
- n = 323

Execução (resumo):
```
=== Sistema RSA com Fatoração ρ de Pollard ===
Digite N1 (3 ou 4 dígitos, produto de primos distintos): 187
Digite N2 (3 ou 4 dígitos, produto de primos distintos): 209

-- Fatoração de N1 --
Iteracao | x | y | d
... (passos do Pollard ρ com mdc detalhado)
Fator encontrado para N1: p = 17

-- Fatoração de N2 --
Iteracao | x | y | d
... (passos do Pollard ρ com mdc detalhado)
Fator encontrado para N2: q = 19

Chaves geradas passo a passo.
Chave pública: (n=323, e=3)
Chave privada: (n=323, d=215)

Digite a mensagem (apenas letras e espaços): CRISTIANE LOESCH
Mensagem codificada: 13 28 19 29 30 19 11 24 15 00 22 25 15 29 13 18 

-- Criptografia --
Usando Teorema de Euler
Reduzindo expoente: e ≡ e mod φ(n) = ...
[Exp. binária] exp=..., base=..., result=...
Cifra(13) = ... [teorema 2]
...

-- Descriptografia --
Usando Teorema de Euler
Reduzindo expoente: d ≡ d mod φ(n) = ...
[Exp. binária] exp=..., base=..., result=...
Decifra(...) = ... [teorema 2]
...

Mensagem decifrada: CRISTIANE LOESCH
Confirmação: Ok
```

## Validações e salvaguardas
- N1 e N2 em [100, 9999] e N1 ≠ N2.
- Preferência pelo maior fator primo de cada Ni (aumenta n).
- Verificação de p ≠ q e de fatores não triviais.
- Verificação: n > 36 e cada símbolo codificado < n.
- Guarda em exponenciação para módulo inválido (mod ≤ 1).

## Observações
- Projeto didático; números pequenos para visualização dos passos.
- O método ρ de Pollard é probabilístico; pode falhar para casos específicos (ex.: N primo ou quadrado perfeito).
- Sem bibliotecas externas de criptografia; apenas headers padrão C.

## Estrutura
- rsa_pollard.c — código-fonte principal com todas as funções e logs.
- rsa_pollard_README.md — este documento.