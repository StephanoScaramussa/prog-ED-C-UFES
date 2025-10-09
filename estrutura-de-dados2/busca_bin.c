#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nolista {
    int info;
    struct nolista* prox;
} NoLista;

typedef struct descritor {
    NoLista* prim;
    NoLista* ult;
    int n;
} Descritor;

void criaLista(Descritor* l) {
    l->prim = l->ult = NULL;
    l->n = 0;
}

int estaVazia(Descritor* l) {
    return (l->n == 0);
}

void insereNoFinal(Descritor* l, int valor) {
    NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
    if (novo != NULL) {
        novo->info = valor;
        novo->prox = NULL;
        if (!estaVazia(l)) {
            l->ult->prox = novo;
            l->ult = novo;
        } else {
            l->ult = novo;
            l->prim = novo;
        }
        l->n++;
    } else {
        printf("Não foi possível alocar espaço!");
    }
}

void geraLista(FILE* readfile, Descritor* l) {
    if (readfile == NULL) {
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), readfile) != NULL) {
        insereNoFinal(l, atoi(line));
    }
}

void buscaBin(Descritor* lista, int chave, Descritor* indices) {
    int i = 0;
    for (NoLista* p = lista->prim; i!=(lista->n)/2; p = p->prox, i++) {
        
    }
}

void printaIndices(Descritor* indices) {
    printf("O valor aparece %d vez(es) nos seguintes índices:\n", indices->n);
    for (NoLista* p = indices->prim; p != NULL; p = p->prox) {
        printf("index %d\n", p->info);
    }
}

void liberaLista(Descritor* l) {
    NoLista* p, * temp;
    for (p = l->prim; p != NULL; p = temp) {
        temp = p->prox;
        free(p);
    }
    l->prim = l->ult = NULL;
    l->n = 0;
}

int main() {
    clock_t start, end;
    start = clock();
    FILE* readInt = fopen("./static/10K-int-ordenado.txt", "r");
    if (readInt == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    Descritor lista;
    criaLista(&lista);
    geraLista(readInt, &lista);
    fclose(readInt);
    if (!estaVazia(&lista)) {
        int chave;
        printf("Valor a ser buscado: ");
        scanf("%d", &chave);
        Descritor indices;
        criaLista(&indices);
        buscaBin(&lista, chave, &indices);
        if (estaVazia(&indices)) {
            printf("Valor não encontrado!\n");
        } else {
            printaIndices(&indices);
        }
        liberaLista(&indices);
        liberaLista(&lista);
    } else {
        printf("A lista principal está vazia ou não foi lida.\n");
    }

    end = clock();
    printf("\n\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    return 0;
}


//implementar com vetor dinamicamente

#include <stdio.h>
#include <stdlib.h> // Essencial para malloc, realloc e free

int main() {
    // --- 1. Declaração de Variáveis ---
    FILE *ponteiro_arquivo;
    char *nome_arquivo = "10K-int.txt";

    int *vetor = NULL; // Ponteiro para nosso vetor dinâmico
    int tamanho = 0;       // Quantidade de números lidos até agora
    int capacidade = 10;   // Capacidade atual do vetor

    // --- 2. Alocação de Memória Inicial ---
    // Aloca espaço para 10 inteiros inicialmente
    vetor = (int *) malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        perror("Erro ao alocar memoria inicial");
        return 1; // Encerra o programa se a memória não puder ser alocada
    }

    // --- 3. Abrindo o Arquivo ---
    ponteiro_arquivo = fopen(nome_arquivo, "r"); // "r" = read (leitura)
    if (ponteiro_arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        free(vetor); // Libera a memória que já foi alocada
        return 1;   // Encerra o programa se o arquivo não for encontrado
    }

    printf("Lendo o arquivo %s...\n", nome_arquivo);

    // --- 4. Loop de Leitura e Armazenamento ---
    int numero;
    // fscanf retorna 1 se conseguiu ler um inteiro com sucesso
    while (fscanf(ponteiro_arquivo, "%d", &numero) == 1) {
        // Verifica se o vetor está cheio
        if (tamanho == capacidade) {
            // Dobra a capacidade
            capacidade *= 2;
            printf("Vetor cheio. Realocando para %d posicoes...\n", capacidade);
            
            // Tenta realocar para o novo tamanho
            int *temp = (int *) realloc(vetor, capacidade * sizeof(int));
            if (temp == NULL) {
                perror("Erro ao realocar memoria");
                free(vetor);
                fclose(ponteiro_arquivo);
                return 1;
            }
            // Se a realocação deu certo, atualiza o ponteiro principal
            vetor = temp;
        }

        // Armazena o número lido e incrementa o tamanho
        vetor[tamanho] = numero;
        tamanho++;
    }

    // --- 5. Fechando o Arquivo ---
    fclose(ponteiro_arquivo);

    printf("\nLeitura concluida com sucesso!\n");
    printf("Total de numeros lidos: %d\n", tamanho);

    // Demonstração: Imprime os 10 primeiros números do vetor para confirmar
    printf("Os 10 primeiros numeros do vetor sao:\n");
    for (int i = 0; i < 10 && i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // --- 6. Liberando a Memória ---
    // Essencial para evitar vazamento de memória (memory leak)
    free(vetor);

    return 0;
}