#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

struct nodo{
      int inf;
      struct nodo *ant;
      struct nodo *prox;
}no;

main(){
    struct nodo *inicio = NULL, *temp, *p;
    int v;

    while( 1 ){
        printf("\n Digite um valor para o nodo: ");
        scanf("%i",&v);

        if( v == 0)
            break;
        
        // novo nó a ser inserido na lista
        temp = (struct nodo*) malloc (sizeof(struct nodo));
        temp->inf = v;
        temp->prox = NULL;

        // lista vazia
        if(inicio == NULL){
           inicio = temp;
           temp->ant = temp->prox = NULL;
        }
        else{
            // percorre a lista
            p = inicio;
            while(p->prox != NULL && p->inf != v){
                p = p -> prox;
            }
            if( p->inf != v){
                p->prox   = temp;
                temp->ant = p;
            }
        }
    }
    // mostrar a lista
    p = inicio;
    while( p != NULL){
        printf("%i ",p->inf);
        p = p->prox;
    }
    printf("\n\n");
}




