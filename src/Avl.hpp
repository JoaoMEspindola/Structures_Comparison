#ifndef AVL_H 
#define AVL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct AVLRecord AVLRecord;
typedef struct AVLTree AVLTree;

struct AVLRecord{
	int key;
	int value;
};

struct AVLTree{
	AVLRecord reg;
	AVLTree *left, *right;
	int weight;
};

AVLTree* CreateAVLTree();
void insertAVLTree(AVLTree **t, AVLRecord r);
void pesquisa(AVLTree **t, AVLTree **aux, AVLRecord r);
int isInAVLTree(AVLTree *t, AVLRecord r);

//muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeAVLTree(AVLTree **t, AVLTree **f, AVLRecord r);
void antecessor(AVLTree **t, AVLTree *aux);
void rebalanceAVLTree(AVLTree **t);

void preordem(AVLTree *t);
void central(AVLTree *t);
void posordem(AVLTree *t);


int getWeight(AVLTree **t);
int getMaxWeight(int left, int right);


void rotacaoSimplesDireita(AVLTree **t);
void rotacaoSimplesEsquerda(AVLTree **t);
void rotacaoDuplaDireita(AVLTree **t);
void rotacaoDuplaEsquerda(AVLTree **t);


#endif