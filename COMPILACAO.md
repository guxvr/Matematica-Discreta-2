# 🔨 Guia Completo de Compilação

Este guia detalha passo a passo como compilar e executar cada exercício do projeto.

---

## 📋 Pré-requisitos

Antes de começar, certifique-se de ter:
- ✅ GCC (GNU Compiler Collection) instalado
- ✅ Terminal/linha de comando disponível
- ✅ Sistema Linux/Unix (ou WSL no Windows)

Para verificar se o GCC está instalado:
```bash
gcc --version
```

---

## 🗂️ Estrutura de Diretórios

```
Matematica-Discreta-2/          ← Raiz do projeto
├── exercicios/
│   ├── questao1/               ← Entre aqui para questão 1
│   │   ├── rsa_pollard.c
│   │   └── rsa_pollard_README.md
│   ├── questao2/               ← Entre aqui para questão 2
│   │   ├── chaves_periodicas.c
│   │   └── questao2_README.md
│   ├── questao3/               ← Entre aqui para questão 3
│   │   ├── razao_eficiencia.c
│   │   └── questao3_README.md
│   └── questao4/               ← Entre aqui para questão 4
│       ├── bonus.c
│       └── questao4_README.md
└── README.md
```

---

## 🎯 Método 1: Compilar de Dentro da Pasta (Recomendado)

### Questão 1: Sistema RSA

**Passo 1 - Entrar no diretório:**
```bash
cd exercicios/questao1
```

**Passo 2 - Compilar:**
```bash
gcc -Wall -Wextra -O2 rsa_pollard.c -o rsa_pollard
```

**Passo 3 - Executar:**
```bash
./rsa_pollard
```

**Passo 4 - Voltar para a raiz (opcional):**
```bash
cd ../..
```

---

### Questão 2: Chaves Periódicas

**Passo 1 - Entrar no diretório:**
```bash
cd exercicios/questao2
```

**Passo 2 - Compilar:**
```bash
gcc -Wall -Wextra -O2 chaves_periodicas.c -o chaves_periodicas
```

**Passo 3 - Executar:**
```bash
./chaves_periodicas
```

**Passo 4 - Voltar para a raiz (opcional):**
```bash
cd ../..
```

---

### Questão 3: Razão de Eficiência

**Passo 1 - Entrar no diretório:**
```bash
cd exercicios/questao3
```

**Passo 2 - Compilar:**
```bash
gcc -Wall -Wextra -O2 razao_eficiencia.c -o razao_eficiencia
```

**Passo 3 - Executar:**
```bash
./razao_eficiencia
```

**Passo 4 - Voltar para a raiz (opcional):**
```bash
cd ../..
```

---

### Questão 4: Bônus

**Passo 1 - Entrar no diretório:**
```bash
cd exercicios/questao4
```

**Passo 2 - Compilar:**
```bash
gcc -Wall -Wextra -O2 bonus.c -o bonus
```

**Passo 3 - Executar:**
```bash
./bonus
```

**Passo 4 - Voltar para a raiz (opcional):**
```bash
cd ../..
```

---

## 🚀 Método 2: Compilar da Raiz do Projeto

Este método é útil quando você quer compilar e executar sem mudar de diretório.

**Certifique-se de estar na raiz do projeto:**
```bash
# Verificar diretório atual
pwd
# Deve mostrar algo como: /caminho/para/Matematica-Discreta-2

# Se não estiver na raiz, navegue até ela
cd /caminho/para/Matematica-Discreta-2
```

### Questão 1 - Uma linha (compila e executa)
```bash
gcc -Wall -Wextra -O2 exercicios/questao1/rsa_pollard.c -o exercicios/questao1/rsa_pollard && exercicios/questao1/rsa_pollard
```

### Questão 2 - Uma linha (compila e executa)
```bash
gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas && exercicios/questao2/chaves_periodicas
```

### Questão 3 - Uma linha (compila e executa)
```bash
gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia && exercicios/questao3/razao_eficiencia
```

### Questão 4 - Uma linha (compila e executa)
```bash
gcc -Wall -Wextra -O2 exercicios/questao4/bonus.c -o exercicios/questao4/bonus && exercicios/questao4/bonus
```

---

## 📝 Compilar Apenas (sem executar)

Se você quiser compilar todos os programas sem executá-los:

```bash
# Da raiz do projeto
gcc -Wall -Wextra -O2 exercicios/questao1/rsa_pollard.c -o exercicios/questao1/rsa_pollard
gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas
gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia
gcc -Wall -Wextra -O2 exercicios/questao4/bonus.c -o exercicios/questao4/bonus
```

Depois você pode executar individualmente:
```bash
exercicios/questao1/rsa_pollard
exercicios/questao2/chaves_periodicas
exercicios/questao3/razao_eficiencia
exercicios/questao4/bonus
```

---

## 🔍 Entendendo os Parâmetros do GCC

| Parâmetro | Descrição |
|-----------|-----------|
| `-Wall` | Habilita todos os warnings comuns |
| `-Wextra` | Habilita warnings extras além do `-Wall` |
| `-O2` | Otimização de nível 2 (código mais rápido) |
| `-o nome` | Define o nome do executável de saída |

**Exemplo completo:**
```bash
gcc -Wall -Wextra -O2 arquivo_fonte.c -o nome_executavel
│   │     │       │   │                │
│   │     │       │   │                └─ Nome do programa compilado
│   │     │       │   └─ Arquivo .c (código-fonte)
│   │     │       └─ Otimização nível 2
│   │     └─ Warnings extras
│   └─ Todos os warnings
└─ Compilador GCC
```

---

## ⚠️ Problemas Comuns

### Erro: "gcc: command not found"
**Solução:** Instale o GCC
```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential

# Fedora
sudo dnf install gcc

# Arch Linux
sudo pacman -S gcc
```

### Erro: "No such file or directory"
**Solução:** Verifique se está no diretório correto
```bash
# Listar arquivos do diretório atual
ls

# Ver caminho completo do diretório atual
pwd

# Navegar para a raiz do projeto
cd /caminho/completo/para/Matematica-Discreta-2
```

### Erro: "Permission denied" ao executar
**Solução:** Dê permissão de execução
```bash
chmod +x nome_do_executavel
# ou
chmod +x exercicios/questao1/rsa_pollard
```

### Warnings durante a compilação
**Nota:** Alguns warnings sobre scanf não usado podem aparecer. Eles são avisos, não erros, e o programa funcionará normalmente.

---

## 🧪 Testes Automatizados (Questão 1)

Para executar os testes da Questão 1:

```bash
# Da raiz do projeto
./test_rsa.sh

# Se necessário, dar permissão de execução
chmod +x test_rsa.sh
./test_rsa.sh
```

---

## 📚 Links Úteis

- [README Principal](README.md)
- [Questão 1 - RSA](exercicios/questao1/rsa_pollard_README.md)
- [Questão 2 - Chaves Periódicas](exercicios/questao2/questao2_README.md)
- [Questão 3 - Razão de Eficiência](exercicios/questao3/questao3_README.md)
- [Questão 4 - Análise de Código](exercicios/questao4/questao4_README.md)

---

## 💡 Dicas Extras

1. **Use Tab para autocompletar:** Digite parte do nome do arquivo/pasta e pressione Tab
2. **Histórico de comandos:** Use as setas ↑ e ↓ para navegar pelos comandos anteriores
3. **Limpar terminal:** Digite `clear` ou pressione `Ctrl+L`
4. **Cancelar programa em execução:** Pressione `Ctrl+C`

---

**Autor:** Gustavo Xavier Evangelista - 241025247  
**Disciplina:** Matemática Discreta 2  
**UnB - Engenharia de Software**
