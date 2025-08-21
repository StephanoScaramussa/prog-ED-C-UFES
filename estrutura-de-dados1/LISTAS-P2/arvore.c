#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
    char info;
    struct arvore* esq;
    struct arvore* dir;
}Arvore;

int qtdeFolhas(Arvore*a){
    if(a==NULL) return 0;
    if(a->esq==NULL&&a->dir==NULL) return 1;
    return(qtdeFolhas(a->esq)+qtdeFolhas(a->dir));
}

int qtdeChar(Arvore*a, char c){
    if(a==NULL) return 0;
    int n = 0; 
    if(a->info==c) n++;
    return(n+qtdeChar(a->esq,c)+qtdeChar(a->dir,c));
}

int iguais(Arvore*a,Arvore*b){
    if(a==NULL&&b==NULL) return 1;
    if(a==NULL || b==NULL) return 0;
    if(a->info!=b->info) return 0;
    return(iguais(a->esq,b->esq) && iguais(a->dir,b->dir));
}

Arvore* copia(Arvore*a){
    if(a==NULL) return NULL;
    Arvore* cop = (Arvore*) malloc(sizeof(Arvore));
    cop->info = a->info;
    cop->esq = copia(a->esq);
    cop->dir = copia(a->dir);
    return cop;
}

int maior(Arvore*a){
    if(a==NULL) return -1;
    int _maior = a->info;
    int maior_esq = -1, maior_dir = -1;
    if(a->esq != NULL) maior_esq = maior(a->esq);
    if(a->dir != NULL) maior_dir = maior(a->dir);
    if(maior_esq>_maior) _maior = maior_esq;
    if(maior_dir>_maior) _maior = maior_dir;
    return _maior;
}

//para ABB quando x for maior ou igual a->info, vai para a direita, ou seja, se incrementar n tambem continua indo para a direita
int ocorrências_x (Arvore* a, int x){
    int n=0;
    if(a==NULL) return n;
    if(a->info == x) n = 1 + ocorrências_x(a->dir,x);
    else if(x<a->info) return ocorrências_x(a->esq,x);
    else return ocorrências_x(a->dir,x);
}

void imprimedec(Arvore*a){
    if(a==NULL) return;
    imprimedec(a->dir);
    if(a->esq==NULL && a->dir==NULL){
        print("%d ",a->info);
    }
    imprimedec(a->esq);
}

int main() {
	
}