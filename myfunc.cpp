#include "mylib.h"

void IrasykRanka (int m, Studentas &x, int &n, int &sum, int i)
{
    int y;
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
                int p = stoi(input); //string to integer
                n++;
                x.pazymys.push_back(p);
                sum += p;
            }
        }
        //-------------------------------------------------------------------------------------------
           cout << "Iveskite egzamino rezultata:" << endl;
        cin >> x.egzaminas;
    }
}


void Skaityk (int &n1, vector <Studentas> &kursas, int &m)
{
    ifstream fd ("kursiokai.txt");
    string ignor;
    Studentas x;
    int paz, sum = 0, n = 0;

    getline(fd, ignor);
    while (fd >> x.vardas >> x.pavarde)
    {
        for (int i = 0; i < n1; i++)
        {
            fd >> paz;
            x.pazymys.push_back(paz);
            n++;
            sum += paz;
        }
        fd >> x.egzaminas;
        getline(fd, ignor);
        VidurkisIrMediana (sum, n, x, kursas);
        m++;
    }
    fd.close();
}

void VidurkisIrMediana (int &sum, int &n, Studentas &x, vector <Studentas> &kursas)
{
    x.vidurkis = static_cast<float>(sum)/n;
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

void Rikiuok (vector <Studentas> &kursas, int &m)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (kursas[i].vardas > kursas[j].vardas || (kursas[i].vardas == kursas[j].vardas && kursas[i].pavarde > kursas[j].pavarde))
            {
               swap(kursas[i], kursas[j]);
            }
        }
    }
}

void generuok (Studentas &x, int &n, int &sum)
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
