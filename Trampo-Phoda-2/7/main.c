#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "deque.h"


void _print_node(int data){
    /// usado em conjunto com funcao void _print.
    printf("[%d] ", data);
}

bool _print_deque(Deque de){
    if(_empty_deque(de)) return false;
    int data;
    Deque piv = _create_deque();
    while(_pop_front(de, &data)){
        printf("[%d] ", data);
        if(!_push_back(piv, data))
            printf("Error at pushing to piv deque.\n");
    }
    printf("    \n");

    while(_pop_front(piv, &data)){
        if(!_push_back(de, data))
            printf("Error at pushing to piv deque.\n");
    }

    free(piv);

    return true;
}

int main(){
    Deque de = NULL;
    int opc, ch = 0, data;

    while(1){
        printf("\n0 - Create deque\n");
        printf("1 - Push back\n");
        printf("2 - Push front\n");
        printf("3 - Pop back\n");
        printf("4 - Pop front\n");
        printf("5 - Print deque\n");
        printf("6 - Delete deque\n");
        printf("Option: ");
        scanf("%d", &opc); getchar();

        switch(opc){
            case 0:
                de = _create_deque();
                printf("Deque created!\n");
                ch = 1;
                break;

            case 1:
                if(!ch){
                    printf("Deque not initialized.\n");
                    break;
                }
                printf("Push back, type a number: ");
                scanf("%d", &data);
                if(_push_back(de, data))
                    printf("Success!\n");
                else
                    printf("Deque is full!\n");

                break;

            case 2:
                if(!ch){
                    printf("Deque not initialized.\n");
                    break;
                }
                printf("Push front, type a number: ");
                scanf("%d", &data);
                if(_push_front(de, data))
                    printf("Success!\n");
                else
                    printf("Deque is full!\n");
                break;

            case 3:
                if(!ch){
                    printf("Deque not initialized.\n");
                    break;
                }
                if(_pop_back(de, &data))
                    printf("[%d] removed!\n", data);
                else
                    printf("Deque is empty!\n");

                break;


            case 4:
                if(!ch){
                    printf("Deque not initialized.\n");
                    break;
                }
                if(_pop_front(de, &data))
                    printf("[%d] removed!\n", data);
                else
                    printf("Deque is empty!\n");

                break;

            case 5:
                if(!ch){
                    printf("Deque not initialized.\n");
                }else{
                    if(!_print_deque(de))
                        printf("Deque is empty!\n");
                }
                break;

            case 6:
                if(!ch){
                    printf("Deque not initialized.\n");
                }else{
                    _delete_deque(&de);
                    printf("Deque has been deleted!\n");
                    ch = 0;
                }
                break;

            default:
                ch = 2;
        }

        if(ch == 2)
            break;
    }

    return 0;
}