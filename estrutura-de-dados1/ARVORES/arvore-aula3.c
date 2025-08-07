#include <stdio.h>
#include <stdlib.h>
//árvore binária de busca(ou de pesquisa) - símetricas.

typedef struct arvore{
	int info;
	struct arvore*dir;
	struct arvore*esq;
}Arvore;

Arvore* criarArvoreVazia(){
	return NULL;
}

int estaVazia(Arvore* arv){
	return (arv == NULL);
}

Arvore* busca(Arvore*a, int v){
	if(estaVazia(a)){
		return NULL;
	}
	else{
		if(a->info==v){
			return a;
		}
		else if(v<a->info){
			return busca(a->esq, v);
		}
		else{
			return busca(a->dir, v);
		}
	}
}

Arvore* insere(Arvore*a, int v){
	if(estaVazia(a)){
		a = (Arvore*) malloc(sizeof(Arvore));
		a->info = v;
		a->esq = a->dir = NULL;
	}
	else{
		if(v<a->info){
			a->esq = insere(a->esq,v);
		}
		else{
			a->dir = insere(a->dir,v);
		}
	}
	return(a);
}

Arvore* remover(Arvore* a, int v){
	if(estaVazia(a)){
		return NULL;
	}
	else{
		if(v<a->info){
			a->esq = remover(a->esq, v);
		}
		else if(v>a->info){
			a->dir = remover(a->dir, v);
		}
		else{
			if(a->esq==NULL&&a->dir==NULL){
				free(a);
				a=NULL;
			}
			else if(a->dir==NULL){
				Arvore*t = a;
				a = a->esq;
				free(t);
			}
			else if(a->esq == NULL){
				Arvore*t = a;
				a = a->dir;
				free(t);
			}
			else{
				Arvore*t = a->esq;
				while(t->dir != NULL){
					t = t->dir;
				}
				a->info = t->info;
				t->info = v;
				a->esq = remover(a->esq,v);
			}
		}
		return a;
	}
}

void imprimeArvore(Arvore* arv){
	printf("<");
	if(!estaVazia(arv)){
		printf("%d",arv->info);
		imprimeArvore(arv->esq);
		imprimeArvore(arv->dir);
	}
	printf(">");
}

Arvore* liberarArv(Arvore*arv){
	if(!estaVazia(arv)){
		liberarArv(arv->esq);
		liberarArv(arv->dir);
		free(arv);
	}
	return NULL;
}

int main() {
	Arvore*a = criarArvoreVazia();
	a = insere(a,3);
	a = insere(a,5);
	a = insere(a,2);
	imprimeArvore(a);
	printf("\n");
	a = remover(a,3);
	imprimeArvore(a);
}
