// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "Dll.h"

int Skaiciaus_Ivedimas(int x1, int x2)
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

void IrasykRanka(int m, Studentas& x, int& n, int& sum, int i)
{
    string y;
    cout << "Iveskite " << i + 1 << " studento varda ir pavarde:" << endl;
    cin >> x; // IVEDIMAS RANKA
    cout << "Ar siam studentui generuoti pazymius? (1 - TAIP, 2 - NE)" << endl;
    int skaicius = Skaiciaus_Ivedimas(1, 2);
    if (skaicius == 1)
    {
        Generuok(x, n, sum, 1, i);
    }
    else
    {
        n = 0;
        cout << "Iveskite " << i + 1 << " studento pazymius:" << endl;
        //----------------pazymiu ivedimas, kur breaking point - 2 enter paspaudimai-------------------
        while (true)
        {
            string input;
            getline(cin, input);
            if (input.empty())
            {
                if (x.getPazymiai().size() >= 1)
                {
                    break;
                }
            }
            else
            {
                int p = stoi(input); //string to integer
                n++;
                x.setPazymiai(p);
                sum += p;
            }
        }
        //-------------------------------------------------------------------------------------------
        cout << "Iveskite egzamino rezultata:" << endl;
        skaicius = Skaiciaus_Ivedimas(1, 10);
        x.setEgzas(skaicius);
    }
}


void Skaityk(vector <Studentas>& kursas, int& m, string fpav)
{
    ifstream fd(fpav);
    string header, ignor;
    Studentas x;
    int paz, sum = 0, n = 0, raidziu_sk = 0, n1, t = 0;
    m = 0;
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
    n1 = (raidziu_sk - 6 - 7 - 3) / 2;
    int egzas;
    while (fd >> x) //IVEDIMAS IS FAILO
    {
        for (int i = 0; i < n1; i++)
        {
            fd >> paz;
            x.setPazymiai(paz);
            sum += paz;
        }
        fd >> egzas;
        x.setEgzas(egzas);
        getline(fd, ignor);
        VidurkisIrMediana(sum, n1, x, kursas);
        m++;
    }
    fd.close();
}

void VidurkisIrMediana(int& sum, int& n, Studentas& x, vector <Studentas>& kursas)
{
    float vidurkis = static_cast<float>(sum) / n;
    vector<int> pazymiai = x.getPazymiai();
    sort(pazymiai.begin(), pazymiai.end());
    int dyd = pazymiai.size();
    float med;
    if (dyd % 2 == 0)
    {
        med = static_cast<float>(pazymiai[(dyd - 1) / 2] + pazymiai[dyd / 2]) / 2;
    }
    else
    {
        med = pazymiai[dyd / 2];
    }
    x.setMediana(med);
    float balm = static_cast<float>(x.getMediana() * 0.4 + x.getEgzas() * 0.6);
    float balv = static_cast<float>(vidurkis * 0.4 + x.getEgzas() * 0.6);
    x.setBalasm(balm);
    x.setBalasv(balv);
    kursas.push_back(x);
    x.clearPazymiai();
    sum = 0;
}

bool palyginimas1(const Studentas& a, const Studentas& b) {
    return a.getVardas() < b.getVardas();
}
bool palyginimas2(const Studentas& a, const Studentas& b) {
    return a.getPavarde() < b.getPavarde();
}
bool palyginimas3(const Studentas& a, const Studentas& b) {
    return a.getBalasv() < b.getBalasv();
}

void Rikiuok(vector<Studentas>& kursas)
{
    int loginis;

    cout << "Pagal ka rikiuoti duomenis? (1 - Pagal varda; 2 - Pagal pavarde; 3 - Pagal galutini pazymi)" << endl;
    cin >> loginis;

    switch (loginis) {
    case 1:
    {
        sort(kursas.begin(), kursas.end(), palyginimas1);
        break;
    }
    case 2:
    {
        sort(kursas.begin(), kursas.end(), palyginimas2);
        break;
    }
    case 3:
    {
        sort(kursas.begin(), kursas.end(), palyginimas3);
        break;
    }
    default:
    {
        cout << "Klaida";
        //return 0;
    }
    }

}

