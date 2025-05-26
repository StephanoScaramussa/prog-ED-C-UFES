// lista-estudo.h
#ifndef LISTAESTUDO_H
#define LISTAESTUDO_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do item armazenado na lista
typedef struct {
    int valor;
} Item;

// Estrutura do nó
typedef struct No {
    Item dado;
    struct No *prox;
} No;

// Estrutura da lista
typedef struct {
    No *inicio;
} Lista;

// Função para criar uma nova lista
static inline void criarLista(Lista *lista) {
    lista->inicio = NULL;
}

// Função para verificar se a lista está vazia
static inline int listaVazia(Lista *lista) {
    return (lista->inicio == NULL);
}

// Função para criar um novo nó
static inline No* criarNo(int valor) {
    No *novoNo = (No *) malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha ao alocar memória.\n");
        exit(1);
    }
    novoNo->dado.valor = valor;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para adicionar item ao final da lista
static inline void adicionarItem(Lista *lista, int valor) {
    No *novo = criarNo(valor);

    if (listaVazia(lista)) {
        lista->inicio = novo;
    } else {
        No *atual = lista->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função para imprimir a lista
static inline void imprimirLista(Lista *lista) {
    if (listaVazia(lista)) {
        printf("A lista está vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    printf("Itens da lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado.valor);
        atual = atual->prox;
    }
    printf("\n");
}

// Função para remover um item (primeira ocorrência)
static inline void removerItem(Lista *lista, int valor) {
    if (listaVazia(lista)) {
        printf("A lista está vazia.\n");
        return;
    }

    No *atual = lista->inicio;
    No *anterior = NULL;

    while (atual != NULL && atual->dado.valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("O valor %d não foi encontrado.\n", valor);
        return;
    }

    if (anterior == NULL) {
        lista->inicio = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("O valor %d foi removido.\n", valor);
}

// Função para liberar toda a memória da lista
static inline void liberarLista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}

#endif // LISTAESTUDO_H
