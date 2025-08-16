#include "lista-dupla-enc.h"

int main(){
    int escolha;
    NoLista * lista = criarLista();
    leRegistro(&lista);
    do{
        printf("\n----------------------------------\n");
        printf("\033[0;35m              MENU                \033[0m\n");
        printf("----------------------------------\n");
        printf("1 - Adicionar novo registro\n");
        printf("2 - Remover registro por id\n");
        printf("3 - Buscar por humor\n");
        printf("4 - Imprimir todos os registros\n");
        printf("5 - Mostrar media das notas do dia\n");
        printf("6 - Mostrar humor mais frequente\n");
        printf("7 - Mostrar os motivos do humor\n");
        printf("8 - Sair\n");
        printf("Escolha uma acao: ");
        scanf("%d", &escolha);
        printf("----------------------------------\n");

        switch(escolha){
            case 1:
                RegistroDeHumor *humor = criarRegistro();
                inserirNoFinalLista(&lista,*humor);
                liberarRegistro(humor);
                break;
            case 2:
                removerPorId(&lista);
                break;
            case 3:
                int m=1;
                buscarPorHumor(&lista,m);
                break;
            case 4:
                int n=1;
                imprimirTodosRegistros(&lista,n);
                break;
            case 5:
                mediaNota(&lista);
                break;
            case 6:
                mostrarHumorMaisFreq(&lista);
                break;
            case 7:
                int o=1;
                imprimirMotivoHumor(&lista,o);
                break;
            case 8:
                printf("\n\033[0;34mAte mais!\033[0m\n");
                salvaRegistro(&lista);
                liberarLista(&lista);
                break;
            default:
                printf("\n\033[0;34mDigite novamente.\033[0m\n");
        }
    }
    while(escolha!=8);
}