#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* geraVetor(const char*read, int*sizeVet){
    FILE* readIntAsc = fopen(read, "r");
    if (readIntAsc == NULL) {
        printf("Erro ao abrir o arquivo");
        *sizeVet = 0;
        return NULL;
    }
    int* arrayInt = NULL;
    int size = 0, cap = 10, num;
    arrayInt = (int*) malloc(sizeof(int)*cap);
    while (fscanf(readIntAsc, "%d", &num) == 1) {
        if (size == cap) {
            cap *= 2;
            int *temp = (int *) realloc(arrayInt, cap * sizeof(int));
            if (temp == NULL) {
                perror("Erro ao realocar memoria");
                free(arrayInt);
                fclose(readIntAsc);
                return NULL;
            }
            arrayInt = temp;
        }
        arrayInt[size] = num;
        size++;
    }
    fclose(readIntAsc);
    *sizeVet = size;
    return arrayInt;
}

int buscaBin(int*array, int*index, int sizeVet){
    int ini = 0, fim = sizeVet-1, meio, key;
    printf("Valor a ser buscado: ");
    scanf("%d",&key);
    while(ini<=fim){
        meio = (ini+fim)/2;
        if(key<array[meio]){
            fim = meio-1;
        }
        else if(key>array[meio]){
            ini = meio + 1;
        }
        else{
            *index = meio;
            printf("Valor encontrado! Index: %d\n", meio);
            return array[meio];
        }
    }
    printf("Valor não encontrado!\n");
    return -1;
}

int buscaBinRec(int*array, int ini, int fim, int key){
    int meio = (ini+fim)/2;
    if(ini>fim){
        printf("Valor não encontrado!\n");
        return -1;
    }
    else if(key<array[meio]){
        buscaBinRec(array, ini, meio-1, key);
    }
    else if(key>array[meio]){
        buscaBinRec(array, meio+1, fim, key);
    }
    else{
        printf("Valor encontrado! Index: %d\n", meio);
        return array[meio];
    }
};

int main() {
    clock_t start, end;
    start = clock();
    int sizeVet = 0, indexFound, key;
    int* arrayInt = geraVetor("./static/10K-int-ordenado.txt", &sizeVet);

    int valor = buscaBin(arrayInt, &indexFound, sizeVet);
    printf("Valor a ser buscado(bin): ");
    scanf("%d",&key);
    int valor2 = buscaBinRec(arrayInt, 0, sizeVet-1, key);

    free(arrayInt);
    end = clock();
    printf("\n\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}