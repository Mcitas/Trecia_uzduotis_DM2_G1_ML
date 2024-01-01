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
using std::istream;
using std::ostream;
using std::copy;

class Studentas {
private:
    string vardas_, pavarde_;
    int egzas_;
    vector<int> pazymiai;
    float balasv_, balasm_, mediana_;
    double* elem;

public:
    Studentas() : egzas_(0), balasv_(0), balasm_(0), mediana_(0), elem(nullptr) {};
    ~Studentas();
    Studentas(const Studentas& o);
    Studentas& operator=(const Studentas& o);

    friend istream& operator>>(istream& input, Studentas& s) {
        string vardas, pavarde;
        int egzas, paz;
        input >> vardas >> pavarde;
        for (int i = 0; i < 5; i++)
        {
            input >> paz;
            s.setPazymiai(paz);
        }
        input >> egzas;
        s.setVardas(vardas);
        s.setPavarde(pavarde);
        s.setEgzas(egzas);
        return input;
    }

    friend ostream& operator<<(ostream& output, const Studentas& s) {
        output << setw(15) << left << s.getVardas() << setw(16) << right << s.getPavarde();
        output << setw(20) << right << setprecision(2) << fixed << s.getBalasv();
        output << setw(20) << right << setprecision(2) << fixed << s.getBalasm();
        return output;
    }

    string getVardas() const { return vardas_; }
    string getPavarde() const { return pavarde_; }
    vector<int> getPazymiai() const { return pazymiai; }
    int getEgzas() const { return egzas_; }
    float getBalasv() const { return balasv_; }
    float getBalasm() const { return balasm_; }
    float getMediana() const { return mediana_; }

    void setVardas(string);
    void setPavarde(string);
    void setEgzas(int);
    void setMediana(float);
    void setPazymiai(int);
    void setBalasv(float);
    void setBalasm(float);
    void clearPazymiai();

};

bool pagalVarda(const Studentas&, const Studentas&);
bool pagalPavarde(const Studentas&, const Studentas&);
bool pagalRezultata(const Studentas&, const Studentas&);

int Skaiciaus_Ivedimas(int x1, int x2);
void IrasykRanka(int m, Studentas& x, int& n, int& sum, int i);
void Skaityk(vector<Studentas>& kursas, int& m, string fpav);
void VidurkisIrMediana(int& sum, int& n, Studentas& x, vector<Studentas>& kursas);
void Rikiuok(vector<Studentas>& kursas);
void Generuok(Studentas& x, int& n, int& sum, int loginis, int randomizer);
void Failo_generavimas(int& m, int& n);
void Isvedimas_i_konsole(vector<Studentas> kursas);
void Isvedimas_i_faila(vector<Studentas> kursas, string pav);
void Rusiuok(vector<Studentas>& kursas, vector<Studentas>& vargseliai);