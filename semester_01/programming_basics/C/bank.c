#include <stdio.h>
#include <string.h>

int main() {
    int D, k;
    int count[5];
    int val[] = {10, 20, 50, 100, 200};
    int n = 5;
    
    scanf("%d", &D);

    for (int t = 0; t < D; t++) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &count[i]);
        }
        scanf("%d", &k);
        int sums[k + 1];

        for (int s = 1; s <= k; s++) {
            sums[s] = -1; } sums[0] = 0;
        
        for (int i = 0; i < n; i++) {
            int v = val[i]; // wartość aktualnego nominału
            int c = count[i]; // liczba dostępnych monet

            for (int s = 0; s <= k; s++) {
                if (sums[s] >= 0) {
                    sums[s] = c;
                }
                else {
                    if (s >= v && sums[s - v] > 0) {
                        sums[s] = sums[s - v] - 1;
                    }
                    else {
                        sums[s] = -1;
                    }
                }
            }
        }
        if (sums[k] >= 0) {
            printf("TAK\n");
        }
        else {
            printf("NIE\n");
        }
    }
    return 0;
}
