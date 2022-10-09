#include "Vector.hpp"

void insertVector(string file, vector <double>* vet){
    double num;
    ifstream f;
    f.open(file + ".txt");
    while (f >> num){
        (*vet).push_back(num);
    }
    f.close();
    sort((*vet).begin(), (*vet).end());
}

void printVector(vector <double>* vet){
    for (size_t i = 0; i < (*vet).size(); ++i) {
        cout << (*vet)[i] << endl;
    }
}

void searchVector(double value, vector <double>* vet){
    if (binary_search((*vet).begin(), (*vet).end(), value) == true){
        cout << value << " existe no vector, removendo-o" << endl;
        (*vet).erase(lower_bound((*vet).begin(), (*vet).end(), value));
    }
    else{
        cout << value << " não existe" << endl;
    }
    return;
}