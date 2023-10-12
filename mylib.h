#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
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
using std::to_string;

struct Studentas {
string vardas, pavarde;
vector <int> pazymys;
int egzaminas;
float vidurkis;
float mediana;
float balasm;
float balasv;
};

int Skaiciaus_Ivedimas (int x1, int x2);
void IrasykRanka (int m, Studentas &x, int &n, int &sum, int i);
void Skaityk (vector <Studentas> &kursas, int &m);
void VidurkisIrMediana (int &sum, int &n, Studentas &x, vector <Studentas> &kursas);
void Rikiuok (vector <Studentas> &kursas);
void Generuok (Studentas &x, int &n, int &sum, int loginis, int randomizer);
void Failo_generavimas (vector <Studentas> &kursas, int &m, int &n);
void Isvedimas_i_konsole (vector <Studentas> kursas);
void Isvedimas_i_faila (vector <Studentas> kursas, int n, string pav);
void Rusiuok (vector <Studentas> &kursas, vector <Studentas> &kietiakai, vector <Studentas> &vargseliai);

#endif // MYLIB_H_INCLUDED
