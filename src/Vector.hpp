#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

void insertVector(string file, vector <double>* vet);
void searchVector(double value, vector <double>* vet);
void deleteVector(double value, vector <double>* vet);
void printVector(vector <double>* vet);

#endif