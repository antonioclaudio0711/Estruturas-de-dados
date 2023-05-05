#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main(){
	setlocale(LC_ALL, "Portuguese");
	
    int i, tamanho;
    char *conteudo;
    
    conteudo = (char *) malloc(tamanho * sizeof(char));

    printf("Digite o número de caracteres da palavra que será inserida:");
    scanf("%i", &tamanho);


    printf("Digite o conteúdo da palavra: ");
    scanf(" %[^\n]", conteudo);
    
    i = 0;
    printf("A palavra inserida sem as vogais: ");
    while(conteudo[i] != '\0'){
        if(conteudo[i] != 'a' && conteudo[i] != 'A' && conteudo[i] != 'e' && conteudo[i] != 'E' && conteudo[i] != 'i' && conteudo[i] != 'I' && conteudo[i] != 'o' && conteudo[i] != 'O' && conteudo[i] != 'u' && conteudo[i] != 'U')
            printf("%c", conteudo[i]);
            i++;
    }
    
    free(conteudo);
}
