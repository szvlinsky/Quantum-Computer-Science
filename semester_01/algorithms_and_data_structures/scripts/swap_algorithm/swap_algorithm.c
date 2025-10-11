#include <stdio.h>

int main() {
    int a = 2;
    int b = 3; //pomijamy operacje początkowe

    printf("Poczatkowo: a = %d, b = %d\n", a, b);

    a = a + b; //2 operacje
    b = a - b; //2 operacje
    a = a - b; //2 operacje

    printf("Po zamianie: a = %d, b = %d\n", a, b);

    return 0; //łącznie 6 operacji
}
