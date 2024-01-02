#pragma once
#ifndef _DLL_H_
#define _DLL_H_

#include <iostream>
#include <stdio.h>
#include <windows.h>

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

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

extern "C"
class Zmogus {
protected:
    string vardas_, pavarde_;
public:
    virtual void setVardas(string vardas) { vardas_ = vardas; }
    virtual void setPavarde(string pavarde) { pavarde_ = pavarde; }
    virtual void abstrakcioji() const = 0; // apibreziama kaip abstrakti klase
};

extern "C"
class Studentas : public Zmogus {
private:
    int egzas_;
    vector<int> pazymiai;
    float balasv_, balasm_, mediana_;
    double* elem;

public:
    Studentas() : Zmogus(), egzas_(0), balasv_(0), balasm_(0), mediana_(0), elem(nullptr) {};
    ~Studentas() { delete[] elem; };

    Studentas(const Studentas& o) {
        vardas_ = o.vardas_;
        pavarde_ = o.pavarde_;
        egzas_ = o.egzas_;
        pazymiai = o.pazymiai;
        balasv_ = o.balasv_;
        balasm_ = o.balasm_;
        mediana_ = o.mediana_;
        if (o.elem != nullptr)
        {
            elem = new double[o.pazymiai.size()];
            copy(o.elem, o.elem + o.pazymiai.size(), elem);
        }
        else
        {
            elem = nullptr;
        }
    }
    
    Studentas& operator=(const Studentas& o) {
        if (this != &o)
        {
            vardas_ = o.vardas_;
            pavarde_ = o.pavarde_;
            egzas_ = o.egzas_;
            pazymiai = o.pazymiai;
            balasv_ = o.balasv_;
            balasm_ = o.balasm_;
            mediana_ = o.mediana_;
            delete[] elem;
            if (o.elem != nullptr)
            {
                elem = new double[o.pazymiai.size()];
                copy(o.elem, o.elem + o.pazymiai.size(), elem);
            }
            else
            {
                elem = nullptr;
            }
        }
        return *this;
    }

    friend istream& operator>>(istream& input, Studentas& s) {
        string vardas, pavarde;
        input >> vardas >> pavarde;
        s.setVardas(vardas);
        s.setPavarde(pavarde);
        return input;
    }

    friend ostream& operator<<(ostream& output, const Studentas& s) {
        output << setw(15) << left << s.getVardas() << setw(16) << right << s.getPavarde();
        return output;
    }

    string getVardas() const { return Zmogus::vardas_; }
    string getPavarde() const { return Zmogus::pavarde_; }
    vector<int> getPazymiai() const { return pazymiai; }
    int getEgzas() const { return egzas_; }
    float getBalasv() const { return balasv_; }
    float getBalasm() const { return balasm_; }
    float getMediana() const { return mediana_; }

    void setVardas(string vardas) { Zmogus::setVardas(vardas); }
    void setPavarde(string pavarde) { Zmogus::setPavarde(pavarde); }
    void setEgzas(int egzas) { egzas_ = egzas; };
    void setMediana(float mediana) { mediana_ = mediana; };
    void setPazymiai(int paz) { pazymiai.push_back(paz); };
    void setBalasv(float balasv) { balasv_ = balasv; };
    void setBalasm(float balasm) { balasm_ = balasm; };
    void clearPazymiai() { pazymiai.clear(); };

    void abstrakcioji() const {} //apibreziama kaip neabstrakti klase
};

extern "C"
DLL_API bool pagalVarda(const Studentas&, const Studentas&);

extern "C"
DLL_API bool pagalPavarde(const Studentas&, const Studentas&);

extern "C"
DLL_API bool pagalRezultata(const Studentas&, const Studentas&);

extern "C"
DLL_API int Skaiciaus_Ivedimas(int x1, int x2);

extern "C"
DLL_API void IrasykRanka(int m, Studentas& x, int& n, int& sum, int i);

extern "C"
DLL_API void Skaityk(vector<Studentas>& kursas, int& m, string fpav);

extern "C"
DLL_API void VidurkisIrMediana(int& sum, int& n, Studentas& x, vector<Studentas>& kursas);

extern "C"
DLL_API void Rikiuok(vector<Studentas>& kursas);

extern "C"
DLL_API void Generuok(Studentas& x, int& n, int& sum, int loginis, int randomizer);

extern "C"
DLL_API void Failo_generavimas(int& m, int& n);

extern "C"
DLL_API void Isvedimas_i_konsole(vector<Studentas> kursas);

extern "C"
DLL_API void Isvedimas_i_faila(vector<Studentas> kursas, string pav);

extern "C"
DLL_API void Rusiuok(vector<Studentas>& kursas, vector<Studentas>& vargseliai);

#endif