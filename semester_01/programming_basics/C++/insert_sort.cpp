#include <iostream>
using namespace std;

int main() {
    int n, k, j;
    cin >> n;
    int a[1000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        k = a[i];
        j = i; 

        while (j > 0 && k < a[j - 1]) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = k;
    }

    for (int i = 0; i < n; i++) { 
        cout << a[i] << " ";
    }
    return 0;
}
