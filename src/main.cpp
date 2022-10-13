#include <time.h>
#include <string>
#include "Avl.hpp"
#include "Binary.hpp"
#include "Maps.hpp"
#include "RedBlack.hpp"
#include "Vector.hpp"
#include <chrono>
using namespace std;
using namespace std::chrono;

// double rand_double(){
//     return ((double)rand()) / ((double)RAND_MAX);
// }

// double rand_double_interval(double a, double b){
//     return rand_double() * (b - a) + a;
// }

int main(){
    // srand(time(NULL));

    // ofstream f("consulta.txt");

    // for (int i = 0; i < 3000; i++){
    //     if ((i % 500) == 0 && i != 0){
    //         f << "\n";
    //     }
    //     f << rand_double_interval(1, 10) << " ";
    // }

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
            file.open("consulta.txt");

            auto startInsert = steady_clock::now();
            insertOnAVLRecord(&avlTree, escolhaArquivo, avlElemento);
            auto endInsert = steady_clock::now();
            auto elapsedInsert = endInsert - startInsert;

            cout << "A inserção na AVL demorou " << duration <double> {elapsedInsert}.count() << "segundos\n";

            auto startSearch = steady_clock::now();
            while(file >> avlElemento.key){
                pesquisaAVL(&avlTree, &avlTreeAux, avlElemento);
            }
            auto endSearch = steady_clock::now();
            auto elapsedSearch = endSearch - startSearch;

            cout << "A pesquisa na AVL demorou " << duration <double> {elapsedSearch}.count() << "segundos\n";
            file.close();

            file.open("consulta.txt");
            
            auto startDeletion = steady_clock::now();
            while(file >> avlElemento.key){
                removeAVLTree(&avlTree, &avlTree, avlElemento);
            }
            auto endDeletion = steady_clock::now();
            auto elapsedDeletion = endDeletion - startDeletion;

            cout << "A remoção na AVL demorou " << duration <double> {elapsedDeletion}.count() << "segundos\n";
            file.close();
        }
        
        else if (escolhaEstrutura == 'B'){
            Record binElemento;
            Tree* binTreeAux = CreateTree();
            file.open("consulta.txt");

            auto startInsert = steady_clock::now();
            insertOnRecord(&binTree, escolhaArquivo, binElemento);
            auto endInsert = steady_clock::now();
            auto elapsedInsert = endInsert - startInsert;

            cout << "A inserção na Binária demorou " << duration <double> {elapsedInsert}.count() << "segundos\n";
            
            auto startSearch = steady_clock::now();
            while(file >> binElemento.key){
                pesquisaBinary(&binTree, &binTreeAux, binElemento);
            }
            auto endSearch = steady_clock::now();
            auto elapsedSearch = endSearch - startSearch;
            cout << "A pesquisa na Binária demorou " << duration <double> {elapsedSearch}.count() << "segundos\n";
            file.close();

            file.open("consulta.txt");
            auto startDeletion = steady_clock::now();
            while(file >> binElemento.key){
                removeTree(&binTree, binElemento);
            }
            auto endDeletion = steady_clock::now();
            auto elapsedDeletion = endDeletion - startDeletion;
            cout << "A remoção na Binária demorou " << duration <double> {elapsedDeletion}.count() << "segundos\n";

            file.close();
        }
        
        else if (escolhaEstrutura == 'C'){
            RBRecord rbElemento;
            RBTree* rbTreeAux = CreateRBTree();
            file.open("consulta.txt");

            auto startInsert = steady_clock::now();
            insertOnRBRecord(&rbTree, escolhaArquivo, rbElemento);
            auto endInsert = steady_clock::now();
            auto elapsedInsert = endInsert - startInsert;
            cout << "A inserção na Red Black demorou " << duration <double> {elapsedInsert}.count() << "segundos\n";

            auto startSearch = steady_clock::now();
            while(file >> rbElemento.key){
                pesquisaRB(&rbTree, &rbTreeAux, rbElemento);
            }
            auto endSearch = steady_clock::now();
            auto elapsedSearch = endSearch - startSearch;
            cout << "A pesquisa na Red Black demorou " << duration <double> {elapsedSearch}.count() << "segundos\n";
            file.close();

            file.open("consulta.txt");

            auto startDeletion = steady_clock::now();
            while(file >> rbElemento.key){
                removeRBTree(&rbTree, &rbTreeAux, rbElemento);
            }
            auto endDeletion = steady_clock::now();
            auto elapsedDeletion = endDeletion - startDeletion;
            cout << "A remoção na Red Black demorou " << duration <double> {elapsedDeletion}.count() << "segundos\n";
            file.close();
        }
        
        else if (escolhaEstrutura == 'D'){
            double unmapElemento;
            file.open("consulta.txt");

            auto startInsert = steady_clock::now();
            insertOnUnMap(escolhaArquivo, unMap);
            auto endInsert = steady_clock::now();
            auto elapsedInsert = endInsert - startInsert;
            cout << "A inserção no Unordered Map demorou " << duration <double> {elapsedInsert}.count() << "segundos\n";

            auto startSearch = steady_clock::now();
            while(file >> unmapElemento){
                searchOnUnMap(unmapElemento, unMap);
            }
            auto endSearch = steady_clock::now();
            auto elapsedSearch = endSearch - startSearch;
            cout << "A pesquisa no Unordered Map demorou " << duration <double> {elapsedSearch}.count() << "segundos\n";
            file.close();

            file.open("consulta.txt");

            auto startDeletion = steady_clock::now();
            while (file >> unmapElemento){
                deleteOnUnMap(unmapElemento, unMap);
            }
            auto endDeletion = steady_clock::now();
            auto elapsedDeletion = endDeletion - startDeletion;
            cout << "A remoção no Unordered Map demorou " << duration <double> {elapsedDeletion}.count() << "segundos\n";

            file.close();
        }

        else if (escolhaEstrutura == 'E'){
            double mapElemento;
            file.open("consulta.txt");

            auto startInsert = steady_clock::now();
            insertOnMap(escolhaArquivo, myMap);
            auto endInsert = steady_clock::now();
            auto elapsedInsert = endInsert - startInsert;
            cout << "A inserção no Map demorou " << duration <double> {elapsedInsert}.count() << "segundos\n";
            
            auto startSearch = steady_clock::now();
            while(file >> mapElemento){
                searchOnMap(mapElemento, myMap);
            }
            auto endSearch = steady_clock::now();
            auto elapsedSearch = endSearch - startSearch;
            cout << "A pesquisa no Map demorou " << duration <double> {elapsedSearch}.count() << "segundos\n";
            file.close();

            file.open("consulta.txt");

            auto startDeletion = steady_clock::now();
            while(file >> mapElemento){
                deleteOnMap(mapElemento, myMap);
            }
            auto endDeletion = steady_clock::now();
            auto elapsedDeletion = endDeletion - startDeletion;
            cout << "A remoção no Map demorou " << duration <double> {elapsedDeletion}.count() << "segundos\n";

            file.close();
        }

        else if (escolhaEstrutura == 'F'){
            double elemento;
            file.open("consulta.txt");

            auto startInsert = steady_clock::now();
            insertVector(escolhaArquivo, vet);
            auto endInsert = steady_clock::now();
            auto elapsedInsert = endInsert - startInsert;
            cout << "A inserção no vetor demorou " << duration <double> {elapsedInsert}.count() << "segundos\n";

            auto startSearch = steady_clock::now();
            while (file >> elemento){
                searchVector(elemento, vet);
            }
            auto endSearch = steady_clock::now();
            auto elapsedSearch = endSearch - startSearch;
            cout << "A pesquisa no vetor demorou " << duration <double> {elapsedSearch}.count() << "segundos\n";
            file.close();

            file.open("consulta.txt");

            auto startDeletion = steady_clock::now();
            while (file >> elemento){
                deleteVector(elemento, vet);
            }
            auto endDeletion = steady_clock::now();
            auto elapsedDeletion = endDeletion - startDeletion;
            cout << "A remoção no vetor demorou " << duration <double> {elapsedDeletion}.count() << "segundos\n";

            file.close();
        }
        
        else{
            cout << "Programa encerrado." << "\n";
            file.close();
        }

    }while(escolhaEstrutura != 'G');
    
    return 0;
}