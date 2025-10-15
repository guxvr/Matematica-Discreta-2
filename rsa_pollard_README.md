**Autor:**  
Gustavo Xavier Evangelista  
Engenharia de Software - UnB


# RSA com Fatoração ρ de Pollard e Teoremas Modulares

Este projeto implementa um sistema educativo de criptografia RSA em linguagem C, incluindo:

- Fatoração de números compostos usando o método ρ de Pollard.
- Cálculo do MDC e inverso modular via Algoritmo de Euclides.
- Geração das chaves públicas e privadas do RSA.
- Codificação e decodificação de mensagens com sistema numérico próprio.
- Exponenciação modular utilizando automaticamente o Pequeno Teorema de Fermat, Teorema de Euler ou Divisão Euclidiana.
- Impressão detalhada do passo a passo de cada cálculo importante.

## Como funciona

1. **Fatoração (Pollard ρ):** O programa solicita dois números compostos (N1 e N2), ambos produtos de primos distintos. Aplica o método ρ de Pollard interativamente, exibindo as iterações e encontrando um fator primo de cada número.
2. **Chaves RSA:** Usa os fatores primos p e q para gerar as chaves RSA, mostrando o cálculo de totiente, escolha do expoente público e cálculo do inverso modular (D).
3. **Codificação da Mensagem:** Cada letra é convertida para um número (A=11, ..., Z=36, espaço=00), sendo então criptografada e posteriormente decodificada.
4. **Criptografia/Descriptografia:** Aplica a exponenciação modular, justificando o teorema usado em cada caso, e mostra o cálculo passo a passo.
5. **Verificação:** Confirma se a mensagem decifrada corresponde à original.

## Como compilar e executar

```sh
gcc rsa_pollard.c -o rsa_pollard
./rsa_pollard
```

## Teste inicial sugerido

Use os seguintes números para N1 e N2 (produtos de primos pequenos):

- N1 = 143  (143 = 11 × 13)
- N2 = 221  (221 = 13 × 17)

Mensagem:  
```
O programa aceita letras e espaços.  
Exemplo: "ABC DE"
```

### Exemplo de execução

```
=== Sistema RSA com Fatoração ρ de Pollard ===
Digite N1 (3 ou 4 dígitos, produto de primos distintos): 143
Digite N2 (3 ou 4 dígitos, produto de primos distintos): 221

-- Fatoração de N1 --
Iteracao | x | y | d
1        | ... | ... | ...
... (passos do Pollard ρ)
Fator encontrado para N1: p = 11

-- Fatoração de N2 --
Iteracao | x | y | d
... (passos do Pollard ρ)
Fator encontrado para N2: q = 13

Chave pública: (n=143, e=3)
Chave privada: (n=143, d=95)

Digite a mensagem (apenas letras e espaços): ABC DE

Mensagem codificada: 11 12 13 0 14 15 
-- Criptografia --
Cifra(11) = ... [teorema ...] 
...
-- Descriptografia --
Decifra(...) = ... [teorema ...]
...

Mensagem decifrada: ABC DE

Confirmação: Ok
```

## Observações

- Todas as funções são implementadas sem uso de bibliotecas externas.
- O programa imprime o passo a passo de cada cálculo.
- O sistema é didático e pode ser expandido para números maiores ou para incluir outras funcionalidades.
