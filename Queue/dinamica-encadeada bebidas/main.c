#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

int main(){
    Queue qu;
    bool ch = true, quit = false;
    int opc, vol;
    float prc;
    char data[50];
    while(true){
        printf("\n0 - Create queue\n");
        printf("1 - Push back\n");
        printf("2 - Pop front\n");
        printf("3 - Print queue\n");
        printf("4 - Erase queue\n");
        printf("5 - Clean queue\n");
        printf("Option: ");
        scanf("%d", &opc);

        switch(opc){
            case 0:
                qu = _create_queue();
                ch = true;
                printf("Queue created!\n");
                break;

            case 5:
                /// apenas reseta a queue para estado de vazia, nao libera os nodes
                qu = _create_queue();
                ch = true;
                printf("Queue cleaned!\n");
                break;

            case 1:
                printf("Push back name, vol, price: \n");
                scanf(" %[^\n]", data);
                scanf("%d%f", &vol, &prc);
                if(_push_back(qu, data, vol, prc))
                    printf("Push back success!\n");
                break;

            case 2:
                if(_pop_front(qu, data))
                    printf("Pop front success, [%s] removed!\n", data);
                else
                    printf("Pop_front error!\n");
                break;

            case 3:
                if(_print(qu))
                    printf("Queue printed!\n");
                else
                    printf("Queue is empty or not initialized!\n");
                break;

            case 4:
                /// so pode deletar a queue se ela existir (se ch == 1)
                /// para voltar a usar a queue eh necessario cria-la novamente (opc: 0)
                if(ch) _erase_queue(&qu);
                ch = false;
                printf("Queue erased!\n");
                break;

            default:
                quit = true;
        }
        if(quit) break;
    }

    return 0;
}