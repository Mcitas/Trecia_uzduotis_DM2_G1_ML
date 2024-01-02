#include "v1.5_head.h"

int main()
{
    Studentas x;

    //Zmogus kazkoks_zmogus; //neveiks, nes Zmogus klase - abstrakcioji

    vector <Studentas> kursas, vargseliai, kursas1;
    int m = 0, n = 0, skaicius, m1 = 0;
    int sum = 0;
    string y;

    cout << "Kaip ivesite duomenis? (1 - Ranka; 2 - Is failo) Taip pat galite generuoti faila (3 - Generuoti faila) arba demontstruoti Treju taisykle (4)." << endl;
    skaicius = Skaiciaus_Ivedimas(1, 4);
    switch (skaicius)
    {
    case 1:
    {
        cout << "Iveskite studentu skaiciu kurse:" << endl;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            IrasykRanka(m, x, n, sum, i);
            VidurkisIrMediana(sum, n, x, kursas);
        }
        Rikiuok(kursas);
        Isvedimas_i_konsole(kursas);
        break;
    }
    case 2:
    {
        string fpav;
        cout << "Koks failo pavadinimas?" << endl;
        cin >> fpav;
        auto start = std::chrono::high_resolution_clock::now();
        Skaityk(kursas, m, fpav);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        cout << m << " studentu failo skaitymas uztruko: " << diff.count() << " s;" << endl;

        Rikiuok(kursas);

        start = std::chrono::high_resolution_clock::now();
        Rusiuok(kursas, vargseliai);
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end - start;
        cout << m << " studentu failo rusiavimas i du vektorius uztruko: " << diff1.count() << " s;" << endl;

        start = std::chrono::high_resolution_clock::now();
        Isvedimas_i_faila(kursas, "Kietiakai");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end - start;
        cout << m << " kietiaku failo isvedimas uztruko: " << diff2.count() << " s;" << endl;

        start = std::chrono::high_resolution_clock::now();
        Isvedimas_i_faila(vargseliai, "Vargseliai");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff3 = end - start;
        cout << m << " vargseliu failo isvedimas uztruko: " << diff3.count() << " s;" << endl;

        std::chrono::duration<double> total_duration = diff + diff1 + diff2 + diff3;
        cout << "--------------------------------" << endl;
        cout << "VISAS LAIKAS:" << total_duration.count() << " s.";
        break;
    }
    case 3:
    {
        cout << "Kiek studentu kurse?" << endl;
        cin >> m;
        Failo_generavimas(m, n);
        break;
    }
    case 4:
    {
        Studentas stud;
        stud.setVardas("Vardenis");
        stud.setPavarde("Pavardenis");
        Studentas stud_copy{stud};
        Studentas stud_prisk = stud;
        cout << "Sukurtas studentas: " << endl;
        cout << stud << endl;
        cout << "Nukopijuotas studentas: " << endl;
        cout << stud_copy << endl;
        cout << "Priskirtas studentas: " << endl;
        cout << stud_prisk << endl;
        break;
    }
    default:
    {
        cout << "Klaida";
    }
    }
}
