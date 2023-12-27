#include "main_head.h"

int main()
{
    char tipas;
    cout << "Su kokio tipo konteineriu norite dirbti? (V - vektorius, L - sarasas)" << endl;
    cin >> tipas;
    if (tipas == 'V')
    {
        su_vector();
    }
    else if (tipas == 'L')
    {
        su_list();
    }
    else
    {
        cout << "Neteisingas simbolis.";
    }
    return 0;
}
