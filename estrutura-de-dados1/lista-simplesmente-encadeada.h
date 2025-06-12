#include <stdio.h>
#include <stdlib.h>

typedef struct noLista{ 
    int info;
    struct noLista *prox;
}NoLista;

void criarLista(NoLista **l) {
    *l = NULL;
}

int estaVazia(NoLista **l) {
    return (*l == NULL);
}

void insereElemento(NoLista **l, int v){
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    if(novo != NULL) {
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    } else {
        printf("Nao foi possivel alocar espaco.\n");
    }
}

void imprimeLista(NoLista **l) {
    if(!estaVazia(l)) {
        for(NoLista *p = *l; p != NULL; p = p->prox){
            printf("%d\n", p->info);
        }
    } else {
        printf("Lista vazia.\n");
    }
}

int qtde(NoLista **l) {
    int n = 0;
    if(!estaVazia(l)) {
        for(NoLista *p = *l; p != NULL; p = p->prox){
            n++;
        }
    }
    return n;    
}

NoLista* busca(NoLista **l, int v){
    for(NoLista*p=*l; p != NULL; p = p->prox){
        if(p->info == v){
            return p;
        }
    }
    return NULL;
}

void removeElemento(NoLista **l, int v){
    NoLista *ant = NULL;
    NoLista *p = *l;
    
    while(p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    
    if(p == NULL) {
        printf("Elemento nao encontrado.\n");
    } else {
        if(ant == NULL){
            *l = p->prox;   
        } else {
            ant->prox = p->prox;
        }
        free(p);
    }
}

void libera(NoLista **l) {
    NoLista*p, *temp;
    for(p=*l; p!=NULL; p=temp){
        temp = p->prox;
        free(p);
    }
    *l = NULL;
}

NoLista* ultimo(NoLista** list){
    if(estaVazia(list)){
        NoLista* p;
        for(p = *list; p->prox != NULL; p = p->prox){
            return p;
        }
    }
    return NULL;
    
}

int main() {
    NoLista *lista;
    criarLista(&lista);
    
    insereElemento(&lista, 45);
    insereElemento(&lista, 32);
    insereElemento(&lista, 23);
    
    printf("Elementos da lista:\n");
    imprimeLista(&lista);
    
    printf("\nQuantidade de elementos da lista: %d\n", qtde(&lista));
    
    int valorBusca = 32;
    NoLista *resultado = busca(&lista, valorBusca);
    if(resultado != NULL) {
        printf("\nElemento %d encontrado.\n", valorBusca);
    } else {
        printf("\nElemento %d nao encontrado.\n", valorBusca);
    }
    
    printf("\nRemovendo elemento 32...\n");
    removeElemento(&lista, 32);
    
    printf("\nLista apos remocao do elemento:\n");
    imprimeLista(&lista);
    
    
    NoLista *ultimoElemento = ultimo(&lista);
        if (ultimoElemento != NULL) {
            printf("\nUltimo elemento da lista: %d\n", ultimoElemento->info);
        } else {
            printf("\nLista vazia, sem ultimo elemento.\n");
        }
     
    libera(&lista);


    return 0;
}
