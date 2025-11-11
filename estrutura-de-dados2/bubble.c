#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10000

int* geraVetor(int size){
    int *vet = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++){
        vet[i] = rand() % 100;
    }
    return vet;
}

int* bubbleSort(int* vetor){
    for(int i = N-1; i>=1; i--){
        for(int j = 0; j < i; j++){
            if(vetor[j] > vetor[j+1]){
                int auxiliar = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = auxiliar;
            }
        }
    }
    return vetor;
}

int main(){
    clock_t start, end;
    start = clock();

    int *vet = geraVetor(N);

    vet = bubbleSort(vet);

    for(int i=0; i<N; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
    end = clock();
    printf("\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}