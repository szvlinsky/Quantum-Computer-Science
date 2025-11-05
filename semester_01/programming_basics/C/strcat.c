#include <stdio.h>
#include <string.h>

int main() {
    char n1[30], n2[30];
    scanf("%s", n1);
    scanf("%s", n2);
    
    strcat(n1, n2);

    printf("%s", n1);

    return 0;
}