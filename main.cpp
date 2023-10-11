#include "mylib.h"

int main()
{
    Studentas x;
    vector <Studentas> kursas;
    int m = 0, n = 0, n1, skaicius;
    int sum = 0;
    string y;

    cout << "Kaip ivesite duomenis? (1 - Ranka; 2 - Is failo)" << endl;

    skaicius = Skaiciaus_Ivedimas (1, 2);

    if (skaicius == 1)
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
        Skaityk (kursas, m);
    }
    Rikiuok (kursas);

    cout << "------------------------------------------------------------------------" << endl;
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
