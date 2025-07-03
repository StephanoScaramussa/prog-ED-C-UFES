#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
	int info;
	struct nolista*prox;
}NoLista;

typedef struct lista{
	NoLista* cabeca;
	NoLista* cauda;
}Lista;

void criaLista(Lista*l){
	l->cabeca=malloc(sizeof(NoLista));
	l->cauda=malloc(sizeof(NoLista));
	l->cabeca->prox=l->cauda;
	l->cauda->prox=NULL;
}

int estaVazia(Lista*l){
	return l->cabeca->prox==l->cauda;
}

void insereElemento(Lista*l, int valor){
	NoLista*novo=malloc(sizeof(NoLista));
	if(novo!=NULL){
		novo->info=valor;
		novo->prox=l->cabeca->prox;
		l->cabeca->prox=novo;
	}
	else{
		printf("Não foi possível alocar memória!");
	}
}

void insereElementoFim(Lista*l, int valor){
	NoLista*novo=malloc(sizeof(NoLista));
	if(novo!=NULL){
		novo->prox=NULL;
		l->cauda->info=valor;
		l->cauda->prox=novo;
		l->cauda=novo;
	}
	else{
		printf("Não foi possível alocar memória!");
	}
}

void imprimeLista(Lista* l){
	if(!estaVazia(l)){
		for(NoLista*p=l->cabeca->prox;p!=l->cauda;p=p->prox){
			printf("%d ",p->info);
		}
	}
	else{
		printf("Lista vazia!");
	}
}

void removeElemento(Lista*l, int valor){
	NoLista*p, *ant=l->cabeca;
	for(p=l->cabeca->prox;p!=l->cauda&&p->info!=valor;p=p->prox){
		ant=p;
	}
	if(p==l->cauda){
			printf("Elemento não encontrado!");
	}
	else{
		ant->prox = p->prox;
		free(p);
	}
}

void libera(Lista*l){
	if(!estaVazia(l)){
		for(NoLista*p=l->cabeca->prox;p!=l->cauda;p=l->cabeca->prox){
			l->cabeca->prox=p->prox;
			free(p);
		}
	}
	else{
		printf("Lista vazia!");
	}
}
