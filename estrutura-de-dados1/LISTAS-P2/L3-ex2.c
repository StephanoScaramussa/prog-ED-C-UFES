#include <stdio.h>
#include <stdlib.h>

typedef struct nopilha{
    float info;
    struct nopilha* prox;
}NoPilha;

typedef struct pilha{
    NoPilha* topo;
}Pilha;

Pilha* criarPilha(){
    Pilha* nova = (Pilha*) malloc(sizeof(Pilha));
    nova->topo = NULL;
    return nova;
}

int estaVazia(Pilha* p){
    return p->topo==NULL;
}

void push(Pilha*p, float v){
    NoPilha* novo = (NoPilha*) malloc(sizeof(NoPilha));
    if(novo!=NULL){
        novo->info = v;
        novo->prox = p->topo;
        p->topo = novo;
    }
    else{
        printf("Erro ao alocar memoria!");
    }
    return;
}

void imprimirTopoBase(Pilha*p){
    if(!estaVazia(p)){
        for(NoPilha*n = p->topo; n!=NULL;n = n->prox){
            printf("%.2f\n",n->info);
        }
    }
    else{
        printf("Pilha vazia!");
    }
}

void imprimirTopoBaseRec(NoPilha*n){
    if(n!=NULL){
        printf("%.2f\n",n->info);
        if(n->prox!=NULL){
            imprimirTopoBaseRec(n->prox);
        }
    }
    else{
        printf("Pilha vazia!\n");
    }
}

void imprimirBaseTopoRec(NoPilha*n){
    if(n == NULL){
        printf("Pilha vazia!\n");
        return;
    }
    if(n->prox!=NULL){
        imprimirBaseTopoRec(n->prox);
    }
    printf("%.2f\n",n->info);
}

float pop(Pilha* p){
    if(!estaVazia(p)){
        NoPilha*temp = p->topo;
        float v = temp->info;
        p->topo = temp->prox;
        free(temp);
        return v;
    }
    else{
        printf("Pilha vazia!\n");
    }
}

void liberarPilha(Pilha*p){
    NoPilha *n, *temp;
    for(n=p->topo;n!=NULL;n=temp){
        temp = n->prox;
        free(n);
    }
    free(p);
}

void umconcantenaPilhas(Pilha* p1, Pilha* p2){
    Pilha* p_aux = (Pilha*) malloc(sizeof(Pilha));
    p_aux->topo = NULL;
    float v;
    NoPilha* _n;
    if(!estaVazia(p2)){
        while(!estaVazia(p2)){
            push(p_aux,pop(p2));
        }
        while(!estaVazia(p_aux)){
            push(p1,pop(p_aux));
        }
    }
    else{
        printf("p2 esta vazia!");
    }
    
}

void doisconcantenaPilhas(Pilha* p1, Pilha* p2){
    if(estaVazia(p2)){
        return;
    }
    float v = pop(p2);
    doisconcantenaPilhas(p1,p2);
    push(p1,v);
}

void tresconcatenaPilhas(Pilha* p1, Pilha* p2){
    if(p2->topo==NULL){
        return;
    }
    NoPilha* n = p2->topo;
    p2->topo = n->prox;
    float v = n->info;
    tresconcatenaPilhas(p1,p2);
    n->prox = p1->topo;
    p1->topo = n;
}

int main() {
	Pilha* pilha1 = criarPilha();
	Pilha* pilha2 = criarPilha();
    push(pilha1,10);
    push(pilha1,20);
    push(pilha1,30);
    push(pilha2,500);
    push(pilha2,300);
    // imprimirTopoBaseRec(pilha1->topo);
    // imprimirBaseTopoRec(pilha1->topo);
    // pop(pilha1);
    // imprimirBaseTopoRec(pilha1->topo);
    //umconcantenaPilhas(pilha1,pilha2);
    //doisconcantenaPilhas(pilha1,pilha2);
    tresconcatenaPilhas(pilha1,pilha2);
    imprimirTopoBaseRec(pilha1->topo);
}