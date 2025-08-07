#include <stdlib.h>
#include <stdio.h>
#include "RegistrodeHumor.h"

typedef struct noLista
{
    RegistroHumor info;
    struct noLista *prox;
    struct noLista *ant;
} NoLista;


void criarLista(NoLista **l);

int estaVazia(NoLista **l);

void inserirElementoFim(NoLista **l, RegistroHumor r);

void removeRegistroPorID(NoLista **l, int id);

void buscaRegistroPorHumor(NoLista **l, int h);

void imprimeUmRegistro(NoLista *p);

void imprimeRegistros(NoLista **l);

void mostraMediaNota(NoLista **l, int d);

void mostraMotivosPorHumor(NoLista **l, int h);

void mostraHumorMaisFrequente(NoLista **l, int d);

void liberarListaCompleta(NoLista **l);