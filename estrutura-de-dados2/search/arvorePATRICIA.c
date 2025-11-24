#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_ASCII 256
#define TAMANHO_MAX_NOS 100000

typedef struct noPATRICIA {
    int filhos[TAMANHO_ASCII];
    char* arestas[TAMANHO_ASCII];
    int fim_de_palavra;
} noPATRICIA;

typedef struct Trie {
    noPATRICIA nos[TAMANHO_MAX_NOS];
    int raiz;
    int proximo_no_livre;
} Trie;

void inicializar_no(noPATRICIA* no) {
    no->fim_de_palavra = 0;
    for (int i = 0; i < TAMANHO_ASCII; i++) {
        no->filhos[i] = -1;
        no->arestas[i] = NULL;
    }
}

void inicializar_trie(Trie* trie) {
    trie->raiz = 0;
    trie->proximo_no_livre = 1;
    inicializar_no(&trie->nos[trie->raiz]);
}

int novo_no(Trie* trie) {
    if (trie->proximo_no_livre >= TAMANHO_MAX_NOS) {
        printf("Erro: A capacidade máxima da Trie foi excedida.\n");
        return -1;
    }
    int novo_no_idx = trie->proximo_no_livre;
    trie->proximo_no_livre++;
    inicializar_no(&trie->nos[novo_no_idx]);
    return novo_no_idx;
}

char* duplicar_string(const char* s) {
    if (!s) return NULL;
    size_t len = strlen(s) + 1;
    char* novo = (char*)malloc(len);
    if (novo) {
        memcpy(novo, s, len);
    }
    return novo;
}

int calcular_lcp(const char* s1, const char* s2) {
    int len = 0;
    while (s1[len] && s2[len] && s1[len] == s2[len]) {
        len++;
    }
    return len;
}

void inserir_recursivo(Trie* trie, int no_idx, const char* palavra) {
    if (palavra == NULL || *palavra == '\0') {
        trie->nos[no_idx].fim_de_palavra = 1;
        return;
    }

    int indice_char = (unsigned char)palavra[0];
    char* aresta_existente = trie->nos[no_idx].arestas[indice_char];
    int filho_idx = trie->nos[no_idx].filhos[indice_char];

    if (aresta_existente == NULL) {
        int novo_filho_idx = novo_no(trie);
        if (novo_filho_idx == -1) return;

        trie->nos[no_idx].arestas[indice_char] = duplicar_string(palavra);
        trie->nos[no_idx].filhos[indice_char] = novo_filho_idx;
        trie->nos[novo_filho_idx].fim_de_palavra = 1;
        return;
    }

    int lcp = calcular_lcp(palavra, aresta_existente);
    int len_aresta = strlen(aresta_existente);
    int len_palavra = strlen(palavra);

    if (lcp == len_aresta && lcp < len_palavra) {
        inserir_recursivo(trie, filho_idx, palavra + lcp);
        return;
    }

    if (lcp == len_palavra && lcp < len_aresta) {
        char* sufixo_aresta = duplicar_string(aresta_existente + lcp);
        
        int no_intermediario_idx = novo_no(trie);
        if (no_intermediario_idx == -1) {
            free(sufixo_aresta);
            return;
        }

        char* prefixo = (char*)malloc(lcp + 1);
        strncpy(prefixo, aresta_existente, lcp);
        prefixo[lcp] = '\0';

        free(trie->nos[no_idx].arestas[indice_char]);
        trie->nos[no_idx].arestas[indice_char] = prefixo;
        trie->nos[no_idx].filhos[indice_char] = no_intermediario_idx;

        trie->nos[no_intermediario_idx].fim_de_palavra = 1;

        int indice_sufixo = (unsigned char)sufixo_aresta[0];
        trie->nos[no_intermediario_idx].arestas[indice_sufixo] = sufixo_aresta;
        trie->nos[no_intermediario_idx].filhos[indice_sufixo] = filho_idx;
        return;
    }

    if (lcp == len_palavra && lcp == len_aresta) {
        trie->nos[filho_idx].fim_de_palavra = 1;
        return;
    }

    if (lcp < len_palavra && lcp < len_aresta) {
        char* sufixo_aresta = duplicar_string(aresta_existente + lcp);
        char* sufixo_palavra = duplicar_string(palavra + lcp);

        int no_intermediario_idx = novo_no(trie);
        if (no_intermediario_idx == -1) {
            free(sufixo_aresta);
            free(sufixo_palavra);
            return;
        }

        int novo_no_palavra_idx = novo_no(trie);
        if (novo_no_palavra_idx == -1) {
            free(sufixo_aresta);
            free(sufixo_palavra);
            return;
        }

        char* prefixo = (char*)malloc(lcp + 1);
        strncpy(prefixo, aresta_existente, lcp);
        prefixo[lcp] = '\0';

        free(trie->nos[no_idx].arestas[indice_char]);
        trie->nos[no_idx].arestas[indice_char] = prefixo;
        trie->nos[no_idx].filhos[indice_char] = no_intermediario_idx;

        int indice_sufixo_aresta = (unsigned char)sufixo_aresta[0];
        trie->nos[no_intermediario_idx].arestas[indice_sufixo_aresta] = sufixo_aresta;
        trie->nos[no_intermediario_idx].filhos[indice_sufixo_aresta] = filho_idx;

        int indice_sufixo_palavra = (unsigned char)sufixo_palavra[0];
        trie->nos[no_intermediario_idx].arestas[indice_sufixo_palavra] = sufixo_palavra;
        trie->nos[no_intermediario_idx].filhos[indice_sufixo_palavra] = novo_no_palavra_idx;
        trie->nos[novo_no_palavra_idx].fim_de_palavra = 1;

        return;
    }
}

