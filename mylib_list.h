#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <list>

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
using std::list;

struct Studentas {
string vardas, pavarde;
list <int> pazymys;
int egzaminas;
float vidurkis;
float mediana;
float balasm;
float balasv;
};

int Skaiciaus_Ivedimas (int x1, int x2);
void IrasykRanka (int m, Studentas &x, int &n, int &sum, int i);
void Skaityk (list <Studentas> &kursas, int &m, string fpav);
void VidurkisIrMediana (int &sum, int &n, Studentas &x, list <Studentas> &kursas);
void Rikiuok (list <Studentas> &kursas);
void Generuok (Studentas &x, int &n, int &sum, int loginis, int randomizer);
void Failo_generavimas (int &m, int &n);
void Isvedimas_i_konsole (list <Studentas> kursas);
void Isvedimas_i_faila (list <Studentas> kursas, string pav);
void Rusiuok (list <Studentas> &kursas, list <Studentas> &kietiakai, list <Studentas> &vargseliai);

#endif
