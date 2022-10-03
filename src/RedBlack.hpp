#ifndef RB_H 
#define RB_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct RBRecord RBRecord;
typedef struct RBTree RBTree;

struct RBRecord{
	int key;
};

struct RBTree{
	RBRecord reg;
	RBTree *esq, *dir;
	RBTree *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHOR, TRUE = PRETO)
};


RBTree* CreateRBTree();

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child);
void rotacaoSimplesDireita(RBTree **raiz, RBTree *child);

void insertFixUp(RBTree **raiz, RBTree *child);
void insertRBTree(RBTree **t, RBTree **pai, RBTree **raiz, RBRecord r);
void pesquisa(RBTree **t, RBTree **aux, RBRecord r);

void preordem(RBTree *t);
void central(RBTree *t);
void posordem(RBTree *t);


#endif