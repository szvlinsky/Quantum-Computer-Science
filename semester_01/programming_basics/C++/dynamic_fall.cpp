#include <iostream>
using namespace std;

int main() {
    int S, k;
    cin >> S >> k;
    int tab[35] = {0};
    tab[0] = 1;  

    for (int i = 1; i <= S; i++) {
        int suma = 0;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) suma += tab[i - j];
        }
        tab[i] = suma;
    }
    cout << tab[S];
    return 0;
}