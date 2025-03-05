#include <stdio.h>
#include <stdlib.h>
#define max 3 /*variável global*/

/*	int vet[max]  variável global*/

int fmaximo(int vet_[max]){ /*recebe "vet" do main e manipula livremente como variável local*/
	int maior = -1;  /*variável local*/
	for(int i=0; i<max; i++){
		if(maior < vet_[i]){
			maior = vet_[i];
		}
	}
return maior;
}

int main(){
	int i, _maior, vet[max]; /*variáveis locais*/
	
	for(i=0; i<max; i++){
		printf("Digite o número	%d de %d:\n",i+1,max);
		scanf("%d",&vet[i]);
	}
	
	_maior = fmaximo(vet);
	printf("O maior valor digitado foi: %d\n",_maior);
}
