#include <stdio.h>
#include <stdlib.h>

typedef struct lista{ //declarando uma lista
	No_lista* prim; //possui um "elemento" do tipo nó que aponta para o primeiro da lista
}Lista;

typedef struct no_lista{ //declarando o nó(elemento/posição) de uma lista
	int info; //informação, armazenada na posição da lista(nó)
	No_lista* prox; //esse "elemento" aponta para o próximo da lista
}No_lista;

Lista* cria_Lista(void){ //criando uma lista vazia
	Lista* 	l_pos = (Lista*) malloc(sizeof(Lista));
	l_pos -> prim = NULL;
	return l_pos;
}

int checa_Lista(Lista* l_pos){ //checa se a lista está vazia
	return (l_pos -> prim == NULL); //retorna 1 caso ela esteja vazia e 0 caso não esteja
};
