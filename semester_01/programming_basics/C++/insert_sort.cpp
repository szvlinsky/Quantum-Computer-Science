#include <iostream>
using namespace std;

int main() {
    int n, k, j;
    cin >> n;
    int a[1000];

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 1; i < n; ++i) {
        k = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
