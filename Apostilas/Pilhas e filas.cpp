#include<iostream>
#include<locale.h>

using namespace std;

typedef struct Pilha {
	int topo;
	int capacidade;
	float *ponteiro_elemento;
};

typedef struct Fila {
	int capacidade;
	float *dados;
	int primeiro;
	int ultimo;
	int nItens;
};

void criarPilha(struct Pilha *p, int c) {
	p -> topo = -1;
	p -> capacidade = c;
	p -> ponteiro_elemento = (float *) malloc(c * sizeof(float));
}

void criarFila (struct Fila *f, int c) {
	f -> capacidade = c;
	f -> dados = (float *) malloc (f -> capacidade * sizeof(float));
	f -> primeiro = 0;
	f -> ultimo = -1;
}