void Generuok(Studentas& x, int& n, int& sum, int loginis, int randomizer)
{
    srand(static_cast<unsigned>(time(nullptr)));
    if (loginis == 1)
    {
        n = (rand() % 5) + 1; // nuo 1 iki 5
        cout << "Sugeneruotas pazymiu kiekis: " << n << endl;
        cout << "Sugeneruoti pazymiai:" << endl;
    }
    for (int i = 0; i < n; i++)
    {
        int p = (rand() % 10) + 1; // nuo 1 iki 10
        x.setPazymiai(p);
        sum += p;
        if (loginis == 1)
        {
            cout << p << " ";
        }
    }
    x.setEgzas((rand() % 10) + 1);
    if (loginis == 1)
    {
        cout << endl;
        cout << "Egzaminas: " << x.getEgzas() << endl;
    }
}

void Failo_generavimas(int& m, int& n)
{
    srand(static_cast<unsigned>(time(nullptr)));
    ofstream fr("Studentai" + to_string(m) + ".txt");
    Studentas x;
    int sum;

    cout << "Kiek pazymiu turi kiekvienas studentas?" << endl;
    cin >> n;
    auto start = std::chrono::high_resolution_clock::now();

    fr << setw(15) << left << "Vardas" << setw(16) << left << "Pavarde";
    for (int i = 0; i < n; i++)
    {
        fr << setw(5) << "ND" + to_string(i + 1);
    }
    fr << setw(7) << right << "Egz." << endl;

    for (int i = 0; i < m; i++)
    {
        string vardas = "Vardas" + to_string(i + 1), pavarde = "Pavarde" + to_string(i + 1);;

        x.setVardas(vardas);
        x.setPavarde(pavarde);
        x.clearPazymiai();
        for (int i = 0; i < n; i++)
        {
            int p = (rand() % 10) + 1; // nuo 1 iki 10
            x.setPazymiai(p);
        }
        x.setEgzas((rand() % 10) + 1);
        fr << x; // ISVEDIMAS
        for (auto& b : x.getPazymiai())
        {
            fr << setw(5) << b;
        }
        fr << setw(7) << right << x.getEgzas() << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << m << " studentu failo generavimas uztruko: " << diff.count() << " s;" << endl;
    fr.close();
}

void Isvedimas_i_konsole(vector <Studentas> kursas)
{
    cout << "Grupes objekto saugojimo atmintyje adresas: " << &kursas << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Vardas" << setw(16) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    cout << setw(20) << right << "Galutinis (Med.)" << setw(20) << right << "Std. Adresas" << endl;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    for (auto& a : kursas)
    {
        cout << a; // ISVEDIMAS
        cout << setw(20) << right << setprecision(2) << fixed << a.getBalasv();
        cout << setw(20) << right << setprecision(2) << fixed << a.getBalasm();
        cout << setw(20) << right << &a << endl;
    }
}

void Isvedimas_i_faila(vector <Studentas> kursas, string pav)
{
    ofstream fr("Rezultatai_" + pav + ".txt");
    fr << setw(15) << left << "Vardas" << setw(16) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    fr << setw(20) << right << "Galutinis (Med.)" << endl;

    for (auto& a : kursas)
    {
        fr << a; // ISVEDIMAS
        fr << setw(20) << right << setprecision(2) << fixed << a.getBalasv();
        fr << setw(20) << right << setprecision(2) << fixed << a.getBalasm() << endl;
    }
    fr.close();
}

void Rusiuok(vector <Studentas>& kursas, vector <Studentas>& vargseliai)
{
    auto partitionPoint = std::partition(kursas.begin(), kursas.end(), [](const Studentas& a) {
        return a.getBalasv() < 5;
        });
    vargseliai.insert(vargseliai.end(), kursas.begin(), partitionPoint);
    kursas.erase(kursas.begin(), partitionPoint);
}

