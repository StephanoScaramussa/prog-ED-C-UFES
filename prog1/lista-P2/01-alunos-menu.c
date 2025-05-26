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

void registrar_Dados(Aluno *vet_aluno, char (*vet_nome_disciplina)[max_nome]){
	for (int i = 0; i < qtd_alunos; i++)
	{
		printf("Nome do aluno: ");
		scanf("%s", vet_aluno[i].nome);
		for (int j = 0; j < qtd_disciplinas; j++)
		{
			printf("\nNota média de %s: ", vet_nome_disciplina[j]);
			scanf("%f", &vet_aluno[i].vet_disciplina[j].media[j]);
			printf("\nNota na PF de %s: ", vet_nome_disciplina[j]);
			scanf("%f", &vet_aluno[i].vet_disciplina[j].nota_final[j]);
		}
	}
}

void exibir_Reprovados(Aluno *vet_aluno, char (*vet_nome_disciplina)[max_nome]){
	for(int i=0; i<qtd_alunos; i++){
		for(int j=0; j<qtd_disciplinas; j++){
			float notaMedia = vet_aluno[i].vet_disciplina[j].media[j];
			float notaFinal = vet_aluno[i].vet_disciplina[j].nota_final[j];
			float mediaTotal = (notaFinal+notaMedia)/2;
			if(mediaTotal >= 7){
				continue;
			}
			if(notaFinal != -1 && mediaTotal>= 5){
				continue;
			}
			printf("%s reprovou em %s\n",vet_aluno[i].nome,vet_nome_disciplina[j]);
		}
	}
}

void salvar_Arquivo(Aluno *vet_aluno, char (*vet_nome_disciplina)[max_nome]){
	FILE*registro;
	registro = fopen("turma.txt","w");
	if(registro == NULL){
		printf("Erro ao abrir arquivo!");
	}
	else{
		fprintf(registro, "Lista de alunos e suas respectivas notas:");
		for (int i = 0; i < qtd_alunos; i++)
		{
			fprintf(registro, "\n%d/%s\n",i,vet_aluno[i].nome);
			for(int j=0; j< qtd_disciplinas; j++){
				fprintf(registro, "%s/Média:%.2f/PF:%.2f\n",vet_nome_disciplina[j],vet_aluno[i].vet_disciplina[j].media[j],vet_aluno[i].vet_disciplina[j].nota_final[j]);
			}
		}
		fclose(registro);
		printf("Arquivo salvo com sucesso!\n");
	}
}

void ler_Arquivo(Aluno *vet_aluno, char (*vet_nome_disciplina)[max_nome]){
	FILE*registro;
	registro = fopen("turma.txt", "r");
	if (registro == NULL){
		printf("Erro ao abrir arquivo!\n");
		return;
	}
	char linha[200];
	int id;
	char textin[200];
	fscanf(registro, "%[^\n]\n", textin);
	printf("\n%s\n",textin);
	for(int i=0; i<qtd_alunos; i++){
		fscanf(registro, "%d/%[^\n]\n", &id, vet_aluno[i].nome);
        	printf("\nAluno %d: %s\n", id+1, vet_aluno[i].nome);
		for(int j=0; j<qtd_disciplinas; j++){
			fscanf(registro, "%[^/]/Média:%f/PF:%f\n", linha, &vet_aluno[i].vet_disciplina[j].media[j], &vet_aluno[i].vet_disciplina[j].nota_final[j]);
			printf("%s: | Média: %.2f | PF: %.2f |\n", 
				linha, 
				vet_aluno[i].vet_disciplina[j].media[j], 
				vet_aluno[i].vet_disciplina[j].nota_final[j]);
		}
	}
	fclose(registro);
	printf("Leitura feita com sucesso!\n");
}

void main(){
	Aluno vet_aluno[qtd_alunos];
	char vet_nome_disciplina[qtd_disciplinas][max_nome]={
	"Calculo",
	"Programacao",
	"Ingles",
	"Vetores",
	"Algebra"
	};
	int opcao;
	
	do{
		printf("-Menu Ciencia da Computacao\n");
		printf("-1 Registrar um aluno.\n");
		printf("-2 Exibir alunos reprovados.\n");
		printf("-3 Salvar no arquivo.\n");
		printf("-4 Ler o arquivo.\n");
		printf("-0 Fechar.\n");
		printf("-Digite uma das opcoes: ");
		scanf("%d",&opcao);
		
		switch(opcao){
		case 1:
			registrar_Dados(vet_aluno, vet_nome_disciplina);
			break;
		case 2:
			exibir_Reprovados(vet_aluno, vet_nome_disciplina);
			break;
		case 3:
			salvar_Arquivo(vet_aluno, vet_nome_disciplina);
			break;
		case 4:
			ler_Arquivo(vet_aluno, vet_nome_disciplina);
			break;
		case 0:
			printf("Fechando...\n");
			break;
		default:
			printf("Opcao invalida.\n");
        }
	}
	while(opcao != 0);
}
