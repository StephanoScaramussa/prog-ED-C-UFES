#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef struct fila{
	float info[N];
	int ini;
	int n;
}Fila;

Fila*criarFila(){
	Fila*f=(Fila*)malloc(sizeof(Fila));
	f->n=0;
	f->ini=0;
	return f;
}

int estaVazia(Fila*f){
	return f->n==0;
}

int estaCheia(Fila*f){
	return f->n==N;
}

void inserir(Fila*f,float v){
	if(!estaCheia(f)){
		int fim=(f->ini+f->n)%N;
		f->info[fim] = v;
		f->n++;
	}
	else{
		printf("Fila esta cheia!\n");
	}
}

void imprimir(Fila*f){
	if(!estaVazia(f)){
		int i = f->ini;
		for(int x=0;x<f->n;x++){
			printf("%.2f",f->info[i]);
			i=(i+1)%N;
		}
	}
	else{
		printf("Fila esta vazia!\n");
	}
}

float remover(Fila*n){
	if(!estaVazia(f)){
		float v = f->info[f->ini];
		f->ini=(f->ini+1)%N;
		f->n--;
		return v;
	}
	else{
		printf("Fila esta vazia!\n");
	}
}

void liberar(Fila*f){
	free(f);
}