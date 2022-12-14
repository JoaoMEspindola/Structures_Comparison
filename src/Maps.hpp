#ifndef MAPS_HPP
#define MAPS_HPP
#include <iostream>
#include <unordered_map>
#include <map>
#include <iterator>
#include <fstream>
using namespace std;

void insertOnMap(string file, map <double, double>* myMap);
void searchOnMap(double value, map <double, double>* myMap);
void deleteOnMap(double value, map <double, double>* myMap);

void insertOnUnMap(string file, unordered_map <double, double>* unMap);
void searchOnUnMap(double value, unordered_map <double, double>* unMap);
void deleteOnUnMap(double value, unordered_map <double, double>* unMap);

void printMap(map <double, double>* myMap);
void printUnMap(unordered_map <double, double>* unMap);
#endif