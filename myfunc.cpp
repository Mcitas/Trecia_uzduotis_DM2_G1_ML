#include "mylib.h"

int Skaiciaus_Ivedimas (int x1, int x2)
{
    string y;
    int number;
    bool validInput = false;

    while (!validInput)
    {
        try
        {
            cin >> y;
            number = stoi(y);
            if (number < x1 || number > x2)
            {
                throw std::out_of_range("");
            }
            validInput = true;
        }

        catch (const std::invalid_argument& e)
        {
            cerr << "Ivedete ne skaiciu. Bandykite dar karta. (" << e.what() << ")" << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            cerr << "Per mazas arba per didelis skaicius. Iveskite skaiciu tarp " << x1 << " ir " << x2 << ":" << e.what() << std::endl;
        }
    }
    return number;
}

void IrasykRanka (int m, Studentas &x, int &n, int &sum, int i)
{
    string y;
    cout << "Iveskite " << i + 1 << " studento varda:" << endl;
    cin >> x.vardas;
    cout << "Iveskite " << i + 1 << " studento pavarde:" << endl;
    cin >> x.pavarde;
    cout << "Ar siam studentui generuoti pazymius? (1 - TAIP, 2 - NE)" << endl;
    int skaicius = Skaiciaus_Ivedimas (1, 2);
    if (skaicius == 1)
    {
        Generuok(x, n, sum);
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
        skaicius = Skaiciaus_Ivedimas(1, 10);
    }
}


void Skaityk (vector <Studentas> &kursas, int &m)
{
    ifstream fd ("studentai100000.txt");
    string header, ignor;
    Studentas x;
    int paz, sum = 0, n = 0, raidziu_sk = 0, n1, t = 0;

    if (!fd.is_open())
    {
    cerr << "Klaida. Failas nerastas." << endl;
    }

    getline(fd, header);
    for (char ch : header)
    {
        if (isalpha(ch))
            {
                raidziu_sk++;
            }
    }
    n1 =(raidziu_sk -6-7-3)/2;

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

bool palyginimas(Studentas &a, Studentas &b)
{
    return a.vardas < b.vardas || a.vardas == b.vardas && a.pavarde < b.pavarde;
}

void Rikiuok(vector<Studentas> &kursas)
{
    sort(kursas.begin(), kursas.end(), palyginimas);
}

void Generuok (Studentas &x, int &n, int &sum)
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
