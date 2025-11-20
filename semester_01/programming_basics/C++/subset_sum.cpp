#include <iostream>
using namespace std;

void sums(int *tab, int sum, int size, int iterator, int *possible) {
    if (iterator == size) {
        possible[sum] = 1;
        return;
    }

    sums(tab, sum, size, iterator + 1, possible);
    sums(tab, sum + tab[iterator], size, iterator + 1, possible);
}

int main() {
    int n;
    cin >> n;
    
    int max_sum = 0;
    int *tab = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> tab[i];
        max_sum += tab[i];
    }
    
    int *possible = new int[max_sum + 1];
    
    for (int i = 0; i <= max_sum; i++) {
        possible[i] = 0;
    }
    
    sums(tab, 0, n, 0, possible);

    for (int i = 0; i <= max_sum; i++) {
        if (possible[i]) {
            cout << i << " ";
        }
    }
    return 0;
}
