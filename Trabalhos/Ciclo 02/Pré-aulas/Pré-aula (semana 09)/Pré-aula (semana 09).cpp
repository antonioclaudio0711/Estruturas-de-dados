#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

typedef struct no {
	int valor;
	struct no *proximo;
} No;

typedef struct {
	No *inicio;
	No *fim;
	int tamanho;
} Lista;

//Prot�tipo de fun��o para se criar uma lista encadeada circular
void criar_lista(Lista *lista);

//Prot�tipo de fun��o para inserir um elemento no in�cio da lista encadeada circular
void inserir_no_inicio(Lista *lista, int num);

//Prot�tipo de fun��o para imprimir a lista encadeada circular
void imprimir (Lista lista);

main() {
	setlocale(LC_ALL, "Portuguese");
	
	int opcao, valor, anterior;
	Lista lista;
	
	criar_lista(&lista);
	
	do {
		printf("*************************************************\n");
		printf("		MENU DE OP��ES		\n");
		printf("1 - Inserir um elemento(n�) no in�cio da lista\n");
		printf("2 - Imprimir a lista encadeada circular\n");
		printf("3 - Sair\n");
		printf("*************************************************\n");
		printf("Selecione uma das op��es apresentadas no menu acima:\n");
		scanf("%i", &opcao);
		
		switch(opcao) {
			case 1:
				printf("Voc� selecionou a op��o: 'Inserir um elemento (n�) no in�cio da lista'!\n");
				printf("Digite um valor:\n");
				scanf("%i", &valor);
				inserir_no_inicio(&lista, valor);			
				break;
				
			case 2:
				printf("Voc� selecionou a op��o: 'Imprimir a lista encadeada circular'!\n");
				imprimir(lista);
				break;
				
			case 3:
				printf("Obrigado por fazer uso do programa!\n");
				break;
				
			default:
				printf("Selecione uma op��o v�lida!\n");
		}
	} while (opcao != 3);
}

void criar_lista(Lista *lista) {
	lista -> inicio = NULL;
	lista -> fim = NULL;
	lista -> tamanho = 0;
}

void inserir_no_inicio(Lista *lista, int num) {
	No *novo;
	novo = (No *) malloc(sizeof(No));
	
	if(novo) {
		novo -> valor = num;
		novo -> proximo = lista -> inicio;
		lista -> inicio = novo;
		
		if (lista -> fim = NULL) {
			lista -> fim = novo;
		}
		lista -> fim -> proximo = lista -> inicio;
		lista -> tamanho++;
	} else {
		printf("Erro ao alocar mem�ria!");
	}
}

void imprimir (Lista lista) {
	No *no = lista.inicio;
	printf("Tamanho da lista encadeada circular: %i", lista.tamanho);
	if(no) {
		do {
			printf("%i ", no -> valor);
			no = no -> proximo;
		} while (no != lista.inicio);
		printf("In�cio da lista: %i\n", no -> valor);
	}
	printf("\n\n");
}
