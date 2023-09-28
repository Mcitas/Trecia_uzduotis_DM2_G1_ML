using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

struct Studentas {
string vardas, pavarde;
vector <int> pazymys;
int egzaminas;
};

int main()
{
    Studentas x;
    vector <Studentas> kursas;
    int m, n;
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
        }
        cout << "Iveskite egzamino rezultata:" << endl;
        cin >> x.egzaminas;
        kursas.push_back(x);
        x.pazymys.clear();
    }
    return 0;
}
