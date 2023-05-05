#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void criar(void);
void pesquisa(void);
void lista(void);
int arra[100], i, n, x, f, l, m, flag = 0, j, a;

main(){
 	int opt;
 
 	setlocale(LC_ALL,"Portuguese");
 	
 	printf("*********************************************************\n");
 	printf("*                   Menu de Opções                      *\n");
 	printf("* 1. Criar array                                        *\n");
 	printf("* 2. Pesquisar, localizar, encontrar lista              *\n");
 	printf("* 3. Ordenar uma lista por ordem crescente e decrescente*\n");
 	printf("* 0. Sair                                               *\n");
 	printf("*********************************************************\n");
 	printf("Digite o número : "); 
 	scanf("%d", &opt);
    	if(opt==1){
 			system("cls");
			printf("Voce selecionou a opcao 1 - Criar array.\n");
			printf("\nSELECIONE OS VALORES EM ORDEM CRESCENTE.\n\n");
			criar();
		}
		if(opt==2){
 			system("cls");
			printf("Voce selecionou a opcao 2 - Pesquisar, localizar, encontrar lista.\n");
			pesquisa();
		}
		if(opt==3){
 			system("cls");
			printf("Voce selecionou a opcao 3 - Ordenar uma lista por ordem crescente e decrescente.\n");
			lista();
		}
		if(opt==0){
 			
			printf("Voce selecionou a opcao 0 - Sair.\n");
			exit(0);
		}
		else{
			printf("Numero invalido.\n");
			system("pause");
			system("cls");
			main();
		}
}
void criar(void){
	
	printf("Digite o tamanho do array que deseja criar: ");
	scanf("%d", &n);


	for (i = 0; i < n; i++){
		printf("Digite o %d número: ", i+1);
		scanf("%d", &arra[i]);
		}
	printf("\nArray Criada com Sucesso!\n");
	/*Lógica binária */
	system("pause");
	system("cls");
	main();
}
void pesquisa(void){
		
	for (i = 0; i < n; ++i)
    	printf("|%d|\n",arra[i]);
	printf("\nDigite o valor que deseja pesquisar/procurar: ");
	scanf("%d", &x);
	
	f = 0;
	l = n - 1;

	while (f <= l){
		m = (f + l) / 2;
	if (x == arra[m]){
		flag = 1;
		break;
	}
	else if (x < arra[m])
		l = m - 1;
	else
		f = m + 1;
	}

	if (flag == 0)
		printf("\n%d  Valor não encontrado\n\n", x);
	else
		printf("\n%d Valor encontrado na %d posição \n\n", x, m + 1);
		
	system("pause");
	system("cls");
	main();
	
}

void lista(void){

	for (i = 0; i < n; ++i){
    for (j = i + 1; j < n; ++j){
    	if (arra[i] > arra[j]){
       		a =  arra[i];
       		arra[i] = arra[j];
       		arra[j] = a;	
            
    	}
	}
}
	printf("\n\nNúmeros em ordem crescente: \n\n");
		for (i = 0; i < n; ++i)
    		printf("%d\n", arra[i]);
    		for (i = 0; i < n; ++i){
    		for (j = i + 1; j < n; ++j){
        		if (arra[i] < arra[j]){
            		a =  arra[i];
            		arra[i] = arra[j];
            		arra[j] = a;
        	
    		}
		}
	}
	
	printf("\n\nNúmeros em ordem decrescente: \n\n");
	for (i = 0; i < n; ++i)
    	printf("%d\n", arra[i]);
	printf("\n\n");
	system("pause");
	system("cls");
	main();
}
