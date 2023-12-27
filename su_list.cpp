#include "su_list.h"

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

void IrasykRanka(int m, Studentas &x, int &n, int &sum, int i)
{
    string y;
    cout << "Iveskite " << i + 1 << " studento varda:" << endl;
    cin >> x.vardas;
    cout << "Iveskite " << i + 1 << " studento pavarde:" << endl;
    cin >> x.pavarde;
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

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        while (true)
        {
            string input;
            getline(cin, input);
            if (input.empty())
            {
                if (!x.pazymys.empty())
                {
                    break;
                }
            }
            else
            {
                int p = stoi(input);
                n++;
                x.pazymys.push_back(p);
                sum += p;
            }
        }

        cout << "Iveskite egzamino rezultata:" << endl;
        skaicius = Skaiciaus_Ivedimas(1, 10);
        x.egzaminas = skaicius;
    }
}


void Skaityk (list <Studentas> &kursas, int &m, string fpav)
{
    ifstream fd (fpav);
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
    n1 =(raidziu_sk -6-7-3)/2;

    while (fd >> x.vardas >> x.pavarde)
    {
        for (int i = 0; i < n1; i++)
        {
            fd >> paz;
            x.pazymys.push_back(paz);
            sum += paz;
        }
        fd >> x.egzaminas;
        getline(fd, ignor);
        VidurkisIrMediana (sum, n1, x, kursas);
        m++;
    }
    fd.close();
}

void VidurkisIrMediana (int &sum, int &n, Studentas &x, list <Studentas> &kursas)
{
    x.vidurkis = static_cast<float>(sum)/n;
        //----------------------skaiciuojam mediana---------------------------
    x.pazymys.sort();
    int dyd = x.pazymys.size();
    auto it = x.pazymys.begin();
    advance(it, dyd / 2);

    if (dyd % 2 == 0)
    {
        auto it2 = it;
        --it2;
        x.mediana = static_cast<float>(*it + *it2) / 2;
    }
    else
    {
        x.mediana = *it;
    }
    //---------------------------------------------------------------------
    x.balasm = static_cast<float>(x.mediana*0.4 + x.egzaminas*0.6);
    x.balasv = static_cast<float>(x.vidurkis*0.4 + x.egzaminas*0.6);
    kursas.push_back(x);
    x.pazymys.clear();
    sum = 0;
}

bool palyginimas1(Studentas &a, Studentas &b)
{
    return a.vardas < b.vardas;
}

bool palyginimas2(Studentas &a, Studentas &b)
{
    return a.pavarde < b.pavarde;
}

bool palyginimas3(Studentas &a, Studentas &b)
{
    return a.balasv < b.balasv;
}

void Rikiuok(list <Studentas> &kursas)
{
    int loginis;

    cout << "Pagal ka rikiuoti duomenis? (1 - Pagal varda; 2 - Pagal pavarde; 3 - Pagal galutini pazymi)" << endl;
    cin >> loginis;

    switch (loginis){
        case 1:
    {
        kursas.sort(palyginimas1);
        break;
    }
        case 2:
    {
        kursas.sort(palyginimas2);
        break;
    }
        case 3:
    {
        kursas.sort(palyginimas3);
        break;
    }
    default:
        {
            cout << "Klaida";
        }
    }

}

void Generuok (Studentas &x, int &n, int &sum, int loginis, int randomizer)
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
        x.pazymys.push_back(p);
        sum += p;
        if (loginis == 1)
        {
        cout << p << " ";
        }
    }
    x.egzaminas = (rand() % 10) + 1;;
    if (loginis == 1)
    {
    cout << endl;
    cout << "Egzaminas: " << x.egzaminas << endl;
    }
}

void Failo_generavimas (int &m, int &n)
{
    srand(static_cast<unsigned>(time(nullptr)));
    ofstream fr ("Studentai" + to_string(m) + ".txt");
    Studentas x;
    int sum;

    cout << "Kiek pazymiu turi kiekvienas studentas?" << endl;
    cin >> n;
    auto start = std::chrono::high_resolution_clock::now();

    fr << setw(15) << left << "Vardas" << setw(16) << left << "Pavarde";
    for (int i = 0; i < n; i++)
    {
        fr << setw(5) << "ND" + to_string(i+1);
    }
    fr << setw(7) << right << "Egz." << endl;

    for (int i = 0; i < m; i++)
    {
        x.vardas = "Vardas" + to_string(i + 1);
        x.pavarde = "Pavarde" + to_string(i + 1);
        x.pazymys.clear();
        for (int i = 0; i < n; i++)
        {
            int p = (rand() % 10) + 1; // nuo 1 iki 10
            x.pazymys.push_back(p);
        }
        x.egzaminas = (rand() % 10) + 1;
        fr << setw(15) << left << x.vardas << setw(16) << left << x.pavarde;
        for (auto &b: x.pazymys)
        {
            fr << setw(5) << b;
        }
        fr << setw(7) << right << x.egzaminas << endl;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << m << " studentu failo generavimas uztruko: "<< diff.count() << " s;" << endl;
    fr.close();
}

void Isvedimas_i_konsole (list <Studentas> kursas)
{
    cout << "Grupes objekto saugojimo atmintyje adresas: " << &kursas << endl;
    cout << "----------------------------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Vardas" << setw(15) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    cout << setw(20) << right << "Galutinis (Med.)" << setw(20) << right << "Std. Adresas" << endl;

    cout << "----------------------------------------------------------------------------------------------" << endl;
    for (auto &a: kursas)
    {
        cout << setw(15) << left << a.vardas << setw(15) << right << a.pavarde;
        cout << setw(20) << right << setprecision(2) << fixed << a.balasv;
        cout << setw(20) << right << setprecision(2) << fixed << a.balasm;
        cout << setw(20) << right << &a << endl;
    }
}

void Isvedimas_i_faila (list <Studentas> kursas, string pav)
{
    ofstream fr ("Rezultatai" + pav + ".txt");
    fr << setw(15) << left << "Vardas" << setw(16) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    fr << setw(20) << right << "Galutinis (Med.)" << endl;

    for (auto &a: kursas)
    {
        fr << setw(15) << left << a.vardas << setw(16) << right << a.pavarde;
        fr << setw(20) << right << setprecision(2) << fixed << a.balasv;
        fr << setw(20) << right << setprecision(2) << fixed << a.balasm << endl;
    }
    fr.close();
}

void Rusiuok(list<Studentas>& kursas, list<Studentas>& vargseliai)
{
    auto partitionPoint = std::partition(kursas.begin(), kursas.end(), [](const Studentas &a) {
        return a.balasv < 5;
        });
    vargseliai.insert(vargseliai.end(), kursas.begin(), partitionPoint);
    kursas.erase(kursas.begin(), partitionPoint);
}
