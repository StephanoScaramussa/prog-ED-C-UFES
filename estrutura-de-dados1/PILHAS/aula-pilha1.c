#include "aula-pilha1.h"

int main(){
    Pilha*pilha = criarPilha();
    push(pilha,53);
    push(pilha,31);
    imprimirPilha(pilha);
    float popi = pop(pilha);
    printf("Topo: %.2f \n",popi);
    imprimirPilha(pilha);
    liberarPilha(pilha);
    imprimirPilha(pilha);
}