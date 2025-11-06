#include <stdio.h>
#include <string.h>

int main() {
    int sum = 0;
    char s1[10];
    char s2[100];
    
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';

    for (int i = 0; i < strlen(s2); i++) {
        if (s2[i] >= 'a' && s2[i] <= 'z') {
            if (s2[i] == s1[0]) {
                sum++;
            }
        }
    }

    printf("%d", sum);
    return 0;
}
