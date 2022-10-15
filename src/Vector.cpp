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

bool searchVector(double value, vector <double>* vet){
    return binary_search((*vet).begin(), (*vet).end(), value);
}

void deleteVector(double value, vector <double>* vet){
    if (searchVector(value, vet)){
        (*vet).erase(lower_bound((*vet).begin(), (*vet).end(), value));
    }
    return;
}