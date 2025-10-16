#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    int *tab = malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &tab[i]);
        sum = sum + tab[i];
    }

    printf("%d", sum);
    return 0;
}