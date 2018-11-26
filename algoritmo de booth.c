#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 4

char multip[tam+1];
char hi[tam+1];
char lo[tam+1];
char aux = '0';

void some_mult(){
    int carry = 0, cont, res = 0;
    for(cont = tam - 1; cont >= 0; cont--){
        if(carry == 1) res++;
        if(multip[cont] == '1') res++;
        if(hi[cont] == '1') res++;

        if(res%2 == 0) hi[cont] = '0';
        else hi[cont] = '1';

        carry = res/2;

        res = 0;
    }
}

void subtrai_mult(){
    int cont, carry = 0;
    char vet[tam + 1];

    for(cont = 0; cont < tam; cont++){
        if(multip[cont] == '0') vet[cont] = '1';
        else vet[cont] = '0';
    }
    vet[tam] = '\0';

    carry = '1';

    for(cont = tam - 1; cont >= 0; cont--){
        if (carry == '1'){
            if(vet[cont] == '0') {vet[cont] = '1'; carry = '0';}
            else {vet[cont] = '0'; carry = '1';}
        }
    }
    carry = 0;
    int res = 0;
    for(cont = tam - 1; cont >= 0; cont--){
        if(carry == 1) res++;
        if(vet[cont] == '1') res++;
        if(hi[cont] == '1') res++;

        if(res%2 == 0) hi[cont] = '0';
        else hi[cont] = '1';

        carry = res/2;

        res = 0;
    }
}

void desloca(){
    int cont;
    aux = lo[tam-1];
    for(cont = tam - 1; cont > 0; cont--){
        lo[cont] = lo[cont - 1];
    }
    lo[0] = hi[tam-1];
    for(cont = tam - 1; cont > 0; cont--){
        hi[cont] = hi[cont - 1];
    }
    hi[0] = hi[1];
}

int main(){

    int cont;

    printf("Digite o multip de %d bit: ", tam); scanf("%s", multip);
    printf("Digite o multiplicador de %d bit: ", tam); scanf("%s", lo);

    for(cont = 0; cont < tam; cont++){
        hi[cont] = '0';
    }
    hi[tam] = '\0';

    for(cont = 1; cont <= tam; cont++){
        if(lo[tam - 1] == '0' && aux == '1'){
            some_mult();
        }
        else if(lo[tam - 1] == '1' && aux == '0'){
            subtrai_mult();
        }
        printf("%s %s %c\n",hi,lo,aux); //apague
        desloca();
        printf("%s %s %c\n",hi,lo,aux); //apague
    }
    printf("%s%s",hi,lo);
    return 0;
}
