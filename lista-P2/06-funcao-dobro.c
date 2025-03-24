#include <stdio.h>
#include <stdlib.h>

void Dobro(float F){
    float dobro;
    for(int i=0;i<3;i++){
        dobro = F*2;
    }
    printf("Dobro de %.2f é %.2f",F,dobro);
}

void main(){
    float F;
    printf("Digite um número: ");
    scanf("%f", &F);
    Dobro(F);
}
