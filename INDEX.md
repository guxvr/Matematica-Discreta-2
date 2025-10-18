# 📚 Índice Completo do Projeto

## 🎯 Acesso Rápido

| Item | Link |
|------|------|
| 🏠 **Início** | [README.md](README.md) |
| 📘 **Guia de Compilação** | [COMPILACAO.md](COMPILACAO.md) |
| ⚡ **Cheat Sheet** | [CHEATSHEET.md](CHEATSHEET.md) |

---

## 📝 Documentação por Questão

### Questão 1: Sistema RSA com Fatoração ρ de Pollard
- 📄 **Código:** [rsa_pollard.c](exercicios/questao1/rsa_pollard.c)
- 📖 **Documentação:** [rsa_pollard_README.md](exercicios/questao1/rsa_pollard_README.md)
- 🎯 **Compilar:**
  ```bash
  cd exercicios/questao1
  gcc -Wall -Wextra -O2 rsa_pollard.c -o rsa_pollard
  ./rsa_pollard
  ```

### Questão 2: Chaves Periódicas (MMC)
- 📄 **Código:** [chaves_periodicas.c](exercicios/questao2/chaves_periodicas.c)
- 📖 **Documentação:** [questao2_README.md](exercicios/questao2/questao2_README.md)
- 🎯 **Compilar:**
  ```bash
  cd exercicios/questao2
  gcc -Wall -Wextra -O2 chaves_periodicas.c -o chaves_periodicas
  ./chaves_periodicas
  ```

### Questão 3: Razão de Eficiência de um Número
- 📄 **Código:** [razao_eficiencia.c](exercicios/questao3/razao_eficiencia.c)
- 📖 **Documentação:** [questao3_README.md](exercicios/questao3/questao3_README.md)
- 🎯 **Compilar:**
  ```bash
  cd exercicios/questao3
  gcc -Wall -Wextra -O2 razao_eficiencia.c -o razao_eficiencia
  ./razao_eficiencia
  ```

### Questão 4: Análise de Código (Bônus)
- 📄 **Código:** [bonus.c](exercicios/questao4/bonus.c)
- 📖 **Documentação:** [questao4_README.md](exercicios/questao4/questao4_README.md)
- 🎯 **Compilar:**
  ```bash
  cd exercicios/questao4
  gcc -Wall -Wextra -O2 bonus.c -o bonus
  ./bonus
  ```

---

## 🔍 Busca por Tópico

### Criptografia
- [RSA - Questão 1](exercicios/questao1/rsa_pollard_README.md)
- Fatoração ρ de Pollard
- Geração de chaves públicas/privadas

### Teoria dos Números
- [MDC/MMC - Questão 2](exercicios/questao2/questao2_README.md)
- [Funções Aritméticas - Questão 3](exercicios/questao3/questao3_README.md)
- Primalidade e Fatoração

### Aritmética Modular
- [RSA - Questão 1](exercicios/questao1/rsa_pollard_README.md)
- [Análise - Questão 4](exercicios/questao4/questao4_README.md)
- Exponenciação modular
- Inverso modular

### Algoritmos
- Euclides (MDC)
- Euclides Estendido
- Pollard ρ
- Trial Division
- Exponenciação binária

---

## 🧪 Testes e Validação

- **Script de testes:** [test_rsa.sh](test_rsa.sh)
- **Executar:** `./test_rsa.sh`

---

## 📊 Estrutura de Arquivos

```
Matematica-Discreta-2/
├── README.md              ← Você está aqui
├── INDEX.md               ← Este arquivo
├── COMPILACAO.md          ← Guia passo a passo
├── CHEATSHEET.md          ← Comandos rápidos
├── test_rsa.sh            ← Testes automatizados
└── exercicios/
    ├── questao1/
    ├── questao2/
    ├── questao3/
    └── questao4/
```

---

## 📞 Suporte

### Problemas com compilação?
👉 Consulte: [COMPILACAO.md](COMPILACAO.md)

### Precisa de comandos rápidos?
👉 Consulte: [CHEATSHEET.md](CHEATSHEET.md)

### Quer entender o código?
👉 Veja os READMEs específicos de cada questão

---

**Autor:** Gustavo Xavier Evangelista - 241025247  
**Disciplina:** Matemática Discreta 2  
**UnB - Engenharia de Software**
