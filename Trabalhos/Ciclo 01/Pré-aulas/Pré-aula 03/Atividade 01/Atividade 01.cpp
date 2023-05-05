#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct data_nascimento {
	int dia;
	int mes;
	int ano;	
} data_nascimento;

typedef struct {
	char nome[40];
	data_nascimento data;
	int CPF;
} pessoa;

void preencher(pessoa *ptr, int tamanho){
	for(int i = 1; i <= tamanho; i++) {
		printf("\nPREENCHENDO O REGISTRO\n");
		printf("Insira o nome da pessoa a ser cadastrada:");
		scanf("%s", &ptr[i].nome);
		printf("\nInsira o CPF da pessoa a ser cadastrada (sem traço):");
		scanf("%i", &ptr[i].CPF);
		printf("\nInsira o dia de nascimento da pessoa:");
		scanf("%i", &ptr[i].data.dia);
		printf("\nInsira de forma numérica o mês de nascimento da pessoa:");
		scanf("%i", &ptr[i].data.mes);
		printf("\nInsira o ano de nascimento da pessoa:");
		scanf("%i", &ptr[i].data.ano);
	}
}

void mostrar(pessoa *ptr, int tamanho) {
	printf("***********************************");
	for(int i = 1; i <= tamanho; i ++) {
		printf("\nREGISTRO %i\n", i);
		printf("Nome: %s\n", ptr[i].nome);
		printf("CPF: %i\n", ptr[i].CPF);
		printf("Data de nascimento: %i/%i/%i\n", ptr[i].data.dia, ptr[i].data.mes, ptr[i].data.ano);
	}
}

main() {
	setlocale(LC_ALL, "Portuguese");
	
	pessoa *ponteiro;
	int tamanho;
	
	ponteiro = (pessoa *) malloc(tamanho * sizeof(pessoa));
	
	printf("Informe o número de registros a serem adicionados:");
	scanf("%i", &tamanho);
	preencher(ponteiro, tamanho);
	mostrar(ponteiro, tamanho);
}
