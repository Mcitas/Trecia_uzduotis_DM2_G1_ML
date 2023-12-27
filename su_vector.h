#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <chrono>

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

struct Studentas_v {
string vardas, pavarde;
vector <int> pazymys;
int egzaminas;
float vidurkis;
float mediana;
float balasm;
float balasv;
};

int Skaiciaus_Ivedimas_v(int x1, int x2);
void IrasykRanka_v(int m, Studentas_v &x, int &n, int &sum, int i);
void Skaityk_v(vector<Studentas_v> &kursas, int &m, string fpav);
void VidurkisIrMediana_v(int &sum, int &n, Studentas_v &x, vector<Studentas_v> &kursas);
void Rikiuok_v(vector<Studentas_v> &kursas);
void Generuok_v(Studentas_v &x, int &n, int &sum, int loginis, int randomizer);
void Failo_generavimas_v(int &m, int &n);
void Isvedimas_i_konsole_v(vector<Studentas_v> kursas);
void Isvedimas_i_faila_v(vector<Studentas_v> kursas, string pav);
void Rusiuok_v(vector<Studentas_v> &kursas, vector<Studentas_v> &vargseliai);

