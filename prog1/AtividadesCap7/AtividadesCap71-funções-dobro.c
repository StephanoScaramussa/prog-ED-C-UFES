#include <stdio.h>
#include <stdlib.h>
 /*Faça um programa em C que leia três números e, para cada um, imprimir o dobro.
O cálculo deverá ser realizado por uma função e o resultado impresso ao ﬁnal do
programa.*/
int calcula_dobro(int valor){
    return valor *= 2;
}
int main(){
    int n=0, valor;
    while(n<3){
        n++;
        printf("Digite um número: \n");
        scanf("%d",&valor);
        printf("Dobro de %d: %d\n",valor,calcula_dobro(valor));
    }
}
