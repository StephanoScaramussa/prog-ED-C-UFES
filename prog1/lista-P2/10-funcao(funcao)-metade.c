#include <stdio.h>
#include <stdlib.h>

#define qtd_numeros 30

float calculaMETADE(float numerador){
    return(numerador/2.0);
}

void METADE(float *valores){
    for(int i=0;i<qtd_numeros;i++){
        printf("Metade de %.2f é %.2f\n", valores[i], calculaMETADE(valores[i]));
    }
}

void main(){
    float valores[qtd_numeros];
    for(int i=0; i<qtd_numeros; i++){
        printf("Digite o %dº valor: ", i+1);
        scanf("%f", &valores[i]);
    }
    METADE(valores);
}
