#include "aula-fila1.h"

int main(){
	Fila*fila = criarFila();
	imprimir(fila);
	remover(fila);
	inserir(fila,10);
	inserir(fila,15);
	inserir(fila,20);
	imprimir(fila);
}