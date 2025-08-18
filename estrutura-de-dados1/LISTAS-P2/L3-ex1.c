#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
	float info;
	struct nolista* prox;
}NoLista;

typedef struct fila{
	NoLista* ini;
	NoLista* fim;
}Fila;

Fila*criarFila(){
	Fila* f = (Fila*) malloc(sizeof(Fila));
	f->ini=f->fim=NULL;
	return f;
}

int estaVazia(Fila*f){
	return (f->ini==NULL);
}

void inserir(Fila*f, float v){
	NoLista* p = (NoLista*) malloc(sizeof(NoLista));
	p->info = v;
	p->prox = NULL;
	if(p!=NULL){
		if(estaVazia(f)){
			f->ini = f->fim = p;
		}
		else{
			f->fim->prox = p;
			f->fim = p;		
		}	
	}
	else{
		printf("Erro ao alocar memória!");
	}
}

float maior(Fila*f){
	float maior_elemento=0;
	if(!estaVazia(f)){
		for(NoLista*p=f->ini;p!=NULL;p=p->prox){
			if(p->info>maior_elemento){
				maior_elemento=p->info;
			}
		}
		return maior_elemento;
	}
	else{
		printf("Lista vazia!\n");
	}
}

int main(){
	Fila*fila = criarFila();
	inserir(fila,2.5);
	inserir(fila,3.5);
	inserir(fila,4.5);
	inserir(fila,5.5);
	inserir(fila,10.5);
	inserir(fila,6.5);
	float n = maior(fila);
	printf("%.2f",n);
}
