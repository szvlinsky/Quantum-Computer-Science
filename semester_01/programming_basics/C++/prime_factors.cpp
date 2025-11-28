#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x;
    cin >> x;

    for (int i = 2; i*i <= x; i++) {
        
        if (x % i == 0) {
            cout << i << " ";
            
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    
    if (x > 1){
        cout << x << "\n";
    }
    return 0;
}