#include "Binary.hpp"
#include"Fila.hpp"

Tree* CreateTree(){
	return NULL;
}

bool TVazia(Tree **t){
  return *t == NULL;
}

void insertTree(Tree **t, Record r){

  if(TVazia(t)){
    *t = new Tree;
    (*t)->esq = NULL; 
    (*t)->dir = NULL; 
    (*t)->reg = r; 
  
  } else {
    
    if(r.key < (*t)->reg.key){
      insertTree(&(*t)->esq, r);
    }
    
    if(r.key > (*t)->reg.key){
      insertTree(&(*t)->dir, r);
    }
  
  }

}

void insertOnRecord(Tree **t, string file, Record r){
  ifstream f;
  f.open(file + ".txt");
  while (f >> r.key){
    insertTree(t, r);
  }
  f.close();
}

void pesquisaBinary(Tree **t, Tree **aux, Record r){

    if(*t == NULL){
        return;
    }

    if((*t)->reg.key > r.key){ pesquisaBinary(&(*t)->esq, aux, r); return;}
    if((*t)->reg.key < r.key){ pesquisaBinary(&(*t)->dir, aux, r); return;}

    // cout << "Deletando " << (*t)->reg.key << "\n";
    *aux = *t;
}


int isInTree(Tree *t, Record r) {
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInTree(t->esq, r) || isInTree(t->dir, r);
}


void antecessor(Tree **t, Tree *aux){ 

	if ((*t)->dir != NULL){ 
		antecessor(&(*t)->dir, aux);
		return;
  }
  	
  aux->reg = (*t)->reg;
  aux = *t; 
  *t = (*t)->esq;
  delete(aux);
} 


void removeTree(Tree **t, Record r){
	Tree *aux;
  	
  	if (*t == NULL){ 
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeTree(&(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeTree(&(*t)->dir, r); return; }

  	if ((*t)->dir == NULL){ 
  		aux = *t;  
  		*t = (*t)->esq;
    	delete(aux);
    	return;
  	}

  	if ((*t)->esq != NULL){ antecessor(&(*t)->esq, *t); return; }

  	aux = *t;  
  	*t = (*t)->dir;
  	delete(aux);
}

void widthPath(Tree *t){
  Fila q;
  Item no, filho;
  
  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q)){

    Desenfileira(&q, &no);
    cout << no.p->reg.key << "\n";

    if(no.p->esq != NULL){
      filho.p = no.p->esq;
      Enfileira(&q, filho);
      //printf(" Entrei esquerda! ");
    }

    if(no.p->dir != NULL){
      filho.p = no.p->dir;
      Enfileira(&q, filho);
      //printf(" Entrei direita! ");
    }

  }


}