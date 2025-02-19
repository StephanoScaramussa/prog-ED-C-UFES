#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
	if (n <=1 ){
		return 1;
	}
	else{
		return n * fatorial(n-1);
	}
}

int main(){
	int num, result;
	printf("Digite um n\xa3mero: \n");
	scanf("%d", &num);
	
	result = fatorial(num);
	
	printf("Resultado da fatorial de %d \x82: %d \n", num,result);
}
