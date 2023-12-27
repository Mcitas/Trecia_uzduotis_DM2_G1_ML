#include "main_head.h"
#include "su_vector.h"
#include "su_list.h"

void su_vector ()
{
    Studentas_v x;
    vector <Studentas_v> kursas, kietiakai, vargseliai, kursas1;
    int m = 0, n = 0, n1, skaicius, m1 = 0;
    int sum = 0;
    string y;

    cout << "Kaip ivesite duomenis? (1 - Ranka; 2 - Is failo) Taip pat galite generuoti faila (3 - Generuoti faila)." << endl;
    skaicius = Skaiciaus_Ivedimas_v (1, 3);
    switch (skaicius)
    {
        case 1:
        {
            cout << "Iveskite studentu skaiciu kurse:" << endl;
            cin >> m;
            for (int i = 0; i < m; i++)
            {
                IrasykRanka_v (m, x, n, sum, i);
                VidurkisIrMediana_v (sum, n, x, kursas);
            }
            Rikiuok_v (kursas);
            Isvedimas_i_konsole_v (kursas);
            break;
        }
        case 2:
        {
            string fpav;
            cout << "Koks failo pavadinimas?" << endl;
            cin >> fpav;
            auto start = std::chrono::high_resolution_clock::now();
            Skaityk_v (kursas, m, fpav);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << m << " studentu failo skaitymas uztruko: "<< diff.count() << " s;" << endl;

            Rikiuok_v (kursas);

            start = std::chrono::high_resolution_clock::now();
            Rusiuok_v (kursas, kietiakai, vargseliai);
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff1 = end-start;
            cout << m << " studentu failo rusiavimas i du vektorius uztruko: "<< diff1.count() << " s;" << endl;

            start = std::chrono::high_resolution_clock::now();
            Isvedimas_i_faila_v (kietiakai, "Kietiakai");
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff2 = end-start;
            cout << m << " kietiaku failo isvedimas uztruko: "<< diff2.count() << " s;" << endl;

            start = std::chrono::high_resolution_clock::now();
            Isvedimas_i_faila_v (vargseliai, "Vargseliai");
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff3 = end-start;
            cout << m << " vargseliu failo isvedimas uztruko: "<< diff3.count() << " s;" << endl;
            break;
        }
        case 3:
        {
            cout << "Kiek studentu kurse?" << endl;
            cin >> m;
            Failo_generavimas_v (m, n);
            break;
        }
        default:
        {
            cout << "Klaida";
        }
    }
}

void su_list ()
{
    Studentas x;
    list <Studentas> kursas, kietiakai, vargseliai, kursas1;
    int m = 0, n = 0, n1, skaicius, m1 = 0;
    int sum = 0;
    string y;

    cout << "Kaip ivesite duomenis? (1 - Ranka; 2 - Is failo) Taip pat galite generuoti faila (3 - Generuoti faila)." << endl;
    skaicius = Skaiciaus_Ivedimas (1, 3);
    switch (skaicius)
    {
        case 1:
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
            break;
        }
        case 2:
        {
            string fpav;
            cout << "Koks failo pavadinimas?" << endl;
            cin >> fpav;
            auto start = std::chrono::high_resolution_clock::now();
            Skaityk (kursas, m, fpav);
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff = end-start;
            cout << m << " studentu failo skaitymas uztruko: "<< diff.count() << " s;" << endl;

            Rikiuok (kursas);

            start = std::chrono::high_resolution_clock::now();
            Rusiuok (kursas, kietiakai, vargseliai);
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff1 = end-start;
            cout << m << " studentu failo rusiavimas i du vektorius uztruko: "<< diff1.count() << " s;" << endl;

            start = std::chrono::high_resolution_clock::now();
            Isvedimas_i_faila (kietiakai, "Kietiakai");
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff2 = end-start;
            cout << m << " kietiaku failo isvedimas uztruko: "<< diff2.count() << " s;" << endl;

            start = std::chrono::high_resolution_clock::now();
            Isvedimas_i_faila (vargseliai, "Vargseliai");
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> diff3 = end-start;
            cout << m << " vargseliu failo isvedimas uztruko: "<< diff3.count() << " s;" << endl;
            break;
        }
        case 3:
        {
            cout << "Kiek studentu kurse?" << endl;
            cin >> m;
            Failo_generavimas (m, n);
            break;
        }
        default:
        {
            cout << "Klaida";
        }
    }
}
