#include <stdio.h>
#include <stdlib.h>

void METADE(float numerador){
    printf("Metade de %.2f é %.2f", numerador, numerador/2.0);
}

void main(){
    float  numerador;
    printf("Digite um valor: ");
    scanf("%f",&numerador);
    METADE(numerador);
}
