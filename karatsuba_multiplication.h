//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE KARATSUBA PARA MULTIPLICAR DOIS INTEIROS DE 128 BITS

/*
O ALGORITMO DE KARATSUBA É UM EFICIENTE ALGORITMO PARA MULTIPLICAR GRANDES NÚMEROS INTEIROS COM COMPLEXIDADE O(ln(N)^(ln(3)/ln(2))).
PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Karatsuba_algorithm

*/


//******************************************************************************************************************************************
//CABEÇALHO
#ifndef KARATSUBA_MULTIPLICATION_H
#define KARATSUBA_MULTIPLICATION_H
#include"int128.h"


//******************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void split_number(__int128_t*, __int128_t*, __int128_t, __int128_t);
__int128_t karatsuba_multiplication(__int128_t, __int128_t, __int128_t);


//******************************************************************************************************************************************
//FUNÇÕES

//Função que separa um número de em duas parcelas contendo seu digitos mais e menos signficativos
void split_number(__int128_t* low, __int128_t* high, __int128_t number, __int128_t B){

 //Resultado
 (*low)=(number%B);
 (*high)=(number/B);
                                                                                     };

//Função que implementa o algoritmo de Karatsuba para multiplicar dois inteiros
__int128_t karatsuba_multiplication(__int128_t base, __int128_t first, __int128_t second){

 //Caso trivial: as parcelas são menores que o elemento usado para redução da string númerica 
 if(first<=base || second<=base)
  return second*first;

 //Caso: aplicação recursiva do algoritmo de redução de Karatsuba

  //Variáveis locais
  __int128_t low1, high1, low2, high2;
  __int128_t B=1, m=0;
  __int128_t z0=0, z1=0, z2=0;
  
  


  //Procedimentos

  //Estimando a ordem de grandeza do fator de redução
  while(B<first && B<second){
   m++;
   B*=base;
                            };

   B/=base;
   m/=2;

  //Separando os números a serem multiplicados em duas parcelas contendo seu digitos mais e menos signficativos
  split_number(&low1, &high1, first, B);
  split_number(&low2, &high2, second, B);


  //TESTE USE UM /**/ APÓS O MESMO
  /*printf128(low1); printf128(high1); printf128(low2); printf128(high2); printf128(m); printf128(B);*/

    

  //Calculando os produtos intermediários
  z0 = karatsuba_multiplication(base, low1, low2);
  z1 = karatsuba_multiplication(base, (low1 + high1), (low2 + high2));
  z2 = karatsuba_multiplication(base, high1, high2);

  //TESTE USE UM /**/ APÓS O MESMO
  /*printf128(z0); printf128(z1); printf128(z2);*/  

  //Resultado
  return ((z2*B*B)+((z1-z2-z0)*B)+z0);
 
                                                                                         };


//******************************************************************************************************************************************
//FIM DO HEADER
#endif

