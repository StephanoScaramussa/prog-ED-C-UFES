//main - lista encadeada com descritor
#include "lista-descritor.h"

int main(){
	Descritor lista;
	criaLista(&lista); //envia endereço para acessar com ponteiro nas funções 'NoLista* l'
	insereNoFinal(&lista,55);
	insereNoFinal(&lista,75);
	insereNoInicio(&lista,95);
	imprimeLista(&lista);
	removeDaLista(&lista,55);
	printf("\n");
	imprimeLista(&lista);
	removeDaLista(&lista,95);
	removeDaLista(&lista,75);
	printf("\n");
	imprimeLista(&lista);
	insereNoFinal(&lista,5);
	insereNoFinal(&lista,7);
	insereNoFinal(&lista,9);
	printf("\n");
	imprimeLista(&lista);
	liberaLista(&lista);
	printf("\n");
	imprimeLista(&lista);
	insereNoFinal(&lista,5);
	insereNoFinal(&lista,7);
	insereNoFinal(&lista,9);
	printf("\n");
	imprimeLista(&lista);
	NoLista* p = buscaNaLista(&lista,7);
	if(p != NULL){
		printf("\n%d",p->info);
	}
}
