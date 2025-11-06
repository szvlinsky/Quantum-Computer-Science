#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = '\0';

    if (strcmp(s1, s2) == 0)
        printf("napisy sa rowne\n");
    else
        printf("napisy nie sa rowne\n");

    return 0;
}
