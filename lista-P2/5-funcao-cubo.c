#include <stdio.h>
#include <stdlib.h>

#define max_char 100

void Cubo(float F){
    float cubo=1;
    for(int i=0;i<3;i++){
        cubo *= F;
    }
    printf("Cubo de %.2f é %.2f",F,cubo);
}

void main(){
    float F;
    printf("Digite um número: ");
    scanf("%f", &F);
    Cubo(F);
}
