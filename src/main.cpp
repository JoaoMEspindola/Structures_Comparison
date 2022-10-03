#include <iostream>
#include <fstream>
#include <time.h>
#include "Avl.hpp"
#include "Binary.hpp"
#include "Map.hpp"
#include "UnordoredMap.hpp"
#include "RedBlack.hpp"
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

    for (int i = 0; i < 500; i++){
        if ((i % 500) == 0){
            file << endl;
        }
        file << rand_double_interval(1, 10) << " ";
    }


    char escolhaArquivo;

    cout << "Escolha o tamanho do arquivo desejado: " << endl;
    cout << "a)500 pontos flutuantes" << endl << "b)5.000 pontos flutuantes" << endl << "c)50.000 pontos flutuantes" << endl << "d)500.000 pontos flutuantes" << endl;
    cin >> toupper(escolhaArquivo);

    switch (escolhaArquivo){

        case 'A':
            //abrir arquivo 500
        break;

        case 'B':
            //abrir arquivo 5.000
        break;

        case 'C':
            //abrir arquivo 50.000
        break;

        case 'D':
            //abrir arquivo 500.000
        break;
    }

    char escolhaEstrutura;
    
    cout << "Escolha a estrutura de dados desejada: " << endl;
    cout << "a)Árvore AVL" << endl << "b)Árvore Binária" << endl << "c)Árvore Red Black" << endl << "d)Unordored Map" << endl << "e)Map" << endl << "f)Sair do programa" << endl;
    cin >> toupper(escolhaEstrutura);

    switch (escolhaEstrutura){
        
        case 'A':
            //chamada arvore avl
        break;
        
        case 'B':
            //chamada arvore binaria
        break;
        
        case 'C':
            //chamada arvore RB
        break;
        
        case 'D':
            //chamada unordoredMap
        break;

        case 'E':
            //chamada map
        break;

        case 'F':
            cout << "Programa encerrado." << endl;
            break;
    }
    
    
    
    
    
    
    return 0;
}