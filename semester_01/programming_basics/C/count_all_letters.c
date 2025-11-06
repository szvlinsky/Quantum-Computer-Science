#include <stdio.h>

int main() {
    char s[1000];
    int c[26] = {0};
    fgets(s, sizeof(s), stdin);
    
    for(int i = 0; s[i] != '\0'; i++) {
        char x = s[i];
        
        if(x >= 'a' && x<= 'z') {
            c[x - 'a']++;
        }
    }
    
    for(int i = 0; i < 26; i++) {
        if(c[i] > 0) {
            printf("%c: %d \n",'a' + i, c[i]);
        }
    }
    return 0;
}