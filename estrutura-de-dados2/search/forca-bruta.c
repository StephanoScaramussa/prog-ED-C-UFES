#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* geraVetor(const char* read, int* sizeVet) {
    FILE* readChar = fopen(read, "r");
    if (readChar == NULL) {
        perror("Erro ao abrir o arquivo");
        *sizeVet = 0;
        return NULL;
    }
    char* arrayChar = NULL;
    int size = 0, cap = 10, ch;
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

int forcaBruta(const char* T, int n, const char* P, int* reps) {
    int m = strlen(P);
    if (m == 0 || m > n) {
        return -1;
    }
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            (*reps)++;
            if (T[i + j] != P[j]) {
                break;
            }
        }
        if (j == m) {
            return i;
        }
    }
    return -1;
}

int main() {
    clock_t start, end;
    start = clock();
    int sizeVet = 0, reps = 0;
    char* arrayChar = geraVetor("./static/random_strings_100_10.txt", &sizeVet);
    if (arrayChar == NULL) {
        printf("Falha ao ler o arquivo de texto!\n");
        return 1;
    }
    char pattern[100];
    printf("Digite o padrao: ");
    if (fgets(pattern, sizeof(pattern), stdin)) {
        pattern[strcspn(pattern, "\n")] = 0;
        int indice = forcaBruta(arrayChar, sizeVet, pattern, &reps);
        if (indice != -1) {
            printf("\nEncontrado no indice: %d, com %d comparacao(oes)\n", indice, reps);
        } else {
            printf("\nNao foi encontrado.\n");
        }
    }

    free(arrayChar);
    end = clock();
    printf("\n\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}