#include <stdio.h>
#include <string.h>
#include <time.h>

#define TAMANHO_ASCII 256
#define TAMANHO_MAX_NOS 100000

typedef struct TrieNode {
    int filhos[TAMANHO_ASCII];
    int fim_de_palavra;
} TrieNode;

typedef struct Trie {
    TrieNode nos[TAMANHO_MAX_NOS];
    int raiz;
    int proximo_no_livre;
} Trie;

void inicializar_no(TrieNode* no);
int no_tem_filhos(TrieNode* no);
int remover_recursivo(Trie* trie, int no_atual_idx, const char* palavra, int profundidade, int tamanho_palavra);

void inicializar_trie(Trie* trie) {
    trie->raiz = 0;
    trie->proximo_no_livre = 1;
    inicializar_no(&trie->nos[trie->raiz]);
}

void inserir(Trie* trie, const char* palavra) {
    int no_atual_idx = trie->raiz;
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        int indice_char = (unsigned char)palavra[i];
        if (trie->nos[no_atual_idx].filhos[indice_char] == -1) {
            if (trie->proximo_no_livre >= TAMANHO_MAX_NOS) {
                printf("Erro: A capacidade máxima da Trie foi excedida.\n");
                return;
            }
            int novo_no_idx = trie->proximo_no_livre;
            trie->proximo_no_livre++;
            inicializar_no(&trie->nos[novo_no_idx]);
            trie->nos[no_atual_idx].filhos[indice_char] = novo_no_idx;
        }
        no_atual_idx = trie->nos[no_atual_idx].filhos[indice_char];
    }
    trie->nos[no_atual_idx].fim_de_palavra = 1;
}

int buscar(Trie* trie, const char* palavra) {
    int no_atual_idx = trie->raiz;
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        int indice_char = (unsigned char)palavra[i];
        if (trie->nos[no_atual_idx].filhos[indice_char] == -1) {
            return 0;
        }
        no_atual_idx = trie->nos[no_atual_idx].filhos[indice_char];
    }
    return trie->nos[no_atual_idx].fim_de_palavra;
}

void remover(Trie* trie, const char* palavra) {
    if (palavra == NULL) {
        return;
    }
    int tamanho = strlen(palavra);
    if (tamanho == 0) {
        return;
    }
    remover_recursivo(trie, trie->raiz, palavra, 0, tamanho);
}

void inicializar_no(TrieNode* no) {
    no->fim_de_palavra = 0;
    for (int i = 0; i < TAMANHO_ASCII; i++) {
        no->filhos[i] = -1;
    }
}

int no_tem_filhos(TrieNode* no) {
    for (int i = 0; i < TAMANHO_ASCII; i++) {
        if (no->filhos[i] != -1) {
            return 1;
        }
    }
    return 0;
}

int remover_recursivo(Trie* trie, int no_atual_idx, const char* palavra, int profundidade, int tamanho_palavra) {
    if (no_atual_idx == -1) {
        return 0;
    }
    TrieNode* no_atual = &trie->nos[no_atual_idx];
    if (profundidade == tamanho_palavra) {
        if (no_atual->fim_de_palavra) {
            no_atual->fim_de_palavra = 0;
            if (!no_tem_filhos(no_atual)) {
                return 1;
            }
        }
        return 0;
    }
    int indice_char = (unsigned char)palavra[profundidade];
    int filho_idx = no_atual->filhos[indice_char];
    if (remover_recursivo(trie, filho_idx, palavra, profundidade + 1, tamanho_palavra)) {
        no_atual->filhos[indice_char] = -1;
        if (!no_atual->fim_de_palavra && !no_tem_filhos(no_atual)) {
            return 1;
        }
    }
    return 0;
}

int main(){
    clock_t start, end;
    start = clock();

    static Trie arvore;
    inicializar_trie(&arvore);
    inserir(&arvore, "romano");
    inserir(&arvore, "romulus");
    inserir(&arvore, "roma");
    inserir(&arvore, "tatu");

    remover(&arvore, "romano");

    end = clock();
    printf("\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}