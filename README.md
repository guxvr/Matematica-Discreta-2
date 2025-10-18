# Matemática Discreta 2 — Engenharia de Software (UnB)

Repositório destinado à documentação e armazenamento dos códigos referentes aos exercícios propostos na disciplina **Matemática Discreta 2**, ministrada pela professora Dra. Cristiane Loesch de Souza Costa, no curso de Engenharia de Software da Universidade de Brasília.

---

## 📑 Índice

- [📖 Sobre o Repositório](#sobre-o-repositório)
- [🗂️ Estrutura](#estrutura-do-repositório)
- [🚀 Como Compilar e Executar](#-como-compilar-e-executar)
- [📚 Descrição dos Exercícios](#-descrição-dos-exercícios)
- [🧪 Testes Automatizados](#-testes-automatizados)
- [📖 Conceitos Abordados](#-conceitos-abordados)
- [📁 Arquivos do Projeto](#-arquivos-do-projeto)
- [📜 Licença](#licença)

> 🗂️ **[Ver índice completo com todos os links →](INDEX.md)**

---

## Sobre o repositório

Este espaço foi criado para compartilhar e organizar as soluções dos exercícios desenvolvidos ao longo da disciplina. Cada exercício será discutido e documentado, visando facilitar o estudo e a compreensão dos principais conceitos de matemática discreta aplicados à computação.

## Estrutura 

## Estrutura do Repositório

```
Matematica-Discreta-2/
├── 📄 README.md                  # Este arquivo - Documentação principal
├── 📘 COMPILACAO.md              # Guia completo de compilação
├── ⚡ CHEATSHEET.md              # Comandos rápidos (cheat sheet)
├── 🧪 test_rsa.sh                # Script de testes automatizados
├── 📜 LICENSE                    # Licença MIT
├── 📋 atividade_MD2_2025_2_k.pdf # Enunciado das questões
│
└── 📁 exercicios/
    │
    ├── 📁 questao1/              # Sistema RSA com Fatoração ρ de Pollard
    │   ├── rsa_pollard.c         # Código fonte
    │   ├── rsa_pollard           # Executável (gerado após compilação)
    │   └── rsa_pollard_README.md # Documentação detalhada
    │
    ├── 📁 questao2/              # Chaves Periódicas (MMC)
    │   ├── chaves_periodicas.c   # Código fonte
    │   ├── chaves_periodicas     # Executável (gerado após compilação)
    │   └── questao2_README.md    # Documentação detalhada
    │
    ├── 📁 questao3/              # Razão de Eficiência de um Número
    │   ├── razao_eficiencia.c    # Código fonte
    │   ├── razao_eficiencia      # Executável (gerado após compilação)
    │   └── questao3_README.md    # Documentação detalhada
    │
    └── 📁 questao4/              # Análise de Código (Bônus)
        ├── bonus.c               # Código fonte
        ├── bonus                 # Executável (gerado após compilação)
        └── questao4_README.md    # Documentação detalhada
```

**Nota:** Os executáveis (arquivos sem extensão) são gerados após a compilação.

---

## 🚀 Como Compilar e Executar

> 📖 **Guias de Compilação:**
> - [📘 Guia Completo Passo a Passo](COMPILACAO.md) - Tutorial detalhado com exemplos
> - [⚡ Cheat Sheet](CHEATSHEET.md) - Comandos rápidos para copiar e colar

### ⚡ Guia Rápido

Todos os comandos abaixo assumem que você está na **raiz do repositório**.

| Questão | Comando de Compilação | Comando de Execução |
|---------|----------------------|---------------------|
| **1 - RSA** | `gcc -Wall -Wextra -O2 exercicios/questao1/rsa_pollard.c -o exercicios/questao1/rsa_pollard` | `exercicios/questao1/rsa_pollard` |
| **2 - Chaves** | `gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas` | `exercicios/questao2/chaves_periodicas` |
| **3 - Eficiência** | `gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia` | `exercicios/questao3/razao_eficiencia` |
| **4 - Bônus** | `gcc -Wall -Wextra -O2 exercicios/questao4/bonus.c -o exercicios/questao4/bonus` | `exercicios/questao4/bonus` |

### Opção 1: Executar a partir do diretório de cada questão

#### Questão 1 - Sistema RSA
```bash
cd exercicios/questao1
gcc -Wall -Wextra -O2 rsa_pollard.c -o rsa_pollard
./rsa_pollard
```

#### Questão 2 - Chaves Periódicas
```bash
cd exercicios/questao2
gcc -Wall -Wextra -O2 chaves_periodicas.c -o chaves_periodicas
./chaves_periodicas
```

#### Questão 3 - Razão de Eficiência
```bash
cd exercicios/questao3
gcc -Wall -Wextra -O2 razao_eficiencia.c -o razao_eficiencia
./razao_eficiencia
```

#### Questão 4 - Bônus
```bash
cd exercicios/questao4
gcc -Wall -Wextra -O2 bonus.c -o bonus
./bonus
```

### Opção 2: Compilar e executar a partir da raiz do projeto

```bash
# Questão 1
gcc -Wall -Wextra -O2 exercicios/questao1/rsa_pollard.c -o exercicios/questao1/rsa_pollard && exercicios/questao1/rsa_pollard

# Questão 2
gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas && exercicios/questao2/chaves_periodicas

# Questão 3
gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia && exercicios/questao3/razao_eficiencia

# Questão 4
gcc -Wall -Wextra -O2 exercicios/questao4/bonus.c -o exercicios/questao4/bonus && exercicios/questao4/bonus
```

### Requisitos

- **Compilador:** GCC (GNU Compiler Collection)
- **Sistema:** Linux/Unix (testado em Ubuntu 24.04.2 LTS)
- **Bibliotecas:** Apenas bibliotecas padrão C (stdio.h, stdlib.h, string.h)

---

## 📚 Descrição dos Exercícios

### Questão 1: Sistema RSA com Fatoração ρ de Pollard
Implementação completa de criptografia RSA com:
- Fatoração usando método ρ de Pollard
- Algoritmo de Euclides e Euclides Estendido
- Geração de chaves RSA
- Exponenciação modular com teoremas de Fermat e Euler
- Codificação/decodificação de mensagens

**[Ver documentação completa →](exercicios/questao1/rsa_pollard_README.md)**

### Questão 2: Chaves Periódicas
Cálculo do Mínimo Múltiplo Comum (MMC) para sincronização de chaves com períodos diferentes.
- Algoritmo de Euclides para MDC
- Cálculo de MMC acumulado
- Validação de limite de 50 anos

**[Ver documentação completa →](exercicios/questao2/questao2_README.md)**

### Questão 3: Razão de Eficiência de um Número
Cálculo da razão σ(N)/τ(N) (média aritmética dos divisores):
- Fatoração prima por Trial Division
- Função Tau: número de divisores
- Função Sigma: soma dos divisores
- Cálculo da razão de eficiência

**[Ver documentação completa →](exercicios/questao3/questao3_README.md)**

### Questão 4: Análise de Código (Bônus)
Análise e classificação de afirmativas sobre:
- Algoritmo de Euclides Estendido
- Inverso modular
- Divisão modular
- Teoremas de Fermat e Euler
- Exponenciação modular

**[Ver documentação completa →](exercicios/questao4/questao4_README.md)**

---

## 🧪 Testes Automatizados

O repositório inclui um script de testes para a Questão 1 (Sistema RSA):

```bash
# Executar todos os testes
./test_rsa.sh

# Dar permissão de execução (se necessário)
chmod +x test_rsa.sh
```

O script testa:
- ✅ Validação de entrada (N1, N2 no intervalo correto)
- ✅ Verificação de números distintos
- ✅ Detecção de quadrados perfeitos
- ✅ Validação de fatores primos
- ✅ Casos de uso reais com mensagens

---

## 📖 Conceitos Abordados

- **Teoria dos Números:** Primalidade, fatoração, MDC, MMC
- **Criptografia:** Sistema RSA, chaves públicas e privadas
- **Aritmética Modular:** Exponenciação, inverso modular
- **Teoremas:** Pequeno Teorema de Fermat, Teorema de Euler
- **Algoritmos:** Euclides, Euclides Estendido, Pollard ρ, Trial Division
- **Funções Aritméticas:** Totiente de Euler (φ), Tau (τ), Sigma (σ)

---

- **exercicios/**: Diretório para os códigos dos exercícios, organizados em listas.
- **docs/**: Arquivos de explicações, anotações ou resumos sobre os temas abordados.
- **README.md**: Este arquivo, com as informações gerais do projeto.
- **questao_4_README.md**: Este arquivo é referente à questão 4 e possui a saída do primeiro exercício e as respostas em V ou F do segundo exercício.

---

## 📁 Arquivos do Projeto

| Arquivo | Descrição |
|---------|-----------|
| [README.md](README.md) | Documentação principal do projeto |
| [INDEX.md](INDEX.md) | Índice completo com links para todos os arquivos |
| [COMPILACAO.md](COMPILACAO.md) | Guia completo de compilação passo a passo |
| [CHEATSHEET.md](CHEATSHEET.md) | Comandos rápidos (cheat sheet) |
| [test_rsa.sh](test_rsa.sh) | Script de testes automatizados |
| [LICENSE](LICENSE) | Licença MIT do projeto |

---

## Licença

Este repositório está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais informações.

---
