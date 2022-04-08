#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int main() {

    string data,dia, mes, ano;

    getline(cin, data);
    int pos1 = data.find("/");
    int pos2=data.rfind("/");

    dia = data.substr(0,pos1);
    mes = data.substr(pos1+1,(pos2-pos1)-1);
    ano = data.substr(pos2+1,4);

    int d = stoi(dia);
    int m = stoi(mes);
    int a = stoi(ano);


    //check ano
    if (ano.size()!= 4){
        cout << "data invalida" << endl;
        return 0;
    }

    // check mes e ano
    if ((m >= 1 && m <= 12) && (a>=1 && a <= 9999) ) {

        // check dia e mês
        if ((d >= 1 && d <= 31) &&
            (m == 1 || m == 3 || m == 5 || m== 7 || m == 8 || m == 10 || m == 12))
            cout << dia << "/" << mes << "/" << ano << endl;
        else if ((d >= 1 && d <= 30) && (m == 4 || m == 6 || m == 9 || m == 11))
            cout << dia << "/" << mes << "/" << ano << endl;
        else if ((d >= 1 && d <= 28) && (m == 2))
            cout << dia << "/" << mes << "/" << ano << endl;
            //check bissexto
        else if (d == 29 && m == 2 && (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0)))
            cout << dia << "/" << mes << "/" << ano << endl;
        else
            cout << "data invalida" << endl;
        return 0;
    }
    cout << "data invalida" << endl;
    return 0;
}