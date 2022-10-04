#ifndef MAPS_HPP
#define MAPS_HPP
#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

unordered_map <double, double>* unMap = new unordered_map<double,double>;
map <double, double>* myMap = new map<double,double>;


void insertOnMap(double value, map <double, double>* myMap);
void searchOnMap(double value, map <double, double>* myMap);

void insertOnUnMap(double value, unordered_map <double, double>* unMap);
void searchOnUnMap(double value, unordered_map <double, double>* unMap);

void printMap(map <double, double>* myMap);
void printUnMap(unordered_map <double, double>* unMap);
#endif