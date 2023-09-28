#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <cstdlib>

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

struct Studentas {
string vardas, pavarde;
vector <int> pazymys;
float egzaminas;
float vidurkis;
float mediana;
};

void generuok (Studentas &x, int &n, float &sum)
{
    srand(time(0));
    n = rand() % 5 + 1; // nuo 1 iki 5
    cout << "Sugeneruotas pazymiu kiekis: " << n << endl;
    cout << "Sugeneruoti pazymiai:" << endl;
    for (int i = 0; i < n; i++)
    {
        int p = rand() % 10 + 1; // nuo 1 iki 10
        x.pazymys.push_back(p);
        sum += p;
        cout << p << " ";
    }
    x.egzaminas = rand() % 10 + 1;
    cout << endl;
    cout << "Egzaminas: " << x.egzaminas << endl;
}

int main()
{
    Studentas x;
    vector <Studentas> kursas;
    int m, n = 0, y;
    float sum = 0;
    cout << "Iveskite studentu skaiciu kurse:" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Iveskite " << i + 1 << " studento varda:" << endl;
        cin >> x.vardas;
        cout << "Iveskite " << i + 1 << " studento pavarde:" << endl;
        cin >> x.pavarde;

        cout << "Ar siam studentui generuoti pazymius? (1 - TAIP, 2 - NE)" << endl;
        cin >> y;
        if (y == 1)
        {
           generuok(x, n, sum);
        }
        else
        {
            cout << "Iveskite " << i + 1 << " studento pazymius:" << endl;

        //----------------pazymiu ivedimas, kur breaking point - 2 enter paspaudimai-------------------
            while (true)
            {
                string input;
                getline(cin, input);
                if (input.empty())
                {
                    if (x.pazymys.size() >= 1)
                    {
                        break;
                    }
                }
                else
                {
                    int p = std::stoi(input);
                    n += 1;
                    x.pazymys.push_back(p);
                    sum += p;
                }
            }
            //-------------------------------------------------------------------------------------------
            cout << "Iveskite egzamino rezultata:" << endl;
            cin >> x.egzaminas;
        }
        x.vidurkis = (sum)/n;

        //----------------------skaiciuojam mediana---------------------------
        sort(x.pazymys.begin(), x.pazymys.end());
        int dyd = x.pazymys.size();
        if (dyd % 2 == 0)
        {
            x.mediana = static_cast<float>(x.pazymys[(dyd - 1) / 2] + x.pazymys[dyd / 2]) / 2;
        }
        else
        {
        x.mediana = x.pazymys[dyd / 2];
        }
        //---------------------------------------------------------------------
        kursas.push_back(x);
        x.pazymys.clear();
        sum = 0;
        n = 0;
    }
    cout << "Pagal ka skaiciuoti galutini bala? (1 - vidurkis, 2 - mediana)" << endl;
    cin >> y;

    if (y == 1)
        {
            cout << setw(15) << left << "Vardas" << setw(15) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)" << endl;
        }
        else
        {
            cout << setw(15) << left << "Vardas" << setw(15) << right << "Pavarde" << setw(20) << right << "Galutinis (Med.)" << endl;
        }

    cout << "----------------------------------------------------" << endl;
    for (auto &a: kursas)
    {
        cout << setw(15) << left << a.vardas << setw(15) << right << a.pavarde;
        if (y == 1)
        {
            cout << setw(20) << right << setprecision(2) << fixed << a.vidurkis*0.4 + a.egzaminas*0.6 << endl;
        }
        else
        {
            cout << setw(20) << right << setprecision(2) << fixed << a.mediana*0.4 + a.egzaminas*0.6 << endl;
        }
    }
    return 0;
}
