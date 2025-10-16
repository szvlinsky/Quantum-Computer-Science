#include <stdio.h>

int main() {
    int N, n, sum = 0;
    scanf("%d", &N);
    
    for(int i = 0; i<N; i++) {
        scanf("%d", &n);
        sum = sum + n;    
    }
    printf("%d", sum);
    return 0;
}