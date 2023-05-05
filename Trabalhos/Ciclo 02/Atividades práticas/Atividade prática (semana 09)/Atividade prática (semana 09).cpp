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

//Inserção de uma nota no início da lista
void inserirElementoInicio(ListaSimplesEncadeada *lista, int valor) {
	No *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor;
	
	if(lista -> primeiro == NULL) { //Caso a lista esteja vazia
		novo -> proximo = NULL;
		lista -> primeiro = novo;
		lista -> ultimo = novo;
	} else { //Caso a lista não esteja vazia
		novo -> proximo = lista -> primeiro;
		lista -> primeiro = novo;
	}
	
	lista -> tamanho++;
}
//*********************************************************************

//Inserção de uma nota no final da lista
void inserirElementoFinal(ListaSimplesEncadeada *lista, int valor) {
	No *novo = (No*)malloc(sizeof(No));
	novo -> valor = valor;
	novo -> proximo = NULL;
	
	if(lista -> primeiro == NULL) { //Caso a lista esteja vazia
		lista -> primeiro = novo;
		lista -> ultimo = novo;
	} else { //Caso a lista não esteja vazia
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
	
	if(inicio != NULL && lista -> primeiro -> valor == valor) { //Remoção do primeiro elemento da lista
		numeroRemover = lista -> primeiro;
		lista -> primeiro = numeroRemover -> proximo;
		if(lista -> primeiro == NULL) {
			lista -> ultimo == NULL;
		}
	} else { //Remoção de um elemento no meio ou no final da lista
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
		free(numeroRemover); //Liberação da memória do nó
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
	
	//Inicialização das listas criadas
	lista.primeiro = NULL;
	lista.ultimo = NULL;
	lista.tamanho = NULL;
	
	//Criação do menu de opções
	do {
		printf("\n");
		printf("***************************************************************\n");
		printf("		MENU DE OPÇÕES		\n");
		printf("1 - Inserir uma nota no início da lista\n");
		printf("2 - Inserir uma nota no fim da lista\n");
		printf("3 - Remover uma nota da lista\n");
		printf("4 - Imprimir a lista de notas\n");
		printf("5 - Sair\n");
		printf("Selecione uma das opções apresentadas acima: ");
		scanf("%i", &opcao);
		printf("*****************************************************************");
		printf("\n");
		
		switch(opcao) {
			case 1:
				system("cls");
				printf("Você selecionou a opção: 'Inserir uma nota no início da lista'!\n");
				printf("Digite o valor a ser inserido: ");
				scanf("%i", &valor);
				inserirElementoInicio(&lista, valor);
				break;
			
			case 2:
				system("cls");
				printf("Você selecionou a opção: 'Inserir uma nota no fim da lista'!\n");
				printf("Digite o valor a ser inserido: ");
				scanf("%i", &valor);
				inserirElementoFinal(&lista, valor);
				break;
				
			case 3:
				system("cls");
				printf("Você selecionou a opção: 'Remover uma nota da lista'!\n");
				printf("Digite o valor a ser removido: ");
				scanf("%i", &valor);
				remover(&lista, valor);
				break;
				
			case 4:
				system("cls");
				printf("Você selecionou a opção: 'Imprimir a lista de notas'!\n");
				imprimir(&lista);
				break;
				
			case 5:
				system("cls");
				printf("Você selecionou a opção: 'Sair'!\n");
				printf("Obrigado por fazer uso do programa!\n");
				break;
				
			default:
				printf("Opção inválida!\n");
				break;
		}
		
	} while(opcao != 5);
}
