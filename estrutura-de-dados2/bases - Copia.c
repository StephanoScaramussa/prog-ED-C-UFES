#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

int buscaBin(int vetor, int chave){
	int dir = MAX;
	int esq = 0;
}

int main(){
	clock_t start, end;
	start = clock();
	
	int vetor[MAX] = {0,3,5,6,7,8,9,19,29,34}

	//getchar();
	
	end = clock();
	printf("\n\n %5.2f seg.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	return 0;
}