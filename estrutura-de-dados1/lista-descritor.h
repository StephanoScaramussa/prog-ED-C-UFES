//lista encadeada com descritor
#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
	int info;
	struct nolista* prox;
}NoLista;

typedef struct descritor{
	NoLista* prim;
	NoLista* ult;
	int n;
}Descritor;

void criarLista(Descritor* l){
	l->prim = l->ult = NULL;
	l->n = 0;
}

int estaVazia(Descritor* l){
	return (l->n == 0);
}

void insereNoInicio(Descritor* l, int valor){
	NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
	if(novo != NULL){
		novo -> info = valor;
		novo -> prox = l->prim;
		l -> prim = novo;
		if(l->n==0){
			l->ult=novo;
		}
		l->n++;
	}
	else{
		printf("Não foi possível alocar espaço!");
	}
}

void imprimeLista(Descritor* l){
	if(!estaVazia(l)){
		for(NoLista*p=l->prim;p!=NULL;p=p->prox){
			printf("%d",p->info);
		}
	}
	else{
		printf("Lista vazia!");
	}
}
