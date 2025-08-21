#include <stdio.h>
#include <stdlib.h>

typedef struct nofila{
	float info;
	struct nofila* prox;
}NoFila;

typedef struct fila{
	NoFila* ini;
	NoFila* fim;
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
	NoFila* p = (NoFila*) malloc(sizeof(NoFila));
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
		for(NoFila*p=f->ini;p!=NULL;p=p->prox){
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

float removeUm(Fila* f){
	if(!estaVazia(f)){
		NoFila*p = f->ini;
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

void umcombinaFilas(Fila* f_res, Fila* f1, Fila* f2){
	while(!estaVazia(f1) && !estaVazia(f2)){
		inserir(f_res, removeUm(f1));
		inserir(f_res, removeUm(f2));
	}
	while(!estaVazia(f1)){
		inserir(f_res,removeUm(f1));
	}
	while(!estaVazia(f2)){
		inserir(f_res,removeUm(f2));
	}
	if(estaVazia(f_res)){
		printf("Todas as filas estao vazias!");
	}
}

void doiscombinaFilas(Fila*f_res, Fila*f1, Fila*f2){
	if(!estaVazia(f1) && !estaVazia(f2)){
		inserir(f_res, removeUm(f1));
		inserir(f_res, removeUm(f2));
		doiscombinaFilas(f_res,f1,f2);
	}
	else if(!estaVazia(f1)){
		inserir(f_res,removeUm(f1));
		doiscombinaFilas(f_res,f1,f2);
	}
	else if(!estaVazia(f2)){
		inserir(f_res,removeUm(f2));
		doiscombinaFilas(f_res,f1,f2);
	}
	else if(estaVazia(f_res)){
		printf("Todas as filas estao vazias!");
	}
	return;
}

void imprimir(Fila*f){
	if(!estaVazia(f)){
		for(NoFila*p=f->ini;p!=NULL;p=p->prox){
			printf("%.2f\n",p->info);
		}
	}
	else{
		printf("Fila esta vazia!\n");
	}
}

int main(){
	Fila*fila = criarFila();
	Fila*f1 = criarFila();
	Fila*f2 = criarFila();
	Fila*f3 = criarFila();
	inserir(fila,2.5);
	inserir(fila,3.5);
	inserir(fila,4.5);
	inserir(f1,5.5);
	inserir(f1,3.5);
	inserir(f1,7.5);
	inserir(f1,10.5);
	inserir(f2,6.5);
	//umcombinaFilas(f3,f1,f2);
	doiscombinaFilas(f3,f1,f2);
	imprimir(f3);
	//printf("%.2f", maior(fila));
}
