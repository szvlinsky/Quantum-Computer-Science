#include <stdio.h>

int main() {
    int x,y,z,v;
    scanf("%d", &x);
    scanf("%d", &y);
    z = x;
    v = x+1;
    
    while(y>z+1 && y>v+1){
        if(x%2 == 0) {
            z = z + 2;
            printf("%d \n", z);
        }
        else {
            printf("%d \n", v);
            v = v + 2;
        }
    }
    return 0;
    
}