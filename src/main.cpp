#include <time.h>
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
    Tree* binTree = new Tree;
    AVLTree* avlTree = new AVLTree;

    char escolhaArquivo;
    ifstream file;

    cout << "Escolha o tamanho do arquivo desejado: " << "\n";
    cout << "a)500 pontos flutuantes" << "\n" << "b)5.000 pontos flutuantes" << "\n" << "c)50.000 pontos flutuantes" << "\n" << "d)500.000 pontos flutuantes" << "\n" << "e)20 pontos flutuantes" << "\n";
    cin >> escolhaArquivo;
    escolhaArquivo = toupper(escolhaArquivo);

    switch (escolhaArquivo){

        case 'A':
            file.open("500.txt");
        break;

        case 'B':
            file.open("5.000.txt");
        break;

        case 'C':
            file.open("50.000.txt");
        break;

        case 'D':
            file.open("500.000.txt");
        break;

        case 'E':
            file.open("test.txt");
        break;
    }

    char escolhaEstrutura;
   do{
        cout << "\nEscolha a estrutura de dados desejada: " << "\n";
        cout << "a)Árvore AVL" << "\n" << "b)Árvore Binária" << "\n" << "c)Árvore Red Black" << "\n" << "d)Unordored Map" << "\n" << "e)Map" << "\n" << "f)Vector" << "\n" << "g)Quit" << "\n";
        cin >> escolhaEstrutura;
        escolhaEstrutura = toupper(escolhaEstrutura);
        
        if (escolhaEstrutura == 'A'){
            AVLRecord elemento;
            AVLTree* avlTreeAux = new AVLTree;
            insertOnAVLRecord(&avlTree, file, avlTree->reg);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> elemento.key;
            removeAVLTree(&avlTree, &avlTreeAux, elemento);
            cout << "\nImprimindo elementos da árvore AVL: " << "\n";
            widthPathAVL(avlTree);
        }
        
        else if (escolhaEstrutura == 'B'){
            Record elemento;
            insertOnRecord(&binTree, file, binTree->reg);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> elemento.key;
            removeTree(&binTree, elemento);
            cout << "\nImprimindo elementos da árvore binária: " << "\n";
            widthPath(binTree);
        }
        
        else if (escolhaEstrutura == 'C'){
            //chamada arvore RB
        }
        
        else if (escolhaEstrutura == 'D'){
            double elemento;
            insertOnUnMap(file, unMap);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> elemento;
            searchOnUnMap(elemento, unMap);
            cout << "\nImprimindo elementos do unMap: " << "\n";
            printUnMap(unMap);
        }

        else if (escolhaEstrutura == 'E'){
            double elemento;
            insertOnMap(file, myMap);
            cout << "Insira o elemento que deseja pesquisar e remover:" << "\n";
            cin >> elemento;
            searchOnMap(elemento, myMap);
            cout << "\nImprimindo elementos do myMap: " << "\n";
            printMap(myMap);
        }

        else if (escolhaEstrutura == 'F'){
            double elemento;
            insertVector(file, vet);
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