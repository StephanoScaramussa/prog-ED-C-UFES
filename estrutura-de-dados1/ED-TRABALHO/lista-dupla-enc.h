#ifndef LISTA_DUPLA_ENC_h
#define LISTA_DUPLA_ENC_h
#include "registro-de-humor.h"

typedef struct nolista{
    RegistroDeHumor info;
    struct nolista* ant;
    struct nolista* prox;
}NoLista;

NoLista* criarLista();
int estaVazia(NoLista**l);
void inserirNoFinalLista(NoLista**l, RegistroDeHumor v); //1
void removerPorId(NoLista**l); //2
void buscarPorHumor(NoLista**l, int n); //3
void imprimirRegistroSimples(NoLista*p, int n);
void imprimirTodosRegistros(NoLista**l,int n); //4
void mediaNota(NoLista**l); //5
void mostrarHumorMaisFreq(NoLista**l); //6
void imprimirMotivoHumor(NoLista**l,int n); //7
void liberarLista(NoLista**l);
void salvaRegistro(NoLista**l);
void leRegistro(NoLista**l);
#endif