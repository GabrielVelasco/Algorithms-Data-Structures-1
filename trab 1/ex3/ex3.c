#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insere(int arr[], int n){
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
}

float tiraMedia(int arr[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    
    return (sum/(float)n);
}

int scaneia(int arr[], int n, float media){
    int cont = 0;
    for(int i = 0; i < n; i++)
        if(arr[i] > media) 
            cont ++;

    return cont;
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    if(n > 15){
        printf("Numero maior que 15\n");
    
    }else{
        int *arr = malloc(n*sizeof(int));
        insere(arr, n);
        float media = tiraMedia(arr, n);
        int ans = scaneia(arr, n, media);
        printf("%d numero sao maiores que a media %.2f\n", ans, media);

        free(arr);
    }

    return 0;
}