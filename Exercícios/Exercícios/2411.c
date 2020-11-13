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
int raizDigital(int x){
    int y=x, z=0;
    if(x < 10){
        return x;
    } else {
        while(y != 0){
           z += y%10;
           y /= 10;
        }
        raizDigital(z);
    }

}
int main(){
    int n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        int a, b, cont=0, j=0;
        scanf("%d%d", &a, &b);
        while(1){
            if(raizDigital(j) == b){
                cont++;
                DBG printf("%d %d %d\n", cont, b, j);
                if(cont == a) {
                    printf("%d\n", j);
                    break;
                }
            }
            j++;
        }
    }
}