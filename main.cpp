#include "mylib.h"

int main()
{
    Studentas x;
    vector <Studentas> kursas, kietiakai, vargseliai;
    int m = 0, n = 0, n1, skaicius;
    int sum = 0;
    string y;

    cout << "Kaip ivesite duomenis? (1 - Ranka; 2 - Is failo) Taip pat galite generuoti faila (3 - Generuoti faila)." << endl;

    skaicius = Skaiciaus_Ivedimas (1, 3);

    if (skaicius == 1)
    {
        cout << "Iveskite studentu skaiciu kurse:" << endl;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            IrasykRanka (m, x, n, sum, i);
            VidurkisIrMediana (sum, n, x, kursas);
        }
    Rikiuok (kursas);
    Isvedimas_i_konsole (kursas);
    }
    else if (skaicius == 2)
    {
        Skaityk (kursas, m);
        Rikiuok (kursas);
        Isvedimas_i_konsole (kursas);
    }
    else
    {
        cout << "Kiek studentu kurse?" << endl;
        cin >> m;
        Failo_generavimas (kursas, m, n);
        Rusiuok (kursas, kietiakai, vargseliai);
        Isvedimas_i_faila (kietiakai, n, "Kietiakai");
        Isvedimas_i_faila (vargseliai, n, "Vargseliai");
    }
    return 0;
}
