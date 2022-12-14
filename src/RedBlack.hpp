#ifndef REDBLACK_HPP 
#define REDBLACK_HPP

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

typedef struct RBRecord RBRecord;
typedef struct RBTree RBTree;

struct RBRecord{
	double key;
};

struct RBTree{
	RBRecord reg;
	RBTree *esq, *dir;
	RBTree *pai; //específico para rubro negra
	bool cor;  //específico para rubro negra (FALSE = VERMELHO, TRUE = PRETO)
};


RBTree* CreateRBTree();
void CreateNil(RBTree *node);

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child);
void rotacaoSimplesDireita(RBTree **raiz, RBTree *child);

void insertFixUp(RBTree **raiz, RBTree *child);
void insertRBTree(RBTree **t, RBTree **pai, RBTree **raiz, RBRecord r);
void insertOnRBRecord(RBTree **t, string file, RBRecord r);
void pesquisaRB(RBTree **t, RBTree **aux, RBRecord r);

void preordem(RBTree *t);
void central(RBTree *t);
void posordem(RBTree *t);

void removeRBTree(RBTree** root, RBTree **t, RBRecord r);
void transplant(RBTree **t, RBTree *u, RBTree *v);
void deleteRBNode(RBTree **t, RBTree *node);
RBTree* treeMinimum(RBTree **t);
void deleteFixUp(RBTree **t, RBTree *x);
#endif
