// lista-main-estudo.c
#include "lista-estudo.h"

int main() {
    Lista minhaLista;
    criarLista(&minhaLista);

    adicionarItem(&minhaLista, 10);
    adicionarItem(&minhaLista, 20);
    adicionarItem(&minhaLista, 30);

    imprimirLista(&minhaLista);

    removerItem(&minhaLista, 20);
    imprimirLista(&minhaLista);

    removerItem(&minhaLista, 100);  // Teste com item inexistente

    liberarLista(&minhaLista);
    imprimirLista(&minhaLista);  // Lista vazia

    return 0;
}
