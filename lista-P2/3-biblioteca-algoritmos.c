#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define qtd_obras 3
#define qtd_disc 3
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
}Obra;

typedef struct{
    char nome[max_char];
    Obra vet_obras[qtd_obras];
}Materia;

int pesquisaCodigo(Materia *vet_materia){
    int codigo;
    printf("Digite o codigo da obra: ");
    scanf("%d", &codigo);
    for(int i=0;i<qtd_disc;i++){
        for(int j=0;j<qtd_obras;j++){
            if(vet_materia[i].vet_obras[j].codigo == codigo){
                printf("Codigo encontrado na materia %s, obra %s, posição %d/%d\n", vet_materia[i].nome, vet_materia[i].vet_obras[j].nome,i,j);
                return j;
            }
        }
    }
    return -1;
}

int obrasAutor(Materia *vet_materia){
    char autor_[max_char];
    int qtd_obras_autor=0;
    printf("Digite o nome do autor: ");
    scanf("%[^\n]", autor_);
    for(int i=0;i<qtd_disc;i++){
        for(int j=0;j<qtd_obras;j++){
            if(*autor_ == *vet_materia[i].vet_obras[j].nome){
                qtd_obras_autor++;
            }
        }
    }
    printf("%s tem %d obras\n", autor_, qtd_obras_autor);
    return qtd_obras_autor;
}

void main(){
    Materia vet_materia[]={
        {
            "Ciências Exatas",{
                {1, "lorem", "Seymour Lipschutz", "McGraw-Hill", "Sim", 500, "Matemática, Estatística", "Matemática"},
                {2, "ipsum", "Seymour Lipschutz", "McGraw-Hill", "Não", 1500, "Portugues, Gramatica", "Linguagens"},
                {3, "dolor", "KhaZhan", "Fores", "Sim", 2000, "Matemática, Calculo", "Integrais"}
            }
        },
            {"Ciências Humanas",{
                {1, "lorem", "Seymour Lipschutz", "McGraw-Hill", "Sim", 500, "Matemática, Estatística", "Matemática"},
                {2, "densin", "Seymour", "Hill", "Não", 1500, "Portugues, Gramatica", "Linguagens"},
                {3, "opren", "KhaZhan", "Fores", "Sim", 2000, "Matemática, Calculo", "Integrais"}
            }
        },
        {
            "Ciências Biomédicas",{
                {1, "lorem", "Seymour Lipschutz", "McGraw-Hill", "Sim", 500, "Matemática, Estatística", "Matemática"},
                {2, "ipsum", "Seymour Lipschutz", "McGraw-Hill", "Não", 1500, "Portugues, Gramatica", "Linguagens"},
                {3, "dolor", "KhaZhan", "Fores", "Sim", 2000, "Matemática, Calculo", "Integrais"}
            }
        }
    };

    pesquisaCodigo(vet_materia);
    obrasAutor(vet_materia);

}
