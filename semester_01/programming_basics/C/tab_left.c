#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    int ** tab;
    int ** trans;
    
    scanf("%d %d", &N, &M);
    tab = malloc(N * sizeof(int *));
    
    for(int i = 0; i<N; i++){
        tab[i] = malloc(M * sizeof(int));
        for(int j = 0; j<M; j++) {
            scanf("%d", &tab[i][j]);
        }
    }
    
    trans = malloc(M * sizeof(int *));
    for(int i = 0; i<M; i++) {
            trans[i] = malloc(N * sizeof(int));
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            trans[j][i] = tab[i][M - 1 - j];
        }
    }
    for(int i = 0; i<M; i++) {
        for(int j = 0; j<N; j++) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }
    return 0;
    
}