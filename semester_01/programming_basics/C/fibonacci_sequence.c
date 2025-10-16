#include <stdio.h>

int main() {
	
int n, a=0, b=1;
scanf("%d", &n);

if (n==0) {
	printf("%d", 0);
} 
else if(n==1) {	
	printf("%d", 1);
} 
else {
    for(int i=0; i<n; i++) {
	b = a+b;
	a = b-a;
    }
	printf("%d", a);
}

return 0;
}