#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(){
    Queue qu;
    int opc;
    char data[12];
    while(1){
        printf("\n0 - Create queue\n");
        printf("1 - Push back\n");
        printf("2 - Pop front\n");
        printf("3 - Print queue\n");
        printf("Option: ");
        scanf("%d", &opc); getchar();

        switch(opc){
            case 0:
                qu = _create_queue();
                printf("Queue created!\n");
                break;

            case 1:
                printf("Push back: \n");
                scanf("%s", data);
                if(_push_back(qu, data))
                    printf("Push success!\n");
                else
                    printf("Error while inserting!\n");
                break;

            case 2:
                if(_pop_front(qu, data))
                    printf("Pop success, [%s] removed!\n", data);
                else
                    printf("Pop_front error!\n");
                break;

            case 3:
                _print(qu);
                break;

            default:
                return 0;
        }
    }

    return 0;
}