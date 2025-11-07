#include <stdio.h>

int main() {
    int x, k, l, c;

    while(1) {
        scanf("%d", &x);
        k = l = c = 0;
        
        if (x == 0) {
            break;
        }

        while (x != 1) {
            if (x % 2 == 0) {
                x = x / 2;
                k++;
            } else {
                x = 3 * x + 1;
                l++;
            }
            c++;
        }
        
        if (c <= 15) {
            printf("TAK %d %d\n", k, l);
        }
        else {
            printf("NIE\n");
        }
    }
    return 0;
}
