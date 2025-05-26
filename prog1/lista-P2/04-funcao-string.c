#include <stdio.h>
#include <stdlib.h>

#define max_char 100

void multiplicaString(char *S, int N){
    printf("Resultado:");
    for(int i=0;i<N;i++){
        printf("\n| %s |",S);
    }
}

void main(){
    char S[max_char];
    int N;
    printf("Digite o texto: ");
    scanf("%[^\n]", S);
    printf("Digite o numero de vezes que deseja repetir o texto: ");
    scanf("%d", &N);
    multiplicaString(S, N);
}
