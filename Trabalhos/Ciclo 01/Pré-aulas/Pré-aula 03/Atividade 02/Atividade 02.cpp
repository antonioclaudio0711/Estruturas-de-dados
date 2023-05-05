#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

typedef struct {
	char nome[40];
	int numero_conta;
	float saldo;
} conta_bancaria;

main(){
	setlocale(LC_ALL, "Portuguese");
	
	conta_bancaria *ponteiro;
	bool identificador;
	int quantidade, escolha, verificar_valor, i, z, j, k, verifica_string, conta_excluir;
	char nome_cliente[40];
	
	identificador = false;
	
	ponteiro = (conta_bancaria *) malloc(quantidade * sizeof(conta_bancaria));
	
	while(escolha != 4) {
		printf("\n");
		printf("*******************************************************\n");
		printf("1 - Cadastrar contas;\n");
		printf("2 - Visualizar todas as contas de determinado cliente;\n");
		printf("3 - Excluir uma conta;\n");
		printf("4 - Sair;\n");
		printf("*******************************************************\n");
		printf("Selecione uma das opções apresentadas no menu de opções: ");
		scanf("%i", &escolha);
		
		switch(escolha) {
			case 1:
				printf("Você selecionou a opção 'Cadastrar contas'!\n");
				printf("Quantas contas serão cadastradas? ");
				scanf("%i", &quantidade);
				
				for(i = 0; i < quantidade; i++) {
					printf("\n");
					printf("Insira o número da conta a ser cadastrada: ");
					scanf("%i", &verificar_valor);
					
					for(z = 0; z <= i; z++) {
						if(verificar_valor == ponteiro[z].numero_conta) {
							identificador = true;
						} 
					}
					
					if(identificador) {
						printf("Número de conta existente!");
						printf("\n");
						identificador = false;
					} else {
						ponteiro[i].numero_conta = verificar_valor;
						printf("Insira o nome da pessoa responsável pela conta:");
						scanf("%s", &ponteiro[i].nome);
						printf("Insira o saldo da conta: ");
						scanf("%f", &ponteiro[i].saldo);
					}
				}
				break;
				
			case 2:
				printf("\nVocê selecionou a opção 'Visualizar todas as contas de determinado cliente'!");
				printf("\nInsira o nome do cliente a ser pesquisado:");
				scanf("%s", &nome_cliente);
				
				for(j = 0; j < quantidade; j++) {
						verifica_string = (strcmp(nome_cliente, ponteiro[j].nome));
						if(verifica_string == 0) {
							printf("\n");
							printf("Nome do cliente: %s\n", ponteiro[j].nome);
							printf("Número da conta: %i\n", ponteiro[j].numero_conta);
							printf("Saldo: %.2f\n", ponteiro[j].saldo);
							printf("\n");
						}
					}
				break;
				
			case 3:
				printf("\nVocê selecionou a opção 'Excluir uma conta'!");
				printf("\nInsira o número da conta que se deseja excluir:");
				scanf("%i", &conta_excluir);
				
				for(k = 0; k < quantidade; k++) {
						if(conta_excluir == ponteiro[k].numero_conta) {
							ponteiro[k].numero_conta = 0;
							ponteiro[k].saldo = 0;
						}
					}
					printf("Conta excluída com sucesso!");
					printf("\n");
				break;
				
			case 4:
				break;
				
			default:
				printf("Selecione uma opção válida!\n");
				printf("\n");			
		}
	}
	
}
