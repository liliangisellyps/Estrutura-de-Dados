#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int decrementa(int n, int i){
    if(i<10) {
        if(i%2 == 0) printf("%d", n-4);
        else printf("%d", n-3);
    } else decrementa(n, i/10);
}
int main() {
    int n;
    scanf("%d", &n);
    decrementa(n, n);
	return 0;
}