#include <stdio.h>

int main() {
    int tab[6][6];
    int i=0, j=0;
    
    while( i<6 && j<6){
        tab[i][j] = 6*i+j+1;
        printf("%d ",tab[i][j]);
        j++;
        if( j == 6 )
        {
            i++; j=0;
            printf("\n");
        }
    }
    return 0;
}