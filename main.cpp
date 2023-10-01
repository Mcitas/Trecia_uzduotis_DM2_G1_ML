#include "mylib.h"

int main()
{
    Studentas x;
    vector <Studentas> kursas;
    int m = 0, n = 0, y, n1;
    int sum = 0;

    cout << "Kaip ivesite duomenis? (1 - Ranka; 2 - Is failo)" << endl;
    cin >> y;

    if (y == 1)
    {
        cout << "Iveskite studentu skaiciu kurse:" << endl;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            IrasykRanka (m, x, n, sum, i);
            VidurkisIrMediana (sum, n, x, kursas);
        }
    }
    else
    {
        cout << "Kiek namu darbu pazymiu?" << endl;
        cin >> n1;
        Skaityk (n1, kursas, m);
    }

    Rikiuok (kursas, m);

    cout << setw(15) << left << "Vardas" << setw(15) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    cout << setw(20) << right << "Galutinis (Med.)" << endl;

    cout << "------------------------------------------------------------------------" << endl;
    for (auto &a: kursas)
    {
        cout << setw(15) << left << a.vardas << setw(15) << right << a.pavarde;
        cout << setw(20) << right << setprecision(2) << fixed << a.vidurkis*0.4 + a.egzaminas*0.6;
        cout << setw(20) << right << setprecision(2) << fixed << a.mediana*0.4 + a.egzaminas*0.6 << endl;
    }
    return 0;
}
