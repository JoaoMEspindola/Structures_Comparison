#include "Maps.hpp"

void insertOnMap(double value, map<double, double>* myMap){
    (*map)[value] = value;
}

void searchOnMap(double value, map <double, double>* myMap){
    auto it = (*map).find(value);

    if (it != (*map).end()){
        (*map).erase(it);
    }else{
        cout << "Elemento não encontrado no Map." << endl;
    }
}

void printMap(map <double, double>* myMap){
    (*map)<char, int>::iterator it;
    for(it=first.begin(); it!=first.end(); ++it){
        cout << it->first << '\n';
    }
}