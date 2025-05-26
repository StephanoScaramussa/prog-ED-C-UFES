#include <stdio.h>
#include <stdlib.h>

int Divisivel(int x, int y){
    if(y==0){
        return 0;
    }
    if(x%y==0){
        return 1;
    }
    return 0;
}

void main(){
    int x,y;
    printf("Digite um valor para o numerador: ");
    scanf("%d", &x);
    printf("Digite um valor para o denominador: ");
    scanf("%d", &y);
    if(Divisivel(x,y)==1){
        printf("%d é divisivel por %d\n", x, y);
    }
    else{
        printf("%d não é divisivel por %d\n", x, y);
    }
}
