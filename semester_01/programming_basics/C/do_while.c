#include <stdio.h>

int main() {
    int x,y;
    scanf("%d", &x);
    printf("%d\n", x);
    
    if(x>40) {
    } else {
        do {
            scanf("%d", &y);
            x = x + y;
            printf("%d\n", x);
        } 
    while (x < 40);
    }
    return 0;
}