#include <stdio.h>

int main() {
    int N, n, max1, max2, c;
    scanf("%d", &N);
    scanf("%d %d", &max1, &max2);
    if(max2>max1) {
        c = max1;
        max1 = max2;
        max2 = c;
    }
    
    for(int i = 0; i<(N-2); i++) {
        scanf("%d", &n);
        if(n>max1) {
            max2 = max1;
            max1 = n;
        }
        else if(max2 < n) {
            max2 = n;
        }
    }
    printf("%d %d", max1, max2);
}