// #include "RegistrodeHumor.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "ListaDuplamenteEnc.h"
#include <locale.h>

char entrada[100];

int exibirMenu()
{
    printf("\n---------------------MENU---------------------\n");
    printf("1- Adicionar novo registro\n");
    printf("2- Remover registro por ID\n");
    printf("3- Buscar por humor\n");
    printf("4- Imprimir todos os registros\n");
    printf("5 - Mostrar media das notas do dia\n");
    printf("6 - Mostrar humor mais frequente\n");
    printf("7 - Mostrar os motivos do humor\n");
    printf("8 - Sair\n");
    printf("----------------------------------------------\n");

    printf("Escolha uma opcao: ");
    char buffer[100];
    limparBuffer();
    fgets(buffer, sizeof(buffer), stdin);
    int opcao;
    sscanf(buffer, "%d", &opcao);
    return opcao;
}

int main()
{
    system("chcp 65001 > nul");
    setlocale(LC_ALL, "pt_BR.UTF-8");
    NoLista *lista;
    criarLista(&lista);

    int opcao = exibirMenu();
    int c;

    while (opcao != 8)
    {
        if ((opcao >= 1) && (opcao <= 8))
        {
            switch (opcao)
            {
            case 1:
            {
                RegistroHumor *humor = criarRegistro(&lista);

                if (humor != NULL)
                {
                    inserirElementoFim(&lista, *humor);
                    liberarRegistro(humor);
                }
                else
                {
                    printf("Falha na criacao do registro. Nao foi adicionado a lista.\n");
                }
                break;
            }
            case 2:
            {
                int id;
                printf("Digite o ID do elemento: ");
                limparBuffer();
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &id);
                removeRegistroPorID(&lista, id);
                break;
            }

            case 3:
            {
                int humorBusca;
                printf("0 - FELIZ\n");
                printf("1 - TRISTE\n");
                printf("2 - ANSIOSO\n");
                printf("3 - CANSADO\n");
                printf("4 - MOTIVADO\n");
                printf("5 - ESTRESSADO\n");
                printf("6 - NEUTRO\n");
                printf("Digite o numero do humor daquele dia: \n");
                limparBuffer();
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &humorBusca);
                while (humorBusca < 0 || humorBusca > 6)
                {
                    printf("Digite um humor valido: ");
                    limparBuffer();
                    fgets(entrada, sizeof(entrada), stdin);
                    sscanf(entrada, "%d", &humorBusca);
                }
                buscaRegistroPorHumor(&lista, humorBusca);
                break;
            }
            case 4:
                imprimeRegistros(&lista);
                break;

            case 5:
            {
                int qtdDias;
                printf("Ver media de quantos dias? ");
                limparBuffer();
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &qtdDias);

                mostraMediaNota(&lista, qtdDias);
                break;
            }

            case 6:
            {
                int dias;
                printf("Voce quer buscar os registros de quantos dias:");
                limparBuffer();
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &dias);
                printf("\n");

                mostraHumorMaisFrequente(&lista, dias);
                break;
            }

            case 7:
            {
                int humor;
                printf("Pesquise os motivos de um humor especifico. Insira o humor: \n");
                limparBuffer();
                fgets(entrada, sizeof(entrada), stdin);
                sscanf(entrada, "%d", &humor);

                mostraMotivosPorHumor(&lista, humor);
                break;
            }
            opcao = exibirMenu();
            }
        }

        else
        {
            printf("Insira uma opcao valida para o menu:  ");
            opcao = exibirMenu();
        }
    }
    liberarListaCompleta(&lista);
    printf("Encerrando o programa. ");
    return 0;
}