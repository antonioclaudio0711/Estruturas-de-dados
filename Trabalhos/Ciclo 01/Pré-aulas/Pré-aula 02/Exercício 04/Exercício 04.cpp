#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

typedef struct aluno {
		int matricula;
		char primeiro_nome[40];
		int ano_nascimento;
} aluno;
	
main(){
	setlocale(LC_ALL, "Portuguese");
	
	int registros;
	aluno *ponteiro;
	ponteiro = (aluno *) malloc(registros * sizeof(aluno));
	
	printf("Insira o número de registros a serem alocados:");
	scanf("%i", &registros);
	
	for(int i=0; i<registros; i++) {
		printf("\nInsira o número da matrícula do aluno:");
		scanf("%i", &ponteiro[i].matricula);
		printf("\nInsira o primeiro nome do aluno (sem acentos):");
		scanf("%s", &ponteiro[i].primeiro_nome);
		printf("\nInsira o ano de nascimento do aluno:");
		scanf("%i", &ponteiro[i].ano_nascimento);
		printf("\n");
	}
	
	printf("\nOs registros inseridos foram:\n");
	for(int i=0; i<registros; i++) {
		printf("Número de matrícula: %i\n", ponteiro[i].matricula);
		printf("Primeiro nome: %s\n", ponteiro[i].primeiro_nome);
		printf("Ano de nascimento: %i\n", ponteiro[i].ano_nascimento);
		printf("\n");
	}
	free(ponteiro);
}
