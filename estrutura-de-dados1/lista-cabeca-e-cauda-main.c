#include "lista-cabeca-e-cauda.h"

int main(){
	Lista lista;
	criaLista(&lista);
	insereElemento(&lista,10);
	insereElementoFim(&lista,20);
	imprimeLista(&lista);
	removeElemento(&lista, 2);
	removeElemento(&lista, 20);
	insereElemento(&lista, 2);
	imprimeLista(&lista);
	libera(&lista);
	imprimeLista(&lista);
}
