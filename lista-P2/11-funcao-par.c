#include <stdio.h>
#include <stdlib.h>

int PAR(int num){
    return (num % 2);
}

void main(){
    int num;
    printf("Digite um número: ");
    scanf("%d", &num);
    if(PAR(num)==0){
        printf("%d é par",num);
    }
    else{
        printf("%d é impar",num);
    }
    return 0;
}
