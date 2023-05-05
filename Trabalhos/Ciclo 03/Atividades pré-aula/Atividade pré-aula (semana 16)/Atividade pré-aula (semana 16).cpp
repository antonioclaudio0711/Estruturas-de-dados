#include <stdio.h>
#include<locale.h>
#include<stdlib.h>

#define MAX 10

//Implementação da estrutura da pilha
struct Pilha {
	int topo;
	int capacidade;
	float *pElemento;
};

//Implementação da função destinada à criação da pilha
void criarPilha(struct Pilha *p, int c) {
	p -> topo = -1;
	p -> capacidade = c;
	p -> pElemento = (float*) malloc (c * sizeof(float));
}

//Implementação da função destinada à verificação se a pilha está vazia
int estaVazia(struct Pilha *p) {
	if (p -> topo == -1) {
		return 1;
	} else {
		return 0;
	}
}

//Implementação da função destinada à verificação se a pilha está cheia
int estaCheia(struct Pilha *p) {
	if (p -> topo == p -> capacidade - 1) {
		return 1;
	} else {
		return 0;
	}
}

//Implementação da função destinada à inserção de um elemento no topo da pilha
void empilhar(struct Pilha *p, float v) {
	p -> topo++;
	p -> pElemento [p -> topo] = v;
}

//Implementação da função destinada à remoção de um elemento do topo da pilha
float desempilhar(struct Pilha *p) {
	float aux = p -> pElemento [p -> topo];
	p -> topo--;
	return aux;
}

//Implementação da função destinada à determinação do elemento do topo da pilha
float retornaTopo(struct Pilha *p) {
	return p -> pElemento[p -> topo];
}


main() {
	setlocale(LC_ALL, "Portuguese");
	
	struct Pilha minhaPilha;
	int capacidade, escolha;
	float valor;
	
	printf("Insira a capacidade da pilha: ");
	scanf("%i", &capacidade);
	
	criarPilha(&minhaPilha, capacidade);
	
	do {
		printf("\n");
		printf("		MENU DE OPÇÕES		\n");
		printf("1 - Empilhar(PUSH)\n");
		printf("2 - Desempilhar(POP)\n");
		printf("3 - Mostrar o topo\n");
		printf("4 - Sair\n");
		printf("Selecione uma das opções do menu acima: ");
		scanf("%i", &escolha);
		
		switch(escolha) {
			case 1:
				printf("Você selecionou a opção 'Empilhar(PUSH)'!\n");
				if(estaCheia(&minhaPilha) == 1) {
					printf("Infelizmente a pilha está cheia!\n");
				} else {
					printf("Qual o valor que se deseja inserir? ");
					scanf("%f", &valor);
					empilhar(&minhaPilha, valor);
					printf("O valor %.2f foi empilhado com sucesso!\n", valor);
				}
				break;
				
			case 2:
				printf("Você selecionou a opção 'Desempilhar(POP)'!\n");
				if(estaVazia(&minhaPilha) == 1) {
					printf("Infelizmente a pilha está vazia!\n");
				} else {
					valor = desempilhar(&minhaPilha);
					printf("O valor %.2f foi desempilhado!\n", valor);
				}
				break;
				
			case 3:
				printf("Você selecionou a opção 'Mostrar o topo'!\n");
				if(estaVazia(&minhaPilha) == 1) {
					printf("Infelizmente a pilha está vazia!\n");
				} else {
					valor = retornaTopo(&minhaPilha);
					printf("O valor do topo da pilha é %.2f", valor);
				}
				break;
				
			case 4:
				printf("Obrigado por utilizar o programa!\n");
				break;
				
			default:
				printf("Selecione uma opção válida!");
		}
	} while(escolha != 4);
}
