#include <stdio.h>
#include <string.h>

int main() {
    int l = 0, c = 0;
    char s[100];
    fgets(s, sizeof(s), stdin);
    
    for (int i = 0; i < strlen(s); i++) {
        if ((s[i] >= 'A' && s[i] <= 'Z') || 
        (s[i] >= 'a' && s[i] <= 'z')){
            l++;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            c++;
        }
    }
        printf("%d litery\n", l);
        printf("%d cyfry\n", c);
    return 0;
}