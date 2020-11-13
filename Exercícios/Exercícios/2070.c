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

li soma(char* n){
    if(strlen(n) == 0) return 0;
    else {
        int i = n[0]-'0';
        if(i%2 == 0){
            return i*2*strlen(n) + soma(&n[1]);
        } else {
            return i*3*strlen(n) + soma(&n[1]);
        }
    }
}

int main(){
    char n[10];
    scanf("%s", n);
    while(strcmp(n, "0") != 0){
        printf("%ld\n", soma(n));
        scanf("%s", n);
    }
}