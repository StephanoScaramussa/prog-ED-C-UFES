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

void criaLista(Descritor* l){
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

void insereNoFinal(Descritor* l, int valor){
	NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
	if (novo != NULL){
		novo->info=valor;
		novo->prox=NULL;
		if(!estaVazia(l)){
			l->ult->prox = novo;
			l->ult=novo;
		}
		else{
			l->ult=novo;
			l->prim=novo;
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
			printf("%d ",p->info);
		}
	}
	else{
		printf("Lista vazia!");
	}
}

void removeDaLista(Descritor* l, int valor){
	NoLista* p, *ant = NULL;
	for(p=l->prim;p!=NULL&&p->info!=valor;p=p->prox){
		ant = p;
	}
	if(p==NULL){
		printf("Não encontrou o elemento!");
	}
	else{
		if(ant==NULL){
			l->prim = p->prox;
			if(l->prim==NULL){
				l->ult = NULL;
			}
		}
		else{
			ant->prox = p->prox;
			if(ant->prox==NULL){
				l->ult=ant;
			}
		}
		free(p);
		l->n--;
	}
}

void liberaLista(Descritor* l){
	NoLista* p, * temp;
	for(p = l->prim; p!=NULL;p=temp){
		temp = p->prox;
		free(p);
	}
	l->prim = l->ult=NULL;
	l->n = 0;
}

NoLista* buscaNaLista(Descritor* l, int valor){
	for(NoLista*p = l->prim; p!=NULL; p=p->prox){
		if(p->info==valor){
			return p;
		}
	}
	return NULL;
}
