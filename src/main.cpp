#include <time.h>
#include <string>
#include "Avl.hpp"
#include "Binary.hpp"
#include "Maps.hpp"
#include "RedBlack.hpp"
#include "Vector.hpp"
using namespace std;

// double rand_double(){
//     return ((double)rand()) / ((double)RAND_MAX);
// }

// double rand_double_interval(double a, double b){
//     return rand_double() * (b - a) + a;
// }

int main(){
    //declaração de globais
    unordered_map <double, double>* unMap = new unordered_map<double,double>;
    map <double, double>* myMap = new map<double,double>;
    vector <double>* vet = new vector<double>;
    Tree* binTree = CreateTree();
    AVLTree* avlTree = CreateAVLTree();
    RBTree* rbTree = CreateRBTree();

    string escolhaArquivo;
    ifstream file;

    cout << "Escolha o tamanho do arquivo desejado: Ex: (500)" << "\n";
    cout << "500 pontos flutuantes" << "\n" << "5.000 pontos flutuantes" << "\n" << "50.000 pontos flutuantes" << "\n" << "500.000 pontos flutuantes" << "\n" << "20 pontos flutuantes" << "\n";
    cin >> escolhaArquivo;

    char escolhaEstrutura;
   do{
        cout << "\nEscolha a estrutura de dados desejada: " << "\n";
        cout << "a)Árvore AVL" << "\n" << "b)Árvore Binária" << "\n" << "c)Árvore Red Black" << "\n" << "d)Unordored Map" << "\n" << "e)Map" << "\n" << "f)Vector" << "\n" << "g)Quit" << "\n";
        cin >> escolhaEstrutura;
        escolhaEstrutura = toupper(escolhaEstrutura);
        
        if (escolhaEstrutura == 'A'){
            AVLRecord avlElemento;
            AVLTree* avlTreeAux = CreateAVLTree();
            insertOnAVLRecord(&avlTree, escolhaArquivo, avlElemento);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> avlElemento.key;
            pesquisaAVL(&avlTree, &avlTreeAux, avlElemento);
            removeAVLTree(&avlTree, &avlTree, avlElemento);
            cout << "\nImprimindo elementos da árvore AVL: " << "\n";
            widthPathAVL(avlTree);
        }
        
        else if (escolhaEstrutura == 'B'){
            Record binElemento;
            Tree* binTreeAux = CreateTree();
            insertOnRecord(&binTree, escolhaArquivo, binElemento);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> binElemento.key;
            pesquisaBinary(&binTree, &binTreeAux, binElemento);
            removeTree(&binTree, binElemento);
            cout << "\nImprimindo elementos da árvore binária: " << "\n";
            widthPath(binTree);
        }
        
        else if (escolhaEstrutura == 'C'){
            RBRecord rbElemento;
            insertOnRBRecord(&rbTree, escolhaArquivo, rbElemento);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> rbElemento.key;
            pesquisaRB(&rbTree, &rbTree, rbElemento);
            removeRBTree(&rbTree, &rbTree, rbElemento);
            cout << "\nImprimindo elementos da árvore RB: " << "\n";
            central(rbTree);
        }
        
        else if (escolhaEstrutura == 'D'){
            double unmapElemento;
            insertOnUnMap(escolhaArquivo, unMap);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> unmapElemento;
            searchOnUnMap(unmapElemento, unMap);
            cout << "\nImprimindo elementos do unMap: " << "\n";
            printUnMap(unMap);
        }

        else if (escolhaEstrutura == 'E'){
            double mapElemento;
            insertOnMap(escolhaArquivo, myMap);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> mapElemento;
            searchOnMap(mapElemento, myMap);
            cout << "\nImprimindo elementos do myMap: " << "\n";
            printMap(myMap);
        }

        else if (escolhaEstrutura == 'F'){
            double elemento;
            insertVector(escolhaArquivo, vet);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> elemento;
            searchVector(elemento, vet);
            cout << "\nImprimindo elementos do vetor: " << "\n";
            printVector(vet);
        }
        
        else{
            cout << "Programa encerrado." << "\n";
            file.close();
        }

    }while(escolhaEstrutura != 'G');
    
    return 0;
}