#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

/*
    Para entender melhor o funcionamento das funoces _solve_post_fix()
    _infix_to_post() e _is_valid() recomendo ver o video sobre pilha do prof.
    Entendi que o usuario realizaria uma sequencia de 3 passos, validacao, conversao
    e avaliacao/resolucao da expressao de entrada, caso o usuario queira mudar
    fazer apenas uma coisa ou outra basta mudar o app atentando-se que uma 
    funcao as vezes vai depender da outra, ex; _solve..() depende da _infix_to..().

    Como eh usado a math.h caso for compilar no terminal tem que linkar
    usando: gcc -o exec main.c stack.c -lm
*/

int _preced_op(char op){
    /// calcula precedencia dos operadores
    if(op == '^') return 3;
    else if(op == '*' || op == '/') return 2;
    else if(op == '+' || op == '-') return 1;
    else return 0;
}

void _print_elem(char c_data, float f_data, int key){
    if(key)
        printf("[%.2f] ", f_data);
    else
        printf("[%c] ", c_data);
}

void _empty_msg(){
    printf("Stack is empty!\n");
}

int _is_valid(Stack *S, char exp[]){
    /// return 1 se exp valida
    /// return 0 se exp tem erro de precedencia
    /// return -1 se exp tem erro de ordem
    char data;
    float tmp;
    for(int i = 0; exp[i] != '\0'; i++){
        /// se exp[i] for abertura vou empilha-lo SE stack estiver vazia OU
        /// se a precedencia (valor do caractere '(', '[' ou '{' na tabela ascii) 
        /// de exp[i] for <= a precedencia de data (elemento do topo da stack)
        /// caso contrario tenho erro de precedencia
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            if(!_get_top(S, &data) || exp[i] <= data)
                _push(S, exp[i], 0, 0);
            else{
                return 0;
            }

        }else if(exp[i] == ')'){
            /// se exp[i] == fechamento, desempilhar elemento do topo (data)
            /// se data (elemento do topo) != abertura, ou se stack estiver vazia, tenho um erro de ordem
            /// obs. abertura e fechamento de que ser do mesmo tipo.
            if(!_pop(S, &data, &tmp) || data != '('){
                return -1;
            }

        }else if(exp[i] == ']'){
            if(!_pop(S, &data, &tmp) || data != '['){
                return -1;
            }

        }else if(exp[i] == '}'){
            if(!_pop(S, &data, &tmp) || data != '{'){
                return -1;
            }
        }
    }

    if(_empty_stack(*S)) /// ao final se stack vazia == exp eh valida
        return 1;
    else
        return -1;
}

void _infix_to_post(Stack *S, char exp[]){
    /// eh garantido que a expressao aqui eh valida dado a sequencia de execucao das funcoes
    /// propostas no ex2.
    char ans[50], data; /// ans guarda exp pos-fixa
    int j = 0;
    float tmp;
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            _push(S, exp[i], 0, 0);

        else if((exp[i] >= '*' && exp[i] <= '/') || (exp[i] == '^')){
            while(_get_top(S, &data) && (_preced_op(data) >= _preced_op(exp[i]))){
                ans[j] = data;
                j++;
                _pop(S, &data);
            }
            _push(S, exp[i]);
        
        }else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            while(_get_top(S, &data) && (data != '(' && data != '[' && data != '{')){
                ans[j] = data;
                j++;
                _pop(S, &data, &tmp);
            }
            if(data == '(' || data == '[' || data == '{')
                _pop(S, &data, &tmp);
        
        }else{
            /// exp[i] eh operando
            ans[j] = exp[i];
            j++;
        }
    }

    while(_pop(S, &data, &tmp)){
        ans[j] = data;
        j++;
    }
    ans[j] = '\0';
    strcpy(exp, ans);
}

int _solve_post_fix(Stack *S, char pos[], float *r){
    /// return 0 se estiver faltando operandos, -1 se estiver faltando operadores, 1 sucesso.
    /// expressao tem que estar na forma pos-fixa e os operandos tem
    /// que ser digitos (0,1,...,9).
    char op;
    float x1, x2, n;
    for(int i = 0; pos[i] != '\0'; i++){
        if(pos[i] >= 'A' && pos[i] <= 'J'){
            printf("Digite o valor de [%c]: ", pos[i]);
            scanf("%f", &n);
            _push(S, '0', n, 1);
        
        }else{
            /// pos[i] == operador
            op = pos[i];
            if(!_pop(S, &op, &x2) || !_pop(S, &op, &x1))
                return 0;
            
            if(op == '+')
                *r = x1 + x2;
            else if(op == '-')
                *r = x1 - x2;
            else if(op == '*')
                *r = x1 * x2;
            else if(op == '/'){
                if(x2 == 0) 
                    return 2; /// nao pode divisao por 0
                *r = x1 / x2;
            }
            else if(op == '^')
                *r = pow(x1, x2);

            _push(S, '0', *r, 1);
        }
    }

    _pop(S, &op, r);
    if(_empty_stack(*S))
        return 1;
    else
        return -1;
}

int main(){
    int ch = 0;
    float r;
    char exp[50] = {0}; /// inicializa com strlen == 0
    Stack S = _create_stack(); // S aponta para o TOPO da stack

    while(1){
        printf("\nDigite uma expressao infixa ou '0' para sair: ");
        scanf("%s", exp);
        if(exp[0] == '0')
            break;
        ch = _is_valid(&S, exp);
        if(ch == 1){
            printf("Expressao valida, convertendo para pos-fixa...\n");
            _infix_to_post(&S, exp);

            printf("\nPost-fix: %s\n", exp);
            printf("\nAtribuir valores:\n");

            ch = _solve_post_fix(&S, exp, &r);
            if(ch == 1){
                printf("Resultado: %.2f\n", r);
            }else if(ch == 0){
                printf("Numero de operandos nao eh adequado!\n");
            }else if(ch == -1){
                printf("Numero de operadores nao eh adequado!\n");
            }else if(ch == 2)
                printf("Nao pode dividir por 0!\n");

        }else if(ch == 0)
            printf("Erro de precedencia!\n");
        else if(ch == -1)
            printf("Erro de ordem!\n");


        _clean(&S);
    }

    return 0;
}