#include <stdio.h>
#include <stdlib.h>

float calculaDobro(float F){
    float dobro;
    for(int i=0;i<3;i++){
        dobro = F*2;
    }
    return(dobro);
}

void Dobro(float *numeros){
    for(int i=0;i<3;i++){
        printf("Dobro de %.2f é %.2f\n",numeros[i],calculaDobro(numeros[i]));
    }
}

void main(){
    float numeros[3];
    for(int i=0;i<3;i++){
        printf("Digite um número: ");
        scanf("%f",&numeros[i]);
    }
    Dobro(numeros);
}
