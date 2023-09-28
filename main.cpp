#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

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

struct Studentas {
string vardas, pavarde;
vector <int> pazymys;
float egzaminas;
float vidurkis;
};

int main()
{
    Studentas x;
    vector <Studentas> kursas;
    int m, n;
    float sum = 0;
    cout << "Iveskite studentu skaiciu kurse:" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cout << "Iveskite " << i + 1 << " studento varda:" << endl;
        cin >> x.vardas;
        cout << "Iveskite " << i + 1 << " studento pavarde:" << endl;
        cin >> x.pavarde;
        cout << "Kiek pazymiu turi " << i + 1 << " studentas?" << endl;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int p;
            cout << "Iveskite " << j + 1 << " pazymi:" << endl;
            cin >> p;
            x.pazymys.push_back(p);
            sum += p;

        }
        cout << "Iveskite egzamino rezultata:" << endl;
        cin >> x.egzaminas;
        x.vidurkis = sum/n;
        kursas.push_back(x);
        x.pazymys.clear();
        sum = 0;
    }

    cout << setw(15) << left << "Vardas" << setw(15) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)" << endl;
    cout << "----------------------------------------------------" << endl;
    for (auto &a: kursas)
    {
        cout << setw(15) << left << a.vardas << setw(15) << right << a.pavarde << setw(20) << right << setprecision(2) << fixed << a.vidurkis*0.4 + a.egzaminas*0.6 << endl;
    }
    return 0;
}
