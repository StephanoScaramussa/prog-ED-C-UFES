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

int main() {
/*	<a 
		<b 
			<
			>
			<d 
				<
				>
				<
				>
			>
		>
		<c
			<e 
				<
				>
				<
				>
			> 
			<f
				<
				>
				<
				>
			>
		>
	>*/
	Arvore* a = criarArvore('X',criarArvoreVazia(),criarArvoreVazia());
	//criar estrutura para <a <b <> <d <> <>>> <c <e <> <>> <f <> <>>>>
	Arvore*d = criarArvore('d',criarArvoreVazia(),criarArvoreVazia());
	Arvore*b = criarArvore('b',criarArvoreVazia(),d);
	Arvore*e = criarArvore('e',criarArvoreVazia(),criarArvoreVazia());
	Arvore*f = criarArvore('f',criarArvoreVazia(),criarArvoreVazia());
	Arvore*c = criarArvore('c',e,f);
	Arvore*a = criarArvore('a',b,c);
}
