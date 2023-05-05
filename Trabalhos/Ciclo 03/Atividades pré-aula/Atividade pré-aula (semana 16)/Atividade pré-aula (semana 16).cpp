#include <stdio.h>
#include<locale.h>
#include<stdlib.h>

#define MAX 10

//Implementa��o da estrutura da pilha
struct Pilha {
	int topo;
	int capacidade;
	float *pElemento;
};

//Implementa��o da fun��o destinada � cria��o da pilha
void criarPilha(struct Pilha *p, int c) {
	p -> topo = -1;
	p -> capacidade = c;
	p -> pElemento = (float*) malloc (c * sizeof(float));
}

//Implementa��o da fun��o destinada � verifica��o se a pilha est� vazia
int estaVazia(struct Pilha *p) {
	if (p -> topo == -1) {
		return 1;
	} else {
		return 0;
	}
}

//Implementa��o da fun��o destinada � verifica��o se a pilha est� cheia
int estaCheia(struct Pilha *p) {
	if (p -> topo == p -> capacidade - 1) {
		return 1;
	} else {
		return 0;
	}
}

//Implementa��o da fun��o destinada � inser��o de um elemento no topo da pilha
void empilhar(struct Pilha *p, float v) {
	p -> topo++;
	p -> pElemento [p -> topo] = v;
}

//Implementa��o da fun��o destinada � remo��o de um elemento do topo da pilha
float desempilhar(struct Pilha *p) {
	float aux = p -> pElemento [p -> topo];
	p -> topo--;
	return aux;
}

//Implementa��o da fun��o destinada � determina��o do elemento do topo da pilha
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
		printf("		MENU DE OP��ES		\n");
		printf("1 - Empilhar(PUSH)\n");
		printf("2 - Desempilhar(POP)\n");
		printf("3 - Mostrar o topo\n");
		printf("4 - Sair\n");
		printf("Selecione uma das op��es do menu acima: ");
		scanf("%i", &escolha);
		
		switch(escolha) {
			case 1:
				printf("Voc� selecionou a op��o 'Empilhar(PUSH)'!\n");
				if(estaCheia(&minhaPilha) == 1) {
					printf("Infelizmente a pilha est� cheia!\n");
				} else {
					printf("Qual o valor que se deseja inserir? ");
					scanf("%f", &valor);
					empilhar(&minhaPilha, valor);
					printf("O valor %.2f foi empilhado com sucesso!\n", valor);
				}
				break;
				
			case 2:
				printf("Voc� selecionou a op��o 'Desempilhar(POP)'!\n");
				if(estaVazia(&minhaPilha) == 1) {
					printf("Infelizmente a pilha est� vazia!\n");
				} else {
					valor = desempilhar(&minhaPilha);
					printf("O valor %.2f foi desempilhado!\n", valor);
				}
				break;
				
			case 3:
				printf("Voc� selecionou a op��o 'Mostrar o topo'!\n");
				if(estaVazia(&minhaPilha) == 1) {
					printf("Infelizmente a pilha est� vazia!\n");
				} else {
					valor = retornaTopo(&minhaPilha);
					printf("O valor do topo da pilha � %.2f", valor);
				}
				break;
				
			case 4:
				printf("Obrigado por utilizar o programa!\n");
				break;
				
			default:
				printf("Selecione uma op��o v�lida!");
		}
	} while(escolha != 4);
}
