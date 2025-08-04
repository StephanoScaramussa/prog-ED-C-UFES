#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	char info;
	struct arvore*dir;
	struct arvore*esq;
}Arvore;

Arvore* criarArvoreVazia(){
	return NULL;
}

Arvore* criarArvore(char c, Arvore*sae, Arvore*sad){
	Arvore* a = (Arvore*)malloc(sizeof(Arvore));
	if(a!=NULL){
		a->info=c;
		a->esq=sae;
		a->dir=sad;
	}
	return a;
}

int estaVazia(Arvore* arv){
	return (arv == NULL);
}

void imprimeArvore(Arvore* arv){
	printf("<");
	if(!estaVazia(arv)){
		printf("%c",arv->info);
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
}

int main() {
	//Arvore* a = criarArvore('X',criarArvoreVazia(),criarArvoreVazia());
	//criar estrutura para <a <b <> <d <> <>>> <c <e <> <>> <f <> <>>>>
	Arvore*d = criarArvore('d',criarArvoreVazia(),criarArvoreVazia());
	Arvore*b = criarArvore('b',criarArvoreVazia(),d);
	Arvore*e = criarArvore('e',criarArvoreVazia(),criarArvoreVazia());
	Arvore*f = criarArvore('f',criarArvoreVazia(),criarArvoreVazia());
	Arvore*c = criarArvore('c',e,f);
	Arvore*a = criarArvore('a',b,c);
	imprimeArvore(a);
	a->dir = liberar(arv->dir);
}
