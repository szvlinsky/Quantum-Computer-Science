#include <iostream>
using namespace std;

int main() {
    int x, a;
    unsigned long long b,c;
    cin >> x;

    for(int i = 0; i<x;i++) {
        cin >> a;
        c=0;
        b=7;

        for(int i=1; i<= a; i++) {
            if(i%2==1) {
                c = c + b;
                b = b * 5;
            }
            else if(i%2==0) {
                c = c + b;
                b = b * 3;
            }
        }
        cout << c << " " << b << endl;
    }
}