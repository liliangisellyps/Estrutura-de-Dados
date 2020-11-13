#include<stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#define DBG if(0)
typedef long long int lli;
typedef unsigned long long int ulli;
typedef long int li;
typedef struct a A;
struct a {
};

int ContaDigitosPares(int n){
    if (n < 10){
        if (n%2 == 0) return 1;
        else return 0;
    } else {
        if (n%2 == 0) return 1 + ContaDigitosPares(n/10);
        else return 0 + ContaDigitosPares(n/10);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", ContaDigitosPares(n));
}