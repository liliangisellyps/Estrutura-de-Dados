#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int mdc(int a, int b){
  return (b == 0) ? a :  mdc(b, b%a);
}
int main() {
    int n, i, a, b;
    scanf("%d", &n);
    for(i=0; i<n; i++){
      scanf("%d %d", &a, &b);
      printf("MDC(%d, %d) = %d", a, b, mdc(a, b));
    }
	return 0;
}