//main - lista encadeada com descritor
#include "lista-descritor.h"

int main(){
	Descritor lista;
	criarLista(&lista); //envia endereço para acessar com ponteiro nas funções 'NoLista* l'
	insereNoInicio(&lista,2);
	insereNoInicio(&lista,5);
	imprimeLista(&lista);
}
