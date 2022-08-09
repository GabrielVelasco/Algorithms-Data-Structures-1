#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define E 1e5

int main(int argc, char *argv[]){
    int n = atoi(argv[1]), in;
    if(n > 30 || n < 1)
        printf("Numero nao pode ser > 30 ou <= 0\n");
    
    else{
        int *arr = malloc(n*sizeof(int));
        for(int i = 0; i < n; i++)
            arr[i] = E;

        for(int _ = 0; _ < n; _ ++){
            scanf("%d", &in);

            for(int i = 0; i < n; i++){
                if(in < arr[i]){
                    for(int j = n-1; j >= i+1; j--)
                        arr[j] = arr[j-1];
                    arr[i] = in;
                    break;

                }else if(arr[i] == E){
                    arr[i] = in;
                    break;
                }
            }

        }

        printf("Resultado final:\n");
        for(int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");

        free(arr);
    }

    return 0;
}