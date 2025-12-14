#include <stdio.h>

int main() {
    int a = 2;
    int b = 3; //pomijamy operacje początkowe
    printf("%d%d ",a,b);
    
    a = a + b; //2 operacje (przypisanie i dodawanie)
    b = a - b; //2 operacje
    a = a - b; //2 operacje
    
    printf("%d%d",a,b);
    return a, b; // algorytm zamiany łącznie 6 operacji
}