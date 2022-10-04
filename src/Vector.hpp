#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

vector <double>* vet = new vector<double>;


void insertVector(ifstream& f, vector <double>* vet);
void searchVector(double value, vector <double>* vet);
void deleteVector(double value, vector <double>* vet);
void printVector(vector <double>* vet);

#endif