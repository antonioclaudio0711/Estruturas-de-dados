#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

main() {
	setlocale(LC_ALL, "Portuguese");
	
	int quantidade_alunos, i;
	float *notas, soma, media;
	soma = 0;
	
	notas = (float *) malloc(quantidade_alunos * sizeof(float));
	
	printf("Insira a quantidade de alunos presentes na turma:");
	scanf("%i", &quantidade_alunos);
	for(i=0; i<quantidade_alunos; i++) {
		printf("\nDigite a nota do aluno %i:", i + 1);
		scanf("%f", &notas[i]);
		
		soma = soma + notas[i];
	}
	
	media = soma / quantidade_alunos;
	printf("\nA média aritmética das notas inseridas é: %.2f", media);
	
	free(notas);
}
