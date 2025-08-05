#include <stdlib.h>
#include <stdio.h>
#include "ListaDuplamenteEnc.h"

void criarLista(NoLista **l)
{
    *l = NULL;
}

int estaVazia(NoLista **l)
{
    return (*l == NULL);
}

void inserirElementoFim(NoLista **l, RegistroHumor r)
{
    NoLista *novo;
    novo = (NoLista *)malloc(sizeof(NoLista));
    if (novo != NULL)
    {
        novo->info = r;
        novo->prox = NULL;

        if (!estaVazia(l))
        {
            NoLista *ult;
            for (ult = *l; ult->prox != NULL; ult = ult->prox)
                ;
            ult->prox = novo;
            novo->ant = ult;
        }
        else
        {
            *l = novo;
            novo->ant = NULL;
        }
    }
    else
        printf("Nao foi possivel alocar espaco \n");
}

void removeRegistroPorID(NoLista **l, int id)
{
    NoLista *p;
    for (p = *l; (p != NULL) && (p->info.id != id); p = p->prox)
        ;

    if (p == NULL)
    {
        printf("Elemento nao encontrado\n");
    }
    else
    {
        if (p->ant == NULL)
        {
            (*l) = p->prox;
        }
        else
        {
            p->ant->prox = p->prox;
        }
        if (p->prox != NULL)
        {
            p->prox->ant = p->ant;
        }
        free(p);
    }
}

void buscaRegistroPorHumor(NoLista **l, int h)
{
    if (!estaVazia(l))
    {
        for (NoLista *p = *l; p != NULL; p = p->prox)
        {
            if (p->info.humor == h)
            {
                printf("Data: %s\n", p->info.data);
                printf("Nota: %d\n\n", p->info.notadoDia);
            }
        }
    }
    else
        printf("Lista Vazia");
}

void imprimeUmRegistro(NoLista *p)
{
    char *nomesHumor[] = {
        "FELIZ",
        "TRISTE",
        "ANSIOSO",
        "CANSADO",
        "MOTIVADO",
        "ESTRESSADO",
        "NEUTRO"};

    int indiceHumor = p->info.humor;
    printf("Id: %d\n", p->info.id);
    printf("Data: %s\n", p->info.data);
    printf("Humor: %s\n", nomesHumor[indiceHumor]);
    printf("Motivo: %s\n", p->info.motivo);
    printf("Nota: %d\n", p->info.notadoDia);
    printf("\n\n");
}

void imprimeRegistros(NoLista **l)
{
    if (!estaVazia(l))
    {
        printf("Registros armazenados: \n\n");
        for (NoLista *p = *l; p != NULL; p = p->prox)
        {
            imprimeUmRegistro(p);
        }
    }
    else
        printf("Lista Vazia\n");
}

void mostraMediaNota(NoLista **l, int d)
{
    if (!estaVazia(l))
    {
        NoLista *ult;
        for (ult = *l; ult->prox != NULL; ult = ult->prox)
            ;

        int soma = 0;
        float contador = 0;

        for (NoLista *p = ult; p != NULL && contador < d; p = p->ant, contador++)
        {
            soma += p->info.notadoDia;
        }
        float media;
        if (contador != 0)
        {
            media = soma / contador;
        }
        else
            media = 0;

        // if (d!=contador){
        //     printf("Ha apenas %d registros\n", contador);
        // }

        printf("A media dos ultimos %1.0f dias e %3.2f", contador, media);
    }
    else
        printf("Nao ha registros\n\n");
}

void mostraHumorMaisFrequente(NoLista **l, int d)
{
    const char *nomesHumor[] = {
        "FELIZ",
        "TRISTE",
        "ANSIOSO",
        "CANSADO",
        "MOTIVADO",
        "ESTRESSADO",
        "NEUTRO"};

    if (estaVazia(l))
    {
        printf("\nNao ha registros para analisar.\n");
        return;
    }

    NoLista *ult;
    for (ult = *l; ult->prox != NULL; ult = ult->prox)
        ;

    int contador = 0;
    int contadores[7] = {0};
    for (NoLista *p = ult; p != NULL && contador < d; p = p->ant, contador++)
    {
        contadores[p->info.humor]++;
    }

    int contagemMaisFrequente = -1;
    int indiceMaisFrequente = -1;

    for (int i = 0; i < 7; i++)
    {
        if (contadores[i] > contagemMaisFrequente)
        {
            contagemMaisFrequente = contadores[i];
            indiceMaisFrequente = i;
        }
    }

    if (d != contador)
    {
        printf("Ha apenas %d registros\n", contador);
    }
    printf("O humor mais frequente para os ultimos %d dias foi: %s\n", contador, nomesHumor[indiceMaisFrequente]);
}

void mostraMotivosPorHumor(NoLista **l, int h)
{
    if (!estaVazia(l))
    {
        printf("Motivos: \n");
        int contador = 0;
        for (NoLista *p = *l; p != NULL; p = p->prox)
        {
            if (p->info.humor == h)
            {
                printf("- %s\n", p->info.motivo);
                contador++;
            }
        }
        if (contador == 0)
        {
            printf("Não há registros para esse humor");
        }
    }
    else
        printf("Nao ha registros\n\n");
}

void liberarListaCompleta(NoLista **l) {
    NoLista *atual = *l;
    NoLista *posterior;
    while (atual != NULL) {
        posterior = atual->prox; 
        free(atual);        
        atual = posterior;       
    }
    *l = NULL; 
    printf("Lista liberada com sucesso.\n"); 
}