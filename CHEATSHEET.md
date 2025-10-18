# ⚡ Comandos Rápidos - Cheat Sheet

## 📍 Navegação Básica

```bash
# Ir para a raiz do projeto
cd /workspaces/Matematica-Discreta-2

# Entrar em uma pasta específica
cd exercicios/questao1
cd exercicios/questao2
cd exercicios/questao3
cd exercicios/questao4

# Voltar um nível
cd ..

# Voltar para a raiz (de qualquer lugar)
cd ../..

# Ver onde você está
pwd

# Listar arquivos
ls
ls -la  # com detalhes
```

---

## 🔨 Compilação - Comando Único

**Da raiz do projeto:**

```bash
# Questão 1 - RSA
gcc -Wall -Wextra -O2 exercicios/questao1/rsa_pollard.c -o exercicios/questao1/rsa_pollard && exercicios/questao1/rsa_pollard

# Questão 2 - Chaves Periódicas
gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas && exercicios/questao2/chaves_periodicas

# Questão 3 - Razão de Eficiência
gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia && exercicios/questao3/razao_eficiencia

# Questão 4 - Bônus
gcc -Wall -Wextra -O2 exercicios/questao4/bonus.c -o exercicios/questao4/bonus && exercicios/questao4/bonus
```

---

## 📂 Compilação - De Dentro da Pasta

```bash
# Questão 1
cd exercicios/questao1
gcc -Wall -Wextra -O2 rsa_pollard.c -o rsa_pollard
./rsa_pollard

# Questão 2
cd exercicios/questao2
gcc -Wall -Wextra -O2 chaves_periodicas.c -o chaves_periodicas
./chaves_periodicas

# Questão 3
cd exercicios/questao3
gcc -Wall -Wextra -O2 razao_eficiencia.c -o razao_eficiencia
./razao_eficiencia

# Questão 4
cd exercicios/questao4
gcc -Wall -Wextra -O2 bonus.c -o bonus
./bonus
```

---

## 🔄 Compilar Tudo de Uma Vez

**Da raiz do projeto:**

```bash
gcc -Wall -Wextra -O2 exercicios/questao1/rsa_pollard.c -o exercicios/questao1/rsa_pollard && \
gcc -Wall -Wextra -O2 exercicios/questao2/chaves_periodicas.c -o exercicios/questao2/chaves_periodicas && \
gcc -Wall -Wextra -O2 exercicios/questao3/razao_eficiencia.c -o exercicios/questao3/razao_eficiencia && \
gcc -Wall -Wextra -O2 exercicios/questao4/bonus.c -o exercicios/questao4/bonus && \
echo "✅ Todos os programas compilados com sucesso!"
```

---

## 🧪 Testes

```bash
# Executar testes da Questão 1
./test_rsa.sh

# Dar permissão de execução (se necessário)
chmod +x test_rsa.sh
```

---

## 🗑️ Limpeza

```bash
# Remover executáveis (da raiz)
rm -f exercicios/questao1/rsa_pollard
rm -f exercicios/questao2/chaves_periodicas
rm -f exercicios/questao3/razao_eficiencia
rm -f exercicios/questao4/bonus

# Remover todos de uma vez
rm -f exercicios/questao*/questao*
rm -f exercicios/questao1/rsa_pollard exercicios/questao2/chaves_periodicas exercicios/questao3/razao_eficiencia exercicios/questao4/bonus
```

---

## 🎯 Exemplos de Entrada

### Questão 1 - RSA
```
N1: 187
N2: 209
Mensagem: OLA MUNDO
```

### Questão 2 - Chaves Periódicas
```
Número de chaves: 3
Ciclo 1: 4
Ciclo 2: 6
Ciclo 3: 8
```

### Questão 3 - Razão de Eficiência
```
N: 12
```

---

## ⌨️ Atalhos Úteis

| Atalho | Ação |
|--------|------|
| `Ctrl+C` | Cancelar programa |
| `Ctrl+L` | Limpar terminal |
| `↑` / `↓` | Navegar histórico |
| `Tab` | Autocompletar |
| `Ctrl+R` | Buscar no histórico |

---

## 📚 Links Rápidos

- [README Principal](README.md)
- [Guia Completo de Compilação](COMPILACAO.md)
- [Questão 1](exercicios/questao1/rsa_pollard_README.md)
- [Questão 2](exercicios/questao2/questao2_README.md)
- [Questão 3](exercicios/questao3/questao3_README.md)
- [Questão 4](exercicios/questao4/questao4_README.md)
