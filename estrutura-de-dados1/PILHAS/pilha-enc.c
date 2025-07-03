#include "pilha-enc.h"

int main(){
    Pilha* pilha = criarPilha();
    imprimir(pilha);
    pop(pilha);
    push(pilha,1);
    push(pilha,2);
    push(pilha,3);
    imprimir(pilha);
    float v = pop(pilha);
    printf("Pilha atualizada:\n");
    imprimir(pilha);
    printf("Valor puxado no pop: %0.2f",v);
    liberar(pilha);
    imprimir(pilha);
}