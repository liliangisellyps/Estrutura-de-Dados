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
void inverter(){
    char linha[1000];
    
    if(gets(linha)) {
        inverter(linha);
        puts(linha);
    }
    else return;
}
int main(){
    inverter();
}