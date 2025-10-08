#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// int buscaBin(int vetor, int chave){
// 	int dir = MAX;
// 	int esq = 0;
// }

// int* lerArquivoDinamicamente(const char* caminhoArquivo, int* tamanhoVetor) {
//     FILE* arquivo = fopen(caminhoArquivo, "r");
//     if (arquivo == NULL) {
//         perror("Erro ao abrir o arquivo");
//         return NULL;
//     }

//     char* linha = NULL;
//     size_t len = 0;
//     ssize_t read;
//     int capacidade = 10;
//     int tamanho = 0;

//     int* vetor = malloc(capacidade * sizeof(int));
//     if (vetor == NULL) {
//         perror("Erro de alocação");
//         fclose(arquivo);
//         return NULL;
//     }

//     while ((read = getline(&linha, &len, arquivo)) != -1) {
//         if (tamanho >= capacidade) {
//             capacidade *= 2;
//             int* novoVetor = realloc(vetor, capacidade * sizeof(int));
//             if (novoVetor == NULL) {
//                 perror("Erro ao realocar memória");
//                 free(vetor);
//                 free(linha);
//                 fclose(arquivo);
//                 return NULL;
//             }
//             vetor = novoVetor;
//         }

//         vetor[tamanho] = atoi(linha); // converte a linha lida em int
//         tamanho++;
//     }

//     free(linha);
//     fclose(arquivo);

//     *tamanhoVetor = tamanho;
//     return vetor;
// }

int* 

int main(){
	clock_t start, end;
	start = clock();
	FILE* readInt;
	readInt = fopen("./static/random_int.txt", "r");
	
	// int vetor[MAX] = {0,3,5,6,7,8,9,19,29,34}
	printf("%d", readInt);
	//getchar();
	
	fclose(readInt);
	end = clock();
	printf("\n\n %5.2f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	return 0;
} 