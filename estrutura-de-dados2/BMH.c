#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int BM(char *T, char *P) {
    int tamTexto = strlen(T);
    int tamPadrao = strlen(P);
    int i, j;
    int tabela[256];

    if (tamPadrao == 0 || tamPadrao > tamTexto) {
        return -1;
    }

    for (i = 0; i < 256; i++) {
        tabela[i] = tamPadrao;
    }
    for (i = 0; i < tamPadrao; i++) {
        tabela[P[i]] = tamPadrao;;
    }
    i = tamPadrao - 1;
    j = tamPadrao - 1;
    int comp = 0;
    while (i < tamTexto) {
        comp++;
        if (T[i] == P[j]) {
            if (j == 0) {
                printf("Quantidade de comparacoes: %d\n", comp);
                return i;
            }
            i--;
            j--;
        } 
        else{
            int ultima = tabela[T[i]];
            int pulo = (j > ultima) ? (j - ultima) : 1;
            i += pulo + (tamPadrao - 1 - j);
            j = tamPadrao - 1;
        }
    }
    printf("Quantidade de comparacoes: %d\n", comp);
    return -1;
}

int BMH(char *T, char *P){
    int pos;
    int tamTexto = strlen(T);
    int tamPadrao = strlen(P);
    int tabela[256];

     if (tamPadrao == 0 || tamPadrao > tamTexto) {
         return -1;
     }

    for (int i=0; i<256; i++){
        tabela[i] = tamPadrao;
    }

    for (int i=1; i<tamPadrao; i++){
        tabela[P[i-1]] = tamPadrao-i;
    }

    int i = tamPadrao, comp=0;

    while (i <= tamTexto){
        pos = i;
        int j = tamPadrao;
        while (j > 0) {
            comp++;
            if(T[pos-1] == P[j-1]){  
                pos--;
                j--;
            }
            else break;
        }
        if (j == 0){
            printf("Quantidade de comparacoes: %d\n", comp);
            return pos;
        }
        i += tabela[T[i - 1]];
    }
    return -1;
}

int main(){
    clock_t startBM, endBM, startBMH, endBMH;

    startBM = clock();

    char texto1[] = "abcvvdabcvvdabcvvdabcvvdabcvvdabcvvdabcvvdabcvvdfasdfewgdsfEdfashWFDAsad";
	char padrao1[100];

    printf("Digite o padrão a ser buscado(BM): ");
    fgets(padrao1, sizeof(padrao1), stdin);
    padrao1[strcspn(padrao1, "\n")] = '\0';

    int pos1 = BM(texto1, padrao1);
    if(pos1 == -1){
        printf("Padrao nao encontrado\n");
    }
    else printf("Padrao encontrado no indice: %d \n", pos1);
    endBM = clock();
    printf("\nTempo de execucao BM: %5.2f seg.\n\n", ((double)(endBM - startBM)) / CLOCKS_PER_SEC);

    startBMH = clock();

    char texto2[] = "abcvvdabcvvdabcvvdabcvvdabcvvdabcvvdabcvvdabcvvdfasdfewgdsfEdfashWFDAsad"; //poderiam utilizar o "mesmo" texto
	char padrao2[100];

    printf("Digite o padrão a ser buscado(BMH): ");
    fgets(padrao2, sizeof(padrao2), stdin);
    padrao2[strcspn(padrao2, "\n")] = '\0';

    int pos2 = BMH(texto2, padrao2);
    if(pos2 == -1){
        printf("Padrao nao encontrado\n");
    }
    else printf("Padrao encontrado no indice: %d \n", pos2);

    endBMH = clock();
    printf("\nTempo de execucao BMH: %5.2f seg.\n", ((double)(endBMH - startBMH)) / CLOCKS_PER_SEC);

    return 0;
}