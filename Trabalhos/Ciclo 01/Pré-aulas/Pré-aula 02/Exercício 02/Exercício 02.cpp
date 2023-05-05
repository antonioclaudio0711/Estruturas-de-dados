#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	
	int *v, tamanho, i, qtd_par, qtd_impar;
	qtd_par = 0;
	qtd_impar = 0;
	
	v = (int *) malloc(tamanho * sizeof(int));
	
	printf("Digite a quantidade de valores que serão inseridos no vetor: ");
	scanf("%i", &tamanho);
	for(i=0; i<tamanho; i++) {
		printf("\nDigite o valor do elemento de posição %i do vetor: ", i);
		scanf("%i", &v[i]);
		
		if(v[i] % 2 == 0) {
			qtd_par = qtd_par + 1;
		} else {
			qtd_impar = qtd_impar + 1;
		}
	}
	
	printf("\nO vetor inserido é: ");
	for(i=0; i<tamanho; i++) {
		printf("%i ", v[i]);
	}
	printf("\nForam inseridos %i números pares e %i números ímpares no vetor.", qtd_par, qtd_impar);
	
	free(v);
}
