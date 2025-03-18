#include <stdio.h>
#include <stdlib.h>

#define qtd_alunos 10
#define qtd_disciplinas 5
#define max_nome 100

typedef struct{
	float media[qtd_disciplinas];
	float nota_final[qtd_disciplinas];
} Disciplina;

typedef struct{
	char nome[max_nome];
	Disciplina vet_disciplina[qtd_disciplinas];
} Aluno;

void registrar_Dados(Aluno vet_aluno[], vet_nome_disciplina[], int i){
	while(i<2){
		printf("Digite o nome do aluno: ");
		
		i++;
	}
}

void exibir_Reprovados(Aluno vet_aluno[]){
	
}

void salvar_Arquivo(Aluno vet_aluno[]){
	
}

void ler_Arquivo(Aluno vet_aluno[]){
	
}

void main(){
	Aluno vet_aluno[qtd_alunos];
	char vet_nome_disciplina[
	"Calculo",
	"Programacao",
	"Ingles",
	"Vetores",
	"Algebra"
	][max_nome];
	int opcao;
	
	do{
		printf("-Menu Ciencia da Computacao\n");
		printf("-1 Registrar um aluno.\n");
		printf("-2 Exibir alunos reprovados.\n");
		printf("-3 Salvar no arquivo.\n");
		printf("-4 Ler o arquivo.\n");
		printf("-0 Fechar.\n");
		printf("-Digite uma das opcoes:\n");
		scanf("%d",&opcao);
		
		switch(opcao)
		case 1:
			registrar_Dados(vet_aluno, vet_nome_disciplina);
			break;
		case 2:
			exibir_Reprovados();
			break;
		case 3:
			salvar_Arquivo(vet_aluno, vet_nome_disciplina);
			break;
		case 4:
			ler_Arquivo();
			break;
		case 0:
			printf("Fechando...\n");
			break;
		default:
			printf("Opcao invalida.\n");
	}
	while(opcao != 0);
}
