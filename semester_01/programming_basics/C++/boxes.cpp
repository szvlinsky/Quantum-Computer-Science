#include <iostream>
using namespace std;

int main(){
    int n, x, y, n1, n2;
    cin >> n;

    int *tab = new int[n];
    int *t = new int[n+1];

    for(int i=0; i<n; i++){
        cin >> x;
        tab[i] = x;
        t[i+1] = tab[i] + t[i];
    }
    
    cin >> y;

    for(int i=0; i<y; i++){
        cin >> n1 >> n2;

        if(n1>1) {
            cout << t[n2] - t[n1-1] << endl;
        }
        else{
            cout << t[n2] << endl;
        }
    }
}