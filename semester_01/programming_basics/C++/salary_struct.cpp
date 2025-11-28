#include <iostream>
#include <string>
using namespace std;

struct pracownicy {
    int ile;
    string *imiona;
    string *nazwiska;
    string *pesel;
    int **pensje;

    pracownicy(int n) {
        ile = n;
        imiona = new string[n];
        nazwiska = new string[n];
        pesel = new string[n];

        pensje = new int*[n];
        for(int i = 0; i < n; i++) {
            pensje[i] = new int[12];
        }
    }
};

string nazwyMies[] = {
    "Styczen", "Luty", "Marzec", "Kwiecien", "Maj", "Czerwiec",
    "Lipiec", "Sierpien", "Wrzesien", "Pazdziernik", "Listopad", "Grudzien"
};

void podajPensje(pracownicy &p, const string &pes, int m) {
    for(int i = 0; i < p.ile; i++) {
        if(p.pesel[i] == pes) {
            cout << p.imiona[i] << " "
                 << p.nazwiska[i] << " "
                 << p.pesel[i]
                 << " wynagrodzenie za "
                 << nazwyMies[m-1] << " 2023: "
                 << p.pensje[i][m-1]
                 << endl;
            return;
        }
    }
    cout << "Brak pracownika o danym numerze pesel" << endl;
}

int main() {
    int x;
    cin >> x;

    pracownicy P(x);

    for(int i = 0; i < x; i++) {
        cin >> P.imiona[i] >> P.nazwiska[i] >> P.pesel[i];
        for(int j = 0; j < 12; j++) {
            cin >> P.pensje[i][j];
        }
    }

    int y;
    cin >> y;

    for(int i = 0; i < y; i++) {
        string pes;
        int m;
        cin >> pes >> m;
        podajPensje(P, pes, m);
    }

    return 0;
}