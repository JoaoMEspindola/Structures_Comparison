#include "Avl.hpp"
#include "FilaAVL.hpp"

AVLTree* CreateAVLTree(){
	return NULL;
}

void insertOnAVLRecord(AVLTree **t, ifstream& f, AVLRecord r){
  while (f >> r.key){
    insertAVLTree(t, r);
  }
}

void insertAVLTree(AVLTree **t, AVLRecord r){

  if(*t == NULL){
    *t = (AVLTree*)malloc(sizeof(AVLTree));
    (*t)->left   = NULL; 
    (*t)->right  = NULL; 
    (*t)->weight = 0;
    (*t)->reg    = r; 

  } else {
    
    if(r.key < (*t)->reg.key){
      insertAVLTree(&(*t)->left, r);
      if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2){
      	if(r.key < (*t)->left->reg.key)
      		rotacaoSimplesDireita(t);
      	else
      		rotacaoDuplaDireita(t);
      }
    }
    
    if(r.key > (*t)->reg.key){
      insertAVLTree(&(*t)->right, r);
      if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2){
      	if(r.key > (*t)->right->reg.key)
      		rotacaoSimplesEsquerda(t);
      	else
      		rotacaoDuplaEsquerda(t);
      }
    }
  
  }

  (*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}


void pesquisa(AVLTree **t, AVLTree **aux, AVLRecord r){

	if(*t == NULL){
		printf("[ERROR]: Node not found!");
		return;
	}

	if((*t)->reg.key > r.key){ pesquisa(&(*t)->left, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisa(&(*t)->right, aux, r); return;}

	*aux = *t;
}

int isInAVLTree(AVLTree *t, AVLRecord r){
  
  if(t == NULL){ 
    return 0;
  }
  
  return t->reg.key == r.key || isInAVLTree(t->left, r) || isInAVLTree(t->right, r);
}


void antecessor(AVLTree **t, AVLTree *aux){ 

	if ((*t)->right != NULL){ 
		antecessor(&(*t)->right, aux);
		return;
  	}
  	
  	aux->reg = (*t)->reg;
  	aux = *t; 
  	*t = (*t)->left;
  	free(aux);
} 

void rebalanceAVLTree(AVLTree **t){
	int balance;
  	int left = 0;
  	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if(balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if(balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if(balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if(balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t); 	

}

void removeAVLTree(AVLTree **t, AVLTree **f, AVLRecord r){
	AVLTree *aux;
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: AVLRecord not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeAVLTree(&(*t)->left, t, r); return;}
  	if (r.key > (*t)->reg.key){ removeAVLTree(&(*t)->right, t, r); return;}

  	if ((*t)->right == NULL){ 
  		aux = *t;  
  		*t = (*t)->left;
    	free(aux);
    	rebalanceAVLTree(f);
    	return;
  	}

  	if ((*t)->left != NULL){ 
  		antecessor(&(*t)->left, *t);
  		rebalanceAVLTree(t);
  		rebalanceAVLTree(f);
  		return;
  	}

  	aux = *t;  
  	*t = (*t)->right;
  	free(aux);
  	rebalanceAVLTree(t);
  	rebalanceAVLTree(f); 	
  	
}

int getWeight(AVLTree **t){
	if(*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right){
	if(left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(AVLTree **t){
	AVLTree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(AVLTree **t){
	AVLTree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight  = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(AVLTree **t){
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(AVLTree **t){
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}

void widthPathAVL(AVLTree *t){
  AVLFila q;
  AVLItem no, filho;
  
  FFVazia(&q);
  no.p = t;
  Enfileira(&q, no);

  while (!isVazia(&q)){

    Desenfileira(&q, &no);
    cout << no.p->reg.key << "\n";

    if(no.p->left != NULL){
      filho.p = no.p->left;
      Enfileira(&q, filho);
      //printf(" Entrei esquerda! ");
    }

    if(no.p->right != NULL){
      filho.p = no.p->right;
      Enfileira(&q, filho);
      //printf(" Entrei direita! ");
    }

  }


}