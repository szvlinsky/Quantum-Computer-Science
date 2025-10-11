#include <stdio.h>

int main() {
    int a = 2;
    int b = 3; //pomijamy operacje początkowe
    
    a = a + b; //2 operacje
    b = a - b; //2 operacje
    a = a - b; //2 operacje

    return 0; //łącznie 6 operacji
}
