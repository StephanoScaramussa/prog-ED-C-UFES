#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define qtd_obras 3
#define qtd_areas 3
#define max_char 100

typedef struct{
    int codigo;
    char nome[max_char];
    char autor[max_char];
    char editora[max_char];
    char doado[max_char];
    int paginas;
    char palavras_chaves[max_char];
    char assunto[max_char];
    int area;
}Obra;

int pesquisaCodigo(Obra *vet_obras){
    int codigo;
    printf("Digite o codigo da obra: ");
    scanf("%d", &codigo);
    for(int i=0;i<qtd_areas;i++){
        if(vet_obras[i].codigo == codigo){
            if(vet_obras[i].area == 0){
                printf("Codigo encontrado da obra %s, em Ciências Exatas, posição %d\n", vet_obras[i].nome,i);
                return i;
            }
            if(vet_obras[i].area == 1){
                printf("Codigo encontrado da obra %s, em Ciências Humanas, posição %d\n", vet_obras[i].nome,i);
                return i;
            }
            if(vet_obras[i].area == 2){
                printf("Codigo encontrado da obra %s, Ciências Biomédicas, posição %d\n", vet_obras[i].nome,i);
                return i;
            }
        }
    }
    return -1;
}

int obrasAutor(Obra *vet_obras){
    char autor_[max_char];
    int qtd_obras_autor = 0;
    printf("Digite o nome do autor: ");
    scanf(" %[^\n]", autor_);
    for(int i = 0; i < qtd_obras; i++){
        if(strcmp(autor_, vet_obras[i].autor) == 0){
            qtd_obras_autor++;
        }
    }
    printf("%s tem %d obras\n", autor_, qtd_obras_autor);
    return qtd_obras_autor;
}

void main(){
    Obra vet_obras[qtd_obras] = {
        {1, "lorem", "Seymour Lipschutz", "McGraw-Hill", "Sim", 500, "Matemática, Estatística", "Matemática", 0},
        {2, "ipsum", "Seymour Lipschutz", "McGraw-Hill", "Não", 1500, "Portugues, Gramatica", "Linguagens", 1},
        {3, "dolor", "KhaZhan", "Fores", "Sim", 2000, "Matemática, Calculo", "Integrais", 0}
    };
    pesquisaCodigo(vet_obras);
    obrasAutor(vet_obras);
}
