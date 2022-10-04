#include <fstream>
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

    // srand(time(NULL));

    // ofstream file("500.txt");

    // for (int i = 0; i < 500; i++){
    //     if ((i % 500) == 0){
    //         file << endl;
    //     }
    //     file << rand_double_interval(1, 10) << " ";
    // }


    char escolhaArquivo;
    ifstream file;

    cout << "Escolha o tamanho do arquivo desejado: " << endl;
    cout << "a)500 pontos flutuantes" << endl << "b)5.000 pontos flutuantes" << endl << "c)50.000 pontos flutuantes" << endl << "d)500.000 pontos flutuantes" << endl << "e)20 pontos flutuantes" << endl;
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
        cout << "Escolha a estrutura de dados desejada: " << endl;
        cout << "a)Árvore AVL" << endl << "b)Árvore Binária" << endl << "c)Árvore Red Black" << endl << "d)Unordored Map" << endl << "e)Map" << endl << "f)Vector" << endl << "g)Quit" << endl;
        cin >> escolhaEstrutura;
        escolhaEstrutura = toupper(escolhaEstrutura);
        
        if (escolhaEstrutura == 'A'){
            //chamada arvore avl
        }
        
        else if (escolhaEstrutura == 'B'){
            //chamada arvore binaria
        }
        
        else if (escolhaEstrutura == 'C'){
            //chamada arvore RB
        }
        
        else if (escolhaEstrutura == 'D'){
            //chamada unordored map
        }

        else if (escolhaEstrutura == 'E'){
            insertOnMap(myMap);
            
        }

        else if (escolhaEstrutura == 'F'){
            double elemento;
            insertVector(file, vet);
            cout << "Insira o elemento que deseja pesquisar e remover:" << endl;
            cin >> elemento;
            searchVector(elemento, vet);
            cout << "\nImprimindo elementos do vetor: " << endl;
            printVector(vet);
        }
        
        else{
            cout << "Programa encerrado." << endl;
            file.close();
        }

    }while(escolhaEstrutura != 'G');
    
    return 0;
}