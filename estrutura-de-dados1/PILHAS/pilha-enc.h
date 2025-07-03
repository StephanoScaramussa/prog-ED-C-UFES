#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    float info;
    struct nolista*prox;
}NoLista;

typedef struct pilha{
    NoLista*prim;
}Pilha;

Pilha* criarPilha(){
    Pilha*p = (Pilha*)malloc(sizeof(Pilha));
    p->prim=NULL;
    return p;
}

int estaVazia(Pilha*p){
    return p->prim==0;
}

void push(Pilha*p, float v){
    NoLista*n = (NoLista*) malloc(sizeof(NoLista));
    if(n!=NULL){
        n->info=v;
        n->prox=p->prim;
        p->prim=n;
    }
    else{
        printf("Nao foi possivel alocar memoria!\n");
    }
}

void imprimir(Pilha*p){
    if(!estaVazia(p)){
        for(NoLista*x=p->prim;x!=NULL;x=x->prox){
            printf("%.2f\n",x->info);
        }
    }
    else{
        printf("Lista vazia!\n");
    }
}

float pop(Pilha*p){
    if(!estaVazia(p)){
        NoLista*t = p->prim;
        float v = t->info;
        p->prim = t->prox;
        free(t);
        return v; 
    }
    else{
        printf("Lista vazia!\n");
    }
}

void liberar(Pilha*p){
    NoLista*t,*temp;
    for(t=p->prim;t!=NULL;t=temp){
        temp = t->prox;
        free(t);
    }
    free(p);
}