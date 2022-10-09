#include "RedBlack.hpp"

RBTree* CreateRBTree(){
  return nullptr;
}

void insertFixUp(RBTree **raiz, RBTree *child){
  RBTree *tio;

  while((child != *raiz) && (child->pai->cor == false)){
      
      if(child->pai == child->pai->pai->esq){
        
        tio = child->pai->pai->dir;

        //caso 1:
        if((tio != nullptr) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->dir){
            child = child->pai;
            rotacaoSimplesEsquerda(raiz, child);
          }
          
          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesDireita(raiz, child->pai->pai);
        }

      }else{
        
        tio = child->pai->pai->esq;
        
        //caso 1
        if((tio != nullptr) && (tio->cor == false)){
          child->pai->cor = true;
          tio->cor = true;
          child->pai->pai->cor = false;
          child = child->pai->pai;
        
        }else{
          
          //caso 2
          if(child == child->pai->esq){
            child = child->pai;
            rotacaoSimplesDireita(raiz, child);
          }

          //caso 3
          child->pai->cor = true;
          child->pai->pai->cor = false;
          rotacaoSimplesEsquerda(raiz, child->pai->pai);      
        }

      }

  }

  (*raiz)->cor = true;
}


void insertRBTree(RBTree **t, RBTree **pai, RBTree **raiz, RBRecord r){
  
  if(*t == nullptr){
    *t = new RBTree;
    (*t)->esq = nullptr; 
    (*t)->dir = nullptr; 
    (*t)->pai = pai!=t?*pai:nullptr;
    (*t)->cor = false; //false: vermelho  true:preto
    (*t)->reg = r; 
    insertFixUp(raiz, *t);
    
  } else { 

    if(r.key < (*t)->reg.key){
      insertRBTree(&(*t)->esq, t, raiz, r);
      return;
    }
    
    if(r.key > (*t)->reg.key){
      insertRBTree(&(*t)->dir, t, raiz, r);
      return;
    }

  }

}

void insertOnRBRecord(RBTree **t, string file, RBRecord r){
  ifstream f;
  f.open(file + ".txt");
  while (f >> r.key){
    insertRBTree(t, t, t, r);
  }
  f.close();
}

void pesquisa(RBTree **t, RBTree **aux, RBRecord r){

  if(*t == nullptr){
    printf("[ERROR]: Node not found!");
    return;
  }

  if((*t)->reg.key > r.key){ pesquisa(&(*t)->esq, aux, r); return;}
  if((*t)->reg.key < r.key){ pesquisa(&(*t)->dir, aux, r); return;}

  *aux = *t;
}

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child){
  RBTree *x, *y;

  x = child;
  y = child->dir;
  x->dir = y->esq;

  if(y->esq != nullptr)
    y->esq->pai = x;

  y->pai = x->pai;
  
  if(x->pai == nullptr)
    *raiz = y;

  else{

    if(x == x->pai->esq)
      x->pai->esq = y;

    else
      x->pai->dir = y;
  
  }

  y->esq = x;
  x->pai = y;
}


void rotacaoSimplesDireita(RBTree **raiz, RBTree *child){
  RBTree *x, *y;

  x = child;
  y = child->esq;
  x->esq = y->dir;

  if(y->dir != nullptr)
    y->dir->pai = x;

  y->pai = x->pai;
  
  if(x->pai == nullptr){
    *raiz = y;
  }

  else{

    if(x == x->pai->dir)
      x->pai->dir = y;

    else
      x->pai->esq = y;
  
  }

  y->dir = x;
  x->pai = y;
  
}


void preordem(RBTree *t){
  if(!(t == nullptr)){
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    preordem(t->esq); 
    preordem(t->dir); 
  }
}


void central(RBTree *t){
  if(!(t == nullptr)){
    central(t->esq); 
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
    central(t->dir); 
  }
}

void posordem(RBTree *t){
  if(!(t == nullptr)){
    posordem(t->esq); 
    posordem(t->dir); 
    printf("%f - %s\t", t->reg.key, t->cor ? "black" : "red");
  }
}