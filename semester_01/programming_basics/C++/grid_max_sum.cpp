#include <iostream>
using namespace std;

int **f;
int A, B;

int max_sum(int x, int y) {
    int best = -1;
    
    if (x == A && y == B) {
        return f[y][x];
    }

    if (x + 1 <= A) {
        int t = max_sum(x + 1, y);
        
        if (t > best) {
            best = t;
        }
    }

    if (y + 1 <= B) {
        int t = max_sum(x, y + 1);
        
        if (t > best) {
            best = t;
        }
    }
    return f[y][x] + best;
}

int main() {
    cin >> A >> B;

    f = new int *[B + 1];
    for (int i = 0; i <= B; i++) {
        f[i] = new int[A + 1];
    }

    for (int i = 0; i <= B; i++) {
        for (int j = 0; j <= A; j++) {
            cin >> f[i][j];
        }
    }

    cout << max_sum(0, 0) << endl;
}