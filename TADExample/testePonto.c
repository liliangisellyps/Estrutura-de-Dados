#include <stdio.h>
#include <stdlib.h>
#include "POnto.h"

int main(){
    float d;
    Ponto *p, *q;
    
    p = pto_cria(10,21);
    q = pto_cria(7, 25);

    d = pto_distancia(p,q);
    printf("Distância entre pontos: %f\n", d);
    
    pto_libera(q);
    pto_libera(p);

    system("pause");
    return 0;
}