#include <stdio.h>
#include <stdlib.h>

void TROCA(int *x, int *y){
    int novo_x, novo_y;
    novo_x = *y;
    novo_y = *x;
    *x = novo_x;
    *y = novo_y;
}

void main(){
    int x,y;
    printf("Digite um valor x: ");
    scanf("%d",&x);
    printf("Digite um valor y: ");
    scanf("%d",&y);
    TROCA(&x,&y);
    printf("Valor trocado de x: %d\n", x);
    printf("Valor trocado de y: %d\n", y);
}
