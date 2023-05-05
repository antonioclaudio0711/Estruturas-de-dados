#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>

typedef struct cliente CLIENTE;
struct cliente {
	int cod_cliente;
	char nome[40];
	char sobrenome[40];
	char endereco[60];
};

typedef struct data DATA;
struct data {
	int dia;
	int mes;
	int ano;
};

typedef struct recebimentos RECEBIMENTOS;
struct recebimentos {
	int num_conta;
	float valor_documento;
	DATA data_emissao;
	DATA data_vencimento;
	int cod_cliente;
};

void inputCliente();
void inputRecebimento();

main() {
	setlocale(LC_ALL,"Portuguese");
	
	CLIENTE cadastro_cliente;
	int escolha;
	
	do {
		printf("\n");
		printf("\n****************************************\n");
		printf("	    MENU DE OPÇÕES			 \n");
		printf("1 - Cadastrar cliente\n");
		printf("2 - Cadastrar recebimento\n");
		printf("3 - Sair\n");
		printf("****************************************\n");
		printf("Selecione uma das opções apresentadas no menu: ");
		scanf("%i",&escolha);
		printf("\n");
		
		switch(escolha) {
			case 1:
				printf("Você escolheu a opção de 'Cadastrar cliente'!\n");
				inputCliente();
				
				break;
				
			case 2:
				printf("Você selecionou a opção de 'Cadastrar recebimento'!\n");
				inputRecebimento();
				break;
				
			case 3:
				printf("Obrigado por fazer uso do sistema!");
				getch();
				break;
				
			default:
				printf("Selecione uma opção válida!\n");
				printf("\n");
				getch();
				break;
		}
	} while(escolha != 3);
	
	
}

//**************************************************************
void inputCliente() {
	FILE* arquivo;
	CLIENTE cli;
	
	arquivo = fopen("arquivo.txt", "ab");
	if(arquivo == NULL) {
		printf("Problemas na abertura do arquivo!");
	} else {
		do {
			printf("Insira o código do cliente:");
			scanf("%i", &cli.cod_cliente);
			
			fflush(stdin);
			printf("Insira o nome do cliente:");
			gets(cli.nome);
			
			fflush(stdin);
			printf("Insira o sobrenome do cliente:");
			gets(cli.sobrenome);
			
			fflush(stdin);
			printf("Insira o endereço do cliente:");
			gets(cli.endereco);
			
			fwrite(&cli, sizeof(CLIENTE), 1, arquivo);
			
			printf("Deseja inserir outro clientes(s/n)? ");
			
		} while(getche() == 's');
		fclose(arquivo);
	}
}

//**************************************************************
void inputRecebimento() {
	FILE* arquivo;
	RECEBIMENTOS rec;
	
	arquivo = fopen("arquivo.txt", "ab");
	if(arquivo == NULL) {
		printf("Problemas na abertura do arquivo!");
	} else {
		do {
			printf("Insira o código do cliente:");
			scanf("%i", &rec.cod_cliente);
			
			printf("Insira o número da conta:");
			scanf("%i", &rec.num_conta);
			
			printf("Insira o valor do documento:");
			scanf("%f", &rec.valor_documento);
			
			printf("Insira a data de emissão:");
			scanf("%i %i %i", &rec.data_emissao.dia, &rec.data_emissao.mes, &rec.data_emissao.ano);
			
			printf("Insira a data de validade:");
			scanf("%i %i %i", &rec.data_vencimento.dia, &rec.data_vencimento.mes, &rec.data_vencimento.ano);
			
			fwrite(&rec, sizeof(RECEBIMENTOS), 1, arquivo);
			
			printf("Deseja inserir outro recebimento(s/n)? ");
			
		} while(getche() == 's');
		fclose(arquivo);
	}
}


