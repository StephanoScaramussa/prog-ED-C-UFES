#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct pilha{
    float info[MAX];
    int n;
}Pilha;

Pilha*criarPilha(){
    Pilha*p=(Pilha*)malloc(sizeof(Pilha));
    p->n=0;
    return p;
}

int estaVazia(Pilha*p){
    return p->n==0;
}

int estaCheia(Pilha*p){
    return p->n==MAX;
}

void push(Pilha* p,float v){
    if(!estaCheia(p)){
        p->info[p->n] = v;
        p->n++;
    }
    else{
        printf("Pilha cheia!\n");
    }
}

void imprimirPilha(Pilha*p){
    if(!estaVazia(p)){
        for(int i=(p->n)-1;i>=0;i--){
            printf("%.2f \n",p->info[i]);
        }
    }
    else{
        printf("Pilha vazia!\n");
    }
}

float pop(Pilha* p){
    if(!estaVazia(p)){
        float v = p->info[p->n-1];
        p->n--;
        return v;
    }
    else{
        printf("Pilha vazia!\n");
    }
}

void liberarPilha(Pilha*p){
    free(p);
    p = NULL;
}