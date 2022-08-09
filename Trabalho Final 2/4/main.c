#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fila.h"

void printa_fila(Fila f){
    int ca, fi, ch;
    if(fila_vazia(f)){
        printf("Fila vazia!\n");
        return;
    }
    Fila aux = cria_fila();
    while(remove_cliente(f, &ca, &fi, &ch)){
        printf("%d %d %d\n", ca, fi, ch);
        insere_cliente(aux, ca, fi, ch);
    }
    while(remove_cliente(aux, &ca, &fi, &ch))
        insere_cliente(f, ca, fi, ch);
}

void avanca_tempo(Fila f){
    if(fila_vazia(f))
        return;
    int ca, fi, ch;
    Fila aux = cria_fila();
    while(remove_cliente(f, &ca, &fi, &ch)){
        insere_cliente(aux, ca, fi, ch);
    }
    while(remove_cliente(aux, &ca, &fi, &ch))
        insere_cliente(f, ca, fi+1, ch);
}

float media_espera(Fila f){
    if(fila_vazia(f))
        return 0;
    int ca, fi, ch, tm;
    float cnt = 0;
    Fila aux = cria_fila();
    tm = tamanho_fila(f);
    if(tm > 5){
        while(remove_cliente(f, &ca, &fi, &ch)){
            insere_cliente(aux, ca, fi, ch);
            tm--;
            if(tm <= 5)
                break;
        }
    }
    while(remove_cliente(f, &ca, &fi, &ch)){
        insere_cliente(aux, ca, fi, ch);
        cnt += fi;
    }
    while(remove_cliente(aux, &ca, &fi, &ch))
        insere_cliente(f, ca, fi, ch);
    cnt /= 5;
    return cnt;
}

int remove_caixa(Fila f){
    if(fila_vazia(f))
        return 0;
    int ca, fi, ch, cnt = 0;
    Fila aux = cria_fila();
    while(remove_cliente(f, &ca, &fi, &ch)){
        if(ca > fi)
            insere_cliente(aux, ca, fi, ch);
        else{
            cnt++;
        }
    }
    while(remove_cliente(aux, &ca, &fi, &ch))
        insere_cliente(f, ca, fi, ch);
    return cnt;
}

int main()
{
    int opt, qt, tca, tfi, tch, tempo = 0, qtcaixas = 0, rmv;
    //cli_fila = clientes na fila
    //cli_caixa = clientes no caixa
    Fila cli_fila = cria_fila(), cli_caixa = cria_fila();

    while(1){
        printf("MENU\n");
        printf("[1]- Inserir clientes na fila\n");
        printf("[2]- Avancar uma unidade de tempo\n");
        printf("[3]- Detalhes cenario\n");
        printf("[4]- Fila visual\n");
        scanf("%d", &opt);
        if(opt == 1){
            printf("Quantidade de clientes entrando: ");
            scanf("%d", &qt);
            for(int i = 0; qt > i; i++){
                tca = (rand() % 9) + 2;
                if(!insere_cliente(cli_fila, tca, 0, tempo)){
                    printf("Erro ao inserir!\n");
                    break;
                }
            }
            printf("Clientes inseridos!\n");
        }
        if(opt == 2){
            tempo++;
            avanca_tempo(cli_fila);
            avanca_tempo(cli_caixa);
            printf("Tempo Decorrido: %d.\n", tempo);
            printf("Otimizando...\n\n");
            //OTIMIZAÇÂO
            //VERIFICAR SE ALGUM CLIENTE SAI DO CAIXA
            rmv = remove_caixa(cli_caixa);
            if(rmv > 0)
                printf("%d Caixas liberados!\n", rmv);
            //ABERTURA DE CAIXAS
            while(qtcaixas <= 8){
                if(media_espera(cli_fila) >= 27 || tamanho_fila(cli_fila) >= 12){
                    remove_cliente(cli_fila, &tca, &tfi, &tch);
                    insere_cliente(cli_caixa, tca, 0, tempo);
                    qtcaixas++;
                    printf("Caixa %d aberto.\n", qtcaixas);
                }
                else
                    break;
            }
            //FECHA CAIXAS EXTRAS
            while(qtcaixas >= 0){
                if(qtcaixas <= tamanho_fila(cli_caixa))
                    break;
                else if(media_espera(cli_fila) < 18 && tamanho_fila(cli_fila) < 9){
                    qtcaixas--;
                }
                else
                    break;
            }
            //AVANÇO DE CLIENTES PARA CAIXAS ABERTOS E DISPONÍVEIS
            //APÓS CALCULO DE QUANTOS CAIXAS SERÃO ABERTOS/FECHADOS
            while(qtcaixas > tamanho_fila(cli_caixa)){
                remove_cliente(cli_fila, &tca, &tfi, &tch);
                insere_cliente(cli_caixa, tca, 0, tempo);
            }
        }
        if(opt == 3){
            printf("Caixas abertos: %d\n", qtcaixas);
            printf("Pessoas na fila: %d\n", tamanho_fila(cli_fila));
            printf("Tempo medio espera(ultimos 5 da fila): %.2f\n\n", media_espera(cli_fila));
        }
        if(opt == 4){
            printf("CLIENTES:\n");
            printa_fila(cli_fila);
            printf("CAIXAS:\n");
            printa_fila(cli_caixa);
        }
    }
    return 0;
}
