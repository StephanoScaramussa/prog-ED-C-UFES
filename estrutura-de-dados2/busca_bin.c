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

void buscaSeq(Descritor* lista, int chave, Descritor* indices) {
    int i = 0;
    for (NoLista* p = lista->prim; p != NULL; p = p->prox) {
        if (p->info == chave) {
            insereNoFinal(indices, i);
        }
        i++;
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
    FILE* readInt = fopen("./static/10K-int.txt", "r");
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
        buscaSeq(&lista, chave, &indices);
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