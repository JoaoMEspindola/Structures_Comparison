#ifndef TREE_H 
#define TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct Record Record;
typedef struct Tree Tree;

struct Record{
	double key;
};

struct Tree{
	Record reg;
	Tree *esq, *dir;
};

Tree* CreateTree();
bool TVazia(Tree **t);
void insertOnRecord(Tree **t, string file, Record r);
void insertTree(Tree **t, Record r);
void pesquisa(Tree **t, Tree **aux, Record r);
int isInTree(Tree *t, Record r);

void removeTree(Tree **t, Record r);
void antecessor(Tree **t, Tree *aux);

void widthPath(Tree *t);

#endif