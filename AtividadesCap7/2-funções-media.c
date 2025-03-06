#include <stdio.h>
#include <stdlib.h>
 /*Faça um programa que receba as notas de três provas e calcule a média. Para o
cálculo, escreva uma função. O programa deve imprimir a média ao ﬁnal.*/
float calcula_media(int *vetor){
    float media;
    media = (vetor[0]+vetor[1]+vetor[2])/3.0;
    return(media);
}
int main(){
    int i, n=1, nota, vet_notas[3];
    for(i=0;i<3;i++){
        printf("Digite a %dª nota:",n);
        scanf("%d",&nota);
        n++;
        vet_notas[i] = nota;
    }
    printf("A média das notas é: %.2f\n",calcula_media(vet_notas));
}
