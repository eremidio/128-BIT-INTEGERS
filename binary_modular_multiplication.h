//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA A OPERAÇÃO DE MULTIPLICAÇÃO A MENOS DE UMA CONGRUÊNCIA PARA INTEIROS DE 128 BITS



//****************************************************************************************************************************************
//CABEÇALHO
#ifndef BINARY_MODULAR_MULTIPLICATION_H
#define BINARY_MODULAR_MULTIPLICATION_H
#include"int128.h"
#include<assert.h>

//****************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
__int128_t binary_modular_multiplication(__int128_t,__int128_t, __int128_t);


//****************************************************************************************************************************************
//FUNÇÕES
__int128_t binary_modular_multiplication(__int128_t a,__int128_t b, __int128_t m){
//Restrição
assert(a<m && b<m);


//Variáveis locais
short * bit_array=NULL;
short bit_size=0;
__int128_t s=0;


//Procedimentos
//Extraindo os bits da primeira parcela da multiplicação
while(a>0){

//Testando a paridade do bit
if((a&1)){

bit_size++;
bit_array=(short*)realloc(bit_array, bit_size*sizeof(short));
bit_array[bit_size-1]=1;

         };

if(!(a&1)){

bit_size++;
bit_array=(short*)realloc(bit_array, bit_size*sizeof(short));
bit_array[bit_size-1]=0;

          };

//Ajustando variáveis para a próxima iteração
a>>=1;

          };


//Calculando o resultado da multiplicação modular
for(short i=bit_size; i>=0; --i){
s<<=1;

if(s>=m)
s-=m;

if(bit_array[i]==1)
s+=b;

if(s>=m)
s-=m;
                                };

//Limpando o cachê de memória e retornando o resultado da função
free(bit_array);
return s;

                                                                                 };


//****************************************************************************************************************************************
//FIM DO CABEÇALHO
#endif
