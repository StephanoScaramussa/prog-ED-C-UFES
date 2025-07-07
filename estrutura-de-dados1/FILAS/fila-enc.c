#include "fila-enc.h"

int main(){
	Fila* fila = criarFila();
    imprimir(fila);
    remover(fila);
    inserir(fila,1);
    inserir(fila,2);
    inserir(fila,3);
    imprimir(fila);
    float v = remover(fila);
    printf("Fila atualizada:\n");
    imprimir(fila);
    printf("Valor puxado na remocao: %0.2f\n",v);
	printf("Primeiro: %.2f\n",primeiro(fila));
    liberar(fila);
    //imprimir(fila);
}