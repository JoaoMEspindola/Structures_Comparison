#include "Maps.hpp"

void insertOnMap(string file, map<double, double>* myMap){
    double value;
    ifstream f;
    f.open(file + ".txt");
    while(f >> value){
        (*myMap)[value] = value;
    }
    f.close();
}

void searchOnMap(double value, map <double, double>* myMap){
    auto it = (*myMap).find(value);

    if (it != (*myMap).end()){
        cout << "\n" << value << " encontrado no mapa, removendo-o..." << "\n";
        (*myMap).erase(it);
    }else{
        cout << "\nElemento não encontrado no myMap." << "\n";
    }
}

void printMap(map <double, double>* myMap){
    for(auto it = (*myMap).cbegin(); it != (*myMap).cend(); ++it){
        cout << it->first << " " << "\n";
    }
}

void insertOnUnMap(string file, unordered_map <double, double>* unMap){
    double value;
    ifstream f;
    f.open(file + ".txt");
    while(f >> value){
        (*unMap)[value] = value;
    }
    f.close();
}

void searchOnUnMap(double value, unordered_map <double, double>* unMap){
    auto it = (*unMap).find(value);

    if (it != (*unMap).end()){
        cout << "\n" << value << " encontrado no mapa, removendo-o..." << "\n";
        (*unMap).erase(it);
    }else{
        cout << "\nElemento não encontrado no unMap." << "\n";
    }
}

void printUnMap(unordered_map <double, double>* unMap){
    for(auto it = (*unMap).cbegin(); it != (*unMap).cend(); ++it){
        cout << it->first << " " << "\n";
    }
}