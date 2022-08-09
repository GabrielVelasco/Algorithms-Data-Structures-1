#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcMfac(int m){
    for(int i = m-1; i > 0; i--)
        m *= i;
    
    return m;
}

int calcPfac(int p){
    for(int i = p-1; i > 0; i--)
        p *= i;
    
    return p;
}

int calcMPfac(int mp){
    for(int i = mp-1; i > 0; i--)
        mp *= i;
    
    return mp;
}

int calcFinal(int num, int den) {    return num / den;   }

int main(int argc, char *argv[]){
    int p, m, mfac, pfac, mpfac, res;
    printf("Digite P e M:\n"); scanf("%d%d", &p, &m);
    if(p > m)
        printf("P nao pode ser maior que M\n");
    else{
        mfac = calcMfac(m);
        pfac = calcPfac(p);
        mpfac = calcMPfac(m-p);
        res = calcFinal(mfac, (pfac * mpfac));
        printf("Resposta: %d\n", res);
    }

    return 0;
}