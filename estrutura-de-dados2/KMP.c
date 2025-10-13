#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* geraVetor(const char* read, int* sizeVet) {
    FILE* readChar = fopen(read, "r");
    if (readChar == NULL) {
        perror("Erro ao abrir o arquivo de texto");
        *sizeVet = 0;
        return NULL;
    }
    char* arrayChar = NULL;
    int size = 0, cap = 10;
    int ch;
    arrayChar = (char*) malloc(sizeof(char) * cap);
    if (arrayChar == NULL) {
        perror("Erro na alocacao inicial");
        fclose(readChar);
        *sizeVet = 0;
        return NULL;
    }
    while ((ch = fgetc(readChar)) != EOF) {
        if (size == cap) {
            cap *= 2;
            char *temp = (char *) realloc(arrayChar, cap * sizeof(char));
            if (temp == NULL) {
                perror("Erro ao realocar memoria");
                free(arrayChar);
                fclose(readChar);
                *sizeVet = 0;
                return NULL;
            }
            arrayChar = temp;
        }
        arrayChar[size] = (char)ch;
        size++;
    }
    fclose(readChar);
    *sizeVet = size;
    return arrayChar;
}

void preKMP(const char* P, int m, int* aux, int* reps1) {
    int j = 0;
    aux[0] = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && P[i] != P[j]) {
            (*reps1)++;
            j = aux[j - 1];
        }
        (*reps1)++;
        if (P[i] == P[j]) {
            j++;
        }
        aux[i] = j;
    }
}

int buscaKMP(const char* T, int n, const char* P, int m, int* reps1, int* reps2) {
    if (m == 0) return 0;
    if (m > n) return -1;
    int* aux = (int*) malloc(sizeof(int) * m);
    if (aux == NULL) {
        perror("Erro ao alocar memoria para a tabela aux");
        return -1;
    }
    preKMP(P, m, aux, reps1);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) {
            (*reps2)++;
            j = aux[j - 1];
        }
        (*reps2)++;
        if (T[i] == P[j]) {
            j++;
        }
        if (j == m) {
            free(aux);
            return i - m + 1;
        }
    }
    free(aux);
    return -1;
}
int main() {
    clock_t start, end;
    start = clock();

    int tamanho_texto = 0;
    char* arrayChar = geraVetor("./static/random_strings_100_10.txt", &tamanho_texto);
    if (arrayChar == NULL) {
        return 1;
    }
    char pattern[100];
    printf("Digite o padrao: ");
    if (fgets(pattern, sizeof(pattern), stdin)) {
        pattern[strcspn(pattern, "\n")] = 0;
        int tamanho_padrao = strlen(pattern);
        if (tamanho_padrao == 0) {
            free(arrayChar);
            return 1;
        }
        int reps1 = 0, reps2 = 0;
        int indice = buscaKMP(arrayChar, tamanho_texto, pattern, tamanho_padrao, &reps1, &reps2);
        if (indice != -1) {
            printf("\nEncontrado no indice: %d\n", indice);
            printf("Comparacoes (pre-processamento): %d\n", reps1);
            printf("Comparacoes (busca): %d\n", reps2);
            printf("Total de comparacoes: %d\n", reps1 + reps2);
        } else {
            printf("\nNao foi encontrado.\n");
            printf("Total de comparacoes (ate o fim do arquivo): %d\n", reps1 + reps2);
        }
    }

    free(arrayChar);
    end = clock();
    printf("\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}