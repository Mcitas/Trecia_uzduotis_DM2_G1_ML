#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::right;
using std::end;
using std::begin;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::swap;
using std::getline;
using std::stoi;
using std::cerr;

struct Studentas {
string vardas, pavarde;
vector <int> pazymys;
float egzaminas;
float vidurkis;
float mediana;
};

int Skaiciaus_Ivedimas (int x1, int x2);
void IrasykRanka (int m, Studentas &x, int &n, int &sum, int i);
void Skaityk (vector <Studentas> &kursas, int &m);
void VidurkisIrMediana (int &sum, int &n, Studentas &x, vector <Studentas> &kursas);
void Rikiuok (vector <Studentas> &kursas);
void Generuok (Studentas &x, int &n, int &sum);

#endif // MYLIB_H_INCLUDED