void inserir(Trie* trie, const char* palavra) {
    inserir_recursivo(trie, trie->raiz, palavra);
}

int buscar(Trie* trie, const char* palavra) {
    int no_atual_idx = trie->raiz;
    int i = 0;
    int len_palavra = strlen(palavra);

    while (i < len_palavra) {
        if (no_atual_idx == -1) return 0;

        noPATRICIA* no_atual = &trie->nos[no_atual_idx];
        int indice_char = (unsigned char)palavra[i];

        char* aresta = no_atual->arestas[indice_char];
        int proximo_no_idx = no_atual->filhos[indice_char];

        if (aresta == NULL) {
            return 0;
        }

        int k = 0;
        int len_aresta = strlen(aresta);
        while (k < len_aresta && i < len_palavra && palavra[i] == aresta[k]) {
            i++;
            k++;
        }

        if (k < len_aresta) {
            return 0;
        }
        
        no_atual_idx = proximo_no_idx;
    }

    return (no_atual_idx != -1) && trie->nos[no_atual_idx].fim_de_palavra;
}

void remover(Trie* trie, const char* palavra) {
    int no_atual_idx = trie->raiz;
    int i = 0;
    int len_palavra = strlen(palavra);

    while (i < len_palavra) {
        if (no_atual_idx == -1) return;

        noPATRICIA* no_atual = &trie->nos[no_atual_idx];
        int indice_char = (unsigned char)palavra[i];

        char* aresta = no_atual->arestas[indice_char];
        int proximo_no_idx = no_atual->filhos[indice_char];

        if (aresta == NULL) {
            return;
        }

        int k = 0;
        int len_aresta = strlen(aresta);
        while (k < len_aresta && i < len_palavra && palavra[i] == aresta[k]) {
            i++;
            k++;
        }

        if (k < len_aresta) {
            return;
        }
        
        no_atual_idx = proximo_no_idx;
    }

    if (no_atual_idx != -1) {
        trie->nos[no_atual_idx].fim_de_palavra = 0;
    }
}

void liberar_no_recursivo(Trie* trie, int no_idx) {
    if (no_idx == -1) return;
    
    noPATRICIA* no = &trie->nos[no_idx];
    for (int i = 0; i < TAMANHO_ASCII; i++) {
        if (no->arestas[i] != NULL) {
            free(no->arestas[i]);
            liberar_no_recursivo(trie, no->filhos[i]);
        }
    }
}

void destruir_trie(Trie* trie) {
    liberar_no_recursivo(trie, trie->raiz);
    inicializar_trie(trie);
}

int main() {
    clock_t start, end;
    start = clock();

    static Trie arvore;
    inicializar_trie(&arvore);
    inserir(&arvore, "romano");
    inserir(&arvore, "romulus");
    inserir(&arvore, "roma");
    inserir(&arvore, "tatu");

    printf("Buscar 'roma': %d\n", buscar(&arvore, "roma"));
    printf("Buscar 'romano': %d\n", buscar(&arvore, "romano"));
    printf("Buscar 'romulus': %d\n", buscar(&arvore, "romulus"));
    printf("Buscar 'tatu': %d\n", buscar(&arvore, "tatu"));
    printf("Buscar 'rom': %d\n", buscar(&arvore, "rom"));

    remover(&arvore, "romano");

    printf("\nApos remover 'romano':\n");
    printf("Buscar 'roma': %d\n", buscar(&arvore, "roma"));
    printf("Buscar 'romano': %d\n", buscar(&arvore, "romano"));
    printf("Buscar 'romulus': %d\n", buscar(&arvore, "romulus"));
    printf("Buscar 'tatu': %d\n", buscar(&arvore, "tatu"));
    printf("Buscar 'teste': %d\n", buscar(&arvore, "teste"));

    destruir_trie(&arvore);

    end = clock();
    printf("\nTempo de execucao: %5.2f seg.\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}