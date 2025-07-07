#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
	struct nolista* prox;
	float info;
}NoLista;

typedef struct fila{
	NoLista*ini;
	NoLista*fim;
}Fila;

Fila*criarFila(){
	Fila*f=(Fila*)malloc(sizeof(Fila));
	f->ini=f->fim=NULL;
	return f;
}

int estaVazia(Fila*f){
	return (f->ini==NULL);
}

void inserir(Fila*f,float v){
	NoLista*n=(NoLista*)malloc(sizeof(NoLista));
	if(n!=NULL){
		n->info = v;
		n->prox = NULL;
		if(!estaVazia(f)){
			f->fim->prox=n;
			f->fim=n;
		}
		else{
			f->ini=n;
			f->fim=n;
		}
	}
	else{
		printf("Nao foi possivel alocar memoria!\n");
	}
}

void imprimir(Fila*f){
	if(!estaVazia(f)){
		for(NoLista*p=f->ini;p!=NULL;p=p->prox){
			printf("%.2f\n",p->info);
		}
	}
	else{
		printf("Fila esta vazia!\n");
	}
}

float remover(Fila*f){
	if(!estaVazia(f)){
		NoLista*p = f->ini;
		float v = p->info;
		f->ini = p->prox;
		if(f->ini==NULL){
			f->fim=NULL;
		}
		free(p);
		return v;
	}
	else{
		printf("Fila esta vazia!\n");
	}
}

void liberar(Fila*f){
	if(!estaVazia(f)){
		for(NoLista*p=f->ini, *prox;p!=NULL;p=prox){
			prox=p->prox;
			free(p);
		}
	}
	free(f);
}

float primeiro(Fila*f){
	return f->ini->info;
}

void furarFila(Fila*f, float v){
	if(!estaVazia(f)){
		
	}
	else{
		printf("Fila esta vazia\n");
	}
}