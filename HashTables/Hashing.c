#include <stdio.h>
#include "HashTable.h"
#include "HashTable.c"

// metodo da divisão ou da congruência linear
// consiste em calcular o resto da divisão do valor
// inteiro que representa o elemento 
// pelo tamanho da tabela

// a operação E bit-a-bit com o valor etc elimina o
// bit e sinal do valor da chave
// evita o risco de ocorrer um overflow e 
// obtermos um número negativo
int chaveDivisao(int chave, int tableSize){
    return (chave & 0x7fffffff) % tableSize;
}

// método da multipliação
// usa um valor "A", "0<A<1",
// para multiplicar o valor da "chave" que representa
// o elemento. em seguida, a parte fracionaria resultante
// eh multiplicada pelo tam da tabela para calcular a 
// posição do elemento

int chaveMultiplicacao(int chave, int tableSize){
    float A = 0.618033987; // constante 0<A<1
    float val = chave * A;
    val = val - (int) val;
    return (int) (tableSize * val);
}

// metodo da dobra

int chaveDobra(int chave, int tableSize){
    int num_bits = 10;
    int parte1 = chave >> num_bits;
    int parte2 = chave & (tableSize-1);
    return (parte1 ^ parte2);
}

// tratando uma string como chave
// calcular um valor numerico a partir dos valores ascii dos 
// caracteres
// deve considerar a posição da letra
int chaveString(char *str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i<tam; i++)
        valor = 31 * valor + (int) str[i];
    return valor;
}