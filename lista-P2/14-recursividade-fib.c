#include <stdio.h>
#include <stdlib.h>

int FIB(int valor){
    if(valor >= 0 && valor < 3){
        return 1;
    }
    return FIB(valor-1) + FIB(valor-2);
}

void main(){
    int valor;
    printf("Digite um número: ");
    scanf("%d",&valor);
    printf("Resultado: %d",FIB(valor));
}
