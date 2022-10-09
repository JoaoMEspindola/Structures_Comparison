#include "FilaAVL.hpp"

void FFVazia(AVLFila *f){
	f->first = (AVLBlock*) malloc (sizeof(AVLBlock));
	f->last  = f->first;
	f->first->prox = NULL;
}

bool isVazia(AVLFila *f){
	return f->first == f->last;
}

void Enfileira(AVLFila *f, AVLItem d){
	f->last->prox = (AVLBlock*) malloc (sizeof(AVLBlock));
	f->last = f->last->prox;
	f->last->data = d;
	f->last->prox = NULL;
}

void Desenfileira(AVLFila *f, AVLItem *d){
	AVLBlock *aux;

	if(f->first == f->last){
		printf("FILA VAZIA!\n");
		return;
	}
	
	aux = f->first->prox;
	f->first->prox = aux->prox;
	
	if (f->first->prox == NULL)
		f->last = f->first;
	
	*d = aux->data;
	free(aux);
}