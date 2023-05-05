#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct No{
	int valor;
	struct No *proximo;	
} No;

typedef struct {
	No *primeiro, *ultimo;
	int tamanho;
} ListaSimplesEncadeada;

//Inser��o de uma nota no in�cio da lista
void inserirElementoInicio(ListaSimplesEncadeada *lista, int valor) {
	No *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor;
	
	if(lista -> primeiro == NULL) { //Caso a lista esteja vazia
		novo -> proximo = NULL;
		lista -> primeiro = novo;
		lista -> ultimo = novo;
	} else { //Caso a lista n�o esteja vazia
		novo -> proximo = lista -> primeiro;
		lista -> primeiro = novo;
	}
	
	lista -> tamanho++;
}
//*********************************************************************

//Inser��o de uma nota no final da lista
void inserirElementoFinal(ListaSimplesEncadeada *lista, int valor) {
	No *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor;
	novo -> proximo = NULL;
	
	if(lista -> primeiro == NULL) { //Caso a lista esteja vazia
		lista -> primeiro = novo;
		lista -> ultimo = novo;
	} else { //Caso a lista n�o esteja vazia
		lista -> ultimo -> proximo = novo;
		lista -> ultimo = novo;
	}
	
	lista -> tamanho++;
}
//*********************************************************************

//Remover uma nota da lista
void remover(ListaSimplesEncadeada *lista, int valor) {
	No *inicio = lista -> primeiro;
	No *numeroRemover = NULL;
	
	if(inicio != NULL && lista -> primeiro -> valor == valor) { //Remo��o do primeiro elemento da lista
		numeroRemover = lista -> primeiro;
		lista -> primeiro = numeroRemover -> proximo;
		if(lista -> primeiro == NULL) {
			lista -> ultimo == NULL;
		}
	} else { //Remo��o de um elemento no meio ou no final da lista
		while(inicio != NULL && inicio -> proximo != NULL && inicio -> proximo -> valor != valor) {
			inicio = inicio -> proximo;
		}
		if(inicio != NULL && inicio -> proximo != NULL) {
			numeroRemover = inicio -> proximo;
			inicio -> proximo = numeroRemover -> proximo;
			if(inicio -> proximo == NULL) {
				lista -> ultimo = inicio;
			}
		}
	}
	
	if(numeroRemover) {
		free(numeroRemover); //Libera��o da mem�ria do n�
		lista -> tamanho--;
	}
}

//*********************************************************************

//Imprimir a lista de notas
void imprimir(ListaSimplesEncadeada *lista) {
	No *primeiro = lista -> primeiro;
	printf("Tamanho da lista: %i\n", lista -> tamanho);
	printf("LISTA: ");
	while(primeiro != NULL) {
		printf("%i ", primeiro -> valor);
		primeiro = primeiro -> proximo;
	}
}





main() {
	setlocale(LC_ALL, "Portuguese");
	
	ListaSimplesEncadeada lista;
	int opcao, valor;
	
	//Inicializa��o das listas criadas
	lista.primeiro = NULL;
	lista.ultimo = NULL;
	lista.tamanho = NULL;
	
	//Cria��o do menu de op��es
	do {
		printf("\n");
		printf("***************************************************************\n");
		printf("		MENU DE OP��ES		\n");
		printf("1 - Inserir uma nota no in�cio da lista\n");
		printf("2 - Inserir uma nota no fim da lista\n");
		printf("3 - Remover uma nota da lista\n");
		printf("4 - Imprimir a lista de notas\n");
		printf("5 - Sair\n");
		printf("Selecione uma das op��es apresentadas acima: ");
		scanf("%i", &opcao);
		printf("*****************************************************************");
		printf("\n");
		
		switch(opcao) {
			case 1:
				system("cls");
				printf("Voc� selecionou a op��o: 'Inserir uma nota no in�cio da lista'!\n");
				printf("Digite o valor a ser inserido: ");
				scanf("%i", &valor);
				inserirElementoInicio(&lista, valor);
				break;
			
			case 2:
				system("cls");
				printf("Voc� selecionou a op��o: 'Inserir uma nota no fim da lista'!\n");
				printf("Digite o valor a ser inserido: ");
				scanf("%i", &valor);
				inserirElementoFinal(&lista, valor);
				break;
				
			case 3:
				system("cls");
				printf("Voc� selecionou a op��o: 'Remover uma nota da lista'!\n");
				printf("Digite o valor a ser removido: ");
				scanf("%i", &valor);
				remover(&lista, valor);
				break;
				
			case 4:
				system("cls");
				printf("Voc� selecionou a op��o: 'Imprimir a lista de notas'!\n");
				imprimir(&lista);
				break;
				
			case 5:
				system("cls");
				printf("Voc� selecionou a op��o: 'Sair'!\n");
				printf("Obrigado por fazer uso do programa!\n");
				break;
				
			default:
				printf("Op��o inv�lida!\n");
				break;
		}
		
	} while(opcao != 5);
}
