#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RegistrodeHumor.h"
#include "ListaDuplamenteEnc.h"

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

RegistroHumor *criarRegistro(NoLista **l)
{
    RegistroHumor *novo;
    novo = (RegistroHumor *)malloc(sizeof(RegistroHumor));

    if (novo != NULL)
    {

        if (estaVazia(l))
        {
            novo->id = 1;
        }
        else
        {
            NoLista *p;
            for (p = *l; p->prox != NULL; p = p->prox)
                ;
            novo->id = p->info.id + 1;
        }
        printf("Insira a data: ");
        limparBuffer();
        fgets(novo->data, sizeof(novo->data), stdin);
        novo->data[strcspn(novo->data, "\n")] = '\0';

        Humor temp_humor;

        printf("0 - FELIZ\n");
        printf("1 - TRISTE\n");
        printf("2 - ANSIOSO\n");
        printf("3 - CANSADO\n");
        printf("4 - MOTIVADO\n");
        printf("5 - ESTRESSADO\n");
        printf("6 - NEUTRO\n");
        printf("Digite o humor do dia: ");
        char linha[100];
        limparBuffer();
        fgets(linha, sizeof(linha), stdin);
        sscanf(linha, "%d", &temp_humor);

        if (temp_humor >= FELIZ && temp_humor <= NEUTRO)
        {
            novo->humor = (Humor)temp_humor;
        }
        else
        {
            printf("Valor de humor invalido. Definindo como NEUTRO por padrao.\n");
            novo->humor = NEUTRO;
        }

        printf("Insira o motivo: ");
        limparBuffer();
        fgets(novo->motivo, sizeof(novo->motivo), stdin);
        novo->motivo[strcspn(novo->motivo, "\n")] = '\0';

        int nota;
        char linhaNota[100];
        printf("Insira a nota do dia (0 a 10): ");
        limparBuffer();
        fgets(linhaNota, sizeof(linhaNota), stdin);
        sscanf(linhaNota, "%d", &nota);

        while (nota < 0 || nota > 10){
            printf("Nota inválida. Digite um valor entre 0 e 10: ");
            limparBuffer();
            fgets(linhaNota, sizeof(linhaNota), stdin);
            sscanf(linhaNota, "%d", &nota);
        }
        
        novo->notadoDia = nota;

        return novo;
    }

    else
    {
        printf("Nao foi possivel alocar espaço");
        return NULL;
    }
}

void imprimeRegistro(RegistroHumor *r)
{
    printf("Id: %d\n", r->id);
    printf("Data: %s\n", r->data);
    printf("Humor: %d\n", r->humor);
    printf("Motivo: %s\n", r->motivo);
    printf("Nota: %d\n", r->notadoDia);
}

void liberarRegistro(RegistroHumor *r)
{
    if (r != NULL)
    {
        free(r);
    }
}