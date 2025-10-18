#!/usr/bin/env bash
# Script de testes automatizados para questao1/rsa_pollard.c
# Autor: Gustavo Xavier Evangelista

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

BIN="./questao1/rsa_pollard"
PASSED=0
FAILED=0

echo "=========================================="
echo "Testes Automatizados: RSA com Pollard ρ"
echo "=========================================="
echo ""

# Helper: executar teste esperando sucesso
test_success() {
    local name="$1"
    local input="$2"
    local expected_msg="$3"
    
    echo -n "[$((PASSED+FAILED+1))] $name... "
    
    output=$(echo -e "$input" | $BIN 2>&1)
    code=$?
    
    if [[ $code -eq 0 ]] && echo "$output" | grep -q "$expected_msg"; then
        echo -e "${GREEN}PASS${NC}"
        ((PASSED++))
    else
        echo -e "${RED}FAIL${NC}"
        echo "  Esperado: código 0 e mensagem '$expected_msg'"
        echo "  Obtido: código $code"
        echo "  Saída resumida:"
        echo "$output" | tail -5 | sed 's/^/    /'
        ((FAILED++))
    fi
}

# Helper: executar teste esperando falha
test_failure() {
    local name="$1"
    local input="$2"
    local expected_err="$3"
    
    echo -n "[$((PASSED+FAILED+1))] $name... "
    
    output=$(echo -e "$input" | $BIN 2>&1)
    code=$?
    
    if [[ $code -ne 0 ]] && echo "$output" | grep -q "$expected_err"; then
        echo -e "${GREEN}PASS${NC}"
        ((PASSED++))
    else
        echo -e "${RED}FAIL${NC}"
        echo "  Esperado: código ≠ 0 e mensagem '$expected_err'"
        echo "  Obtido: código $code"
        echo "  Saída resumida:"
        echo "$output" | tail -5 | sed 's/^/    /'
        ((FAILED++))
    fi
}

echo "=== Testes de Validação de Entrada ==="
test_failure "N1 fora da faixa (99)" "99\n200" "N1 fora da faixa"
test_failure "N1 fora da faixa (10000)" "10000\n200" "N1 fora da faixa"
test_failure "N2 fora da faixa (50)" "200\n50" "N2 fora da faixa"
test_failure "N1 = N2" "391\n391" "N1 e N2 devem ser distintos"

echo ""
echo "=== Testes de Fatoração Inválida ==="
test_failure "N1 primo (997)" "997\n209" "Falha ao fatorar N1"
test_failure "N2 primo (211)" "391\n211" "Falha ao fatorar N2"
test_failure "N1 quadrado de primo (121=11²)" "121\n209" "quadrado perfeito"
test_failure "N2 quadrado de primo (169=13²)" "391\n169" "quadrado perfeito"
test_failure "N1 e N2 com primo compartilhado (391=17×23, 437=19×23)" "391\n437\nTESTE" "compartilham o mesmo fator primo"

echo ""
echo "=== Testes de n Inválido ==="
# Nota: Difícil criar teste realista para n<=36 pois N>=100 naturalmente gera n>36
# Removido: test_failure "n muito pequeno (N1=15, N2=21, n=35)" "15\n21" "n=.*<= 36"

echo ""
echo "=== Testes Válidos (Casos de Sucesso) ==="
test_success "Caso válido 1: N1=391(17×23), N2=209(11×19), msg='TESTE'" "391\n209\nTESTE" "Confirmação: Ok"
test_success "Caso válido 2: N1=187(11×17), N2=299(13×23), msg='ABC'" "187\n299\nABC" "Confirmação: Ok"
test_success "Caso válido 3: N1=437(19×23), N2=209(11×19), msg='OLA MUNDO'" "437\n209\nOLA MUNDO" "Confirmação: Ok"
test_success "Caso válido 4: Mensagem com espaços e maiúsculas/minúsculas" "391\n209\nCRIS LOESCH" "Confirmação: Ok"

echo ""
echo "=== Testes de Borda ==="
# Mensagem vazia (enter direto) - esperamos que codifique 0 símbolos e passe
test_success "Mensagem vazia" "391\n209\n" "Confirmação: Ok"
# Mensagem só com espaços
test_success "Mensagem com espaços" "391\n209\n   " "Confirmação: Ok"

echo ""
echo "=========================================="
echo -e "Resultados: ${GREEN}$PASSED passaram${NC}, ${RED}$FAILED falharam${NC}"
echo "=========================================="

if [[ $FAILED -eq 0 ]]; then
    echo -e "${GREEN}Todos os testes passaram!${NC}"
    exit 0
else
    echo -e "${RED}Alguns testes falharam.${NC}"
    exit 1
fi
