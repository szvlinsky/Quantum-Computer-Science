#include <iostream>
using namespace std;

void quicksort(int a[], int left, int right) {
    int i = left;
    int j = right;
    int pivot = a[(left + right) / 2];

    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;

        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quicksort(a, left, j);
    }
    if (i < right){
        quicksort(a, i, right);
    }
}

int main() {
    int n;
    cin >> n;
    int a[1000];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quicksort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}