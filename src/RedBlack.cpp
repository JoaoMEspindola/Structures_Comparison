#include "RedBlack.hpp"

RBTree* CreateRBTree(){
	return nullptr;
}

void CreateNil(RBTree* node){
	node->cor = true;
    node->reg.key = -1;
    node->dir = NULL;
    node->esq = NULL;
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

void insertOnRBRecord(RBTree **t, string file, RBRecord r){
  ifstream f;
  f.open(file + ".txt");
  while (f >> r.key){
    insertRBTree(t, t, t, r);
  }
  f.close();
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


void pesquisaRB(RBTree **t, RBTree **aux, RBRecord r){

	if(*t == nullptr){
		printf("[ERROR]: Node not found!");
		return;
	}

	if((*t)->reg.key > r.key){ pesquisaRB(&(*t)->esq, aux, r); return;}
	if((*t)->reg.key < r.key){ pesquisaRB(&(*t)->dir, aux, r); return;}

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

void transplant(RBTree **raiz, RBTree *u, RBTree *v){
	if (u->pai == nullptr){
		(*raiz) = v;
	}
	else if (u == u->pai->esq){
		u->pai->esq = v;
	}else{
		u->pai->dir = v;
	}

	v->pai = u->pai;
}

void deleteRBNode(RBTree **t, RBTree *node){
	RBTree *sucessorSon;
    RBTree *nodeSucessor;

	nodeSucessor = node;
	bool nodeSucessor_original_color = nodeSucessor->cor;

	if(node->esq == nullptr){
		sucessorSon = node->dir;
        if (sucessorSon == nullptr){
            sucessorSon = new RBTree;
            CreateNil(sucessorSon);
            sucessorSon->pai = nodeSucessor;
            nodeSucessor->esq = sucessorSon;
            node->dir = sucessorSon;
        }
		transplant(t, node, node->dir);
	}

	else if(node->dir == nullptr){
		sucessorSon = node->esq;
		transplant(t, node, node->esq);
	}

	else{
		nodeSucessor = treeMinimum(&node->esq);
		nodeSucessor_original_color = nodeSucessor->cor;
        sucessorSon = nodeSucessor->esq;
        if (sucessorSon == nullptr){
            sucessorSon = new RBTree;
            CreateNil(sucessorSon);
            sucessorSon->pai = nodeSucessor;
            nodeSucessor->esq = sucessorSon;
        }

		if(nodeSucessor->pai == node){
			sucessorSon->pai = nodeSucessor;
		}else{
			transplant(t, nodeSucessor, nodeSucessor->esq);
			nodeSucessor->esq = node->esq;
			nodeSucessor->esq->pai = nodeSucessor;
		}

		transplant(t, node, nodeSucessor);
		nodeSucessor->dir = node->dir;
		nodeSucessor->dir->pai = nodeSucessor;
		nodeSucessor->cor = node->cor;
	}

	if (nodeSucessor_original_color == true){
		deleteFixUp(t, sucessorSon);
	}

    RBTree* aux = sucessorSon;

    if (aux->reg.key == -1){
        if (aux == aux->pai->esq)
            aux->pai->esq = nullptr;
        else
            aux->pai->dir = nullptr;
        delete aux;
    }
    delete node;
}

RBTree* treeMinimum(RBTree **t){
	if((*t)->dir != nullptr){
		return treeMinimum(&(*t)->dir);
	}
	return (*t);
}

void deleteFixUp(RBTree **t, RBTree *x){
	while (x != (*t) && x->cor == true){
		if (x == x->pai->esq){
			RBTree *w = x->pai->dir;

			if(w->cor == false){
				w->cor = true;
				x->pai->cor = false;
				rotacaoSimplesEsquerda(t, x->pai);
				w = x->pai->dir;
			}

			if ((w->esq == nullptr || w->esq->cor == true) && (w->dir == nullptr || w->dir->cor == true)){
				w->cor = false;
				x = x->pai;
			}

			else if (w->dir->cor == true){
				w->esq->cor = true;
				w->cor = false;
				rotacaoSimplesDireita(t, w);
				w = x->pai->dir;
			}

            if (w->esq != nullptr && w->esq->cor == false){
                w->cor = x->pai->cor;
                x->pai->cor = true;
                w->dir->cor = true;
                rotacaoSimplesEsquerda(t, x->pai);
                x = (*t);
            }
		}else{
			RBTree *w = x->pai->esq;

			if(w->cor == false){
				w->cor = true;
				x->pai->cor = false;
				rotacaoSimplesEsquerda(t, x->pai);
				w = x->pai->dir;
			}

			if ((w->esq == nullptr || w->esq->cor == true) && (w->dir == nullptr || w->dir->cor == true)){
				w->cor = false;
				x = x->pai;
			}

			else if (w->dir->cor == true){
				w->dir->cor = true;
				w->cor = false;
				rotacaoSimplesDireita(t, w);
				w = x->pai->esq;
			}

            if (w->esq != nullptr && w->esq->cor == false){
                w->cor = x->pai->cor;
                x->pai->cor = true;
                w->esq->cor = true;
                rotacaoSimplesEsquerda(t, x->pai);
                x = (*t);
            }
		}
	}
	x->cor = true;
}

void removeRBTree(RBTree** root, RBTree **t, RBRecord r){
  	
  	if (*t == NULL){ 
  		printf("[ERROR]: RBRecord not found!!!\n");
    	return;
  	}

  	if (r.key < (*t)->reg.key){ removeRBTree(root, &(*t)->esq, r); return; }
  	if (r.key > (*t)->reg.key){ removeRBTree(root, &(*t)->dir, r); return; }

  	if ((*root)->dir == nullptr && (*root)->esq == nullptr){
		delete (*root);
		(*root) = nullptr;
		return;
	}

	deleteRBNode(root, (*t));
}