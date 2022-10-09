#ifndef FILAAVL_H 
#define FILAAVL_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Avl.hpp"

typedef struct AVLItem AVLItem;
typedef struct AVLBlock AVLBlock;
typedef struct AVLFila AVLFila;


struct AVLItem{
	AVLTree *p;
};

struct AVLBlock{
	AVLItem data;
	AVLBlock *prox;
};

struct AVLFila{
	AVLBlock *first;
	AVLBlock *last;
};


void FFVazia(AVLFila *f);
bool isVazia(AVLFila *f);
void Enfileira(AVLFila *f, AVLItem d);
void Desenfileira(AVLFila *f, AVLItem *d);

#endif