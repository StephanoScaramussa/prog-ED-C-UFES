#include <stdio.h>
#include <stdlib.h>

typedef struct arvore{
	int info;
	struct arvore sae;
	struct arvore sad;
	int fatBal;
}Arvore;

void rotacaoLR(Arvore**L){
	Arvore*temp;
	int fat = (*L)->fatBal;
	temp = (*L);
	(*L) = temp->esq;
	temp->esq = (*L)->dir;
	(*L)->dir = temp;
	if(fat==-2){
		if((*L)->fatBal==-1){
			(*L)->fatBal = 0;
			temp->fatBal = 0;
		}
		else{
			(*L)->fatBal = 1;
			temp->fatBal = -1;
		}
	}
	else{
		if((*L)->fatBal==0){
			(*L)->fatBal = 1;
			temp->fatBal = 0;
		}
		else{
			(*L)->fatBal = 0;
			temp->fatBal = 0;
		}
	}
}

void rotacaoRL(Arvore**L){
	Arvore*temp;
	int fat = (*L)->fatBal;
	temp = (*L);
	(*L) = temp->dir;
	temp->dir = (*L)->esq;
	(*L)->esq = temp;
	if(fat==-2){
		if((*L)->fatBal==1){
			(*L)->fatBal = 0;
			temp->fatBal = 0;
		}
		else{
			(*L)->fatBal = -1;
			temp->fatBal = 1;
		}
	}
	else{
		if((*L)->fatBal==0){
			(*L)->fatBal = -1;
			temp->fatBal = 0;
		}
		else{
			(*L)->fatBal = 0;
			temp->fatBal = 0;
		}
	}
}

int main() {
	
}
