//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE KARATSUBA PARA MULTIPLICAR DOIS INTEIROS DE 128 BITS

/*

O ALGORITMO DE KARATSUBA É UM EFICIENTE ALGORITMO PARA MULTIPLICAR GRANDES NÚMEROS INTEIROS COM COMPLEXIDADE ASSINTÓTICA O(n^{log(3)/log(2)})
NA MULTIPLICAÇÃO DE INTEIROS DE n BITS, SENDO MAIS EFICIENTE QUE O MÉTODO TRADICIONAL QUE TEM COMPLEXIDADE DE O(n²).

O ALGORITMO DE KARATSUBA É O ALGORITMO MAIS SIMPLES PARA MULTIPLICAÇÃO DE DOIS NÚMEROS INTEIROS BAEADOS EM INTERPOLAÇÃO POLINOMIAL. SEJAM 'A'
E 'B' DOIS INTEIROS DE n BITS E 'R' UM INTEIRO DE NO MÁXIMO (n/2) BITS DE FORMA QUE A=a(1)R+a(0) E B=b(1)R+b(0). O PRODUTO DESTES DOIS
NÚMEROS C=AxB, PODE SER ESCRITO COMO C(R) = c(2)R²+c(1)R+c(0), COM c(2)=a(1)b(1), c(1)=a(1)b(0)+a(0)b(1) e c(0)=a(0)b(0).

A AVALIAÇÃO SIMPLES DOS COEFICIENTES DO POLINÔMIO C(R) EXIGE QUATRO MULTIPLICAÇÕES DE INTEIROS DE (n/2) BITS. ESTE NÚMERO PODE SER REDUZIDO
PARA APENAS TRÊS USANDO UM SEGUNDO CONJUNTO DE COEFICIENTES DEFINIDOS COMO c'(2)=a(1)b(1), c'(0)=a(0)b(0), c'(1)=[a(0)+a(1)][b(0)+b(1)]. É
FÁCIL VERIFICAR QUE c(0)=c'(0), c(2)=c'(2) e c(1)=c'(1)-c'(2)-c'(0). AO CUSTO DE DUAS OPERAÇÕES DE SUBTRAÇÃO, UMA OPERAÇÃO DE MULTIPLICAÇÃO
FOI DESCARTADA.

OPERAÇÕES DE ADIÇÃO E SUBTRAÇÃO POSSUEM COMPLEXIDADE MUITO MENOR, ALÉM  DISSO DEFININDO-SE R=2^k, COM k INTEIRO, O VALOR DE C PODE SER
RECUPERADO USANDO-SE APENAS OPERAÇÕES DE MANIPULAÇÕES DE BITS QUE SÃO REALIZADAS EM TEMPO CONSTANTE O(1). A IDEIA PRINCIPAL DO ALGORÍTMO DE
KARATSUBA É USAR ESTE PROCEDIMENTO RECURSIVAMENTE ATÉ QUE OS MULTIPLICANDOS SEJAM PEQUENOS O SUFICIENTE PARA SE EMPREGAR A TÉCNICA USUAL DE
MULTIPLICAÇÃO.


PARA MAIORES INFORMAÇÕES: https://en.wikipedia.org/wiki/Karatsuba_algorithm

*/


//******************************************************************************************************************************************
//CABEÇALHO
#ifndef KARATSUBA_MULTIPLICATION_H
#define KARATSUBA_MULTIPLICATION_H
#include"int128.h"
#include<stdbool.h>


//CONSTANTES GLOBAIS
const uint32_t KARATSUBA_BOUND=65536; //2^16


//******************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
size_t get_bit_length(__int128_t);
void karatusa_decomposition(__int128_t*, __int128_t*, __int128_t, size_t);
__int128_t karatsuba_multiplication(__int128_t, __int128_t);


//******************************************************************************************************************************************
//FUNÇÕES
//Função que calcula o tamanho da string binária de um inteiro de 128 bits
size_t get_bit_length(__int128_t n){

  //Variáveis locais
  size_t bit_length=0;


  //Procedimentos
    //Loop principal
    while(n>0){
      n>>=1;
      bit_length++;

    }

  //Resultado
  return bit_length;

};

//Função que decompõe um inteiro de 128 bits em duas parcelas com números de bits reduzidos pela metade
void karatusa_decomposition(__int128_t* N1, __int128_t* N0, __int128_t n, size_t bit_half){

  //Variáveis locais
  __int128_t reducer=((__int128_t)1<<bit_half)-1;


  //Resultado
  (*N1)=(n>>bit_half); //N1=n/(2^bit_half)
  (*N0)=(n&reducer); //N0=n mod (2^bit_half)
  
};


//Função que implementa o algoritmo de Karatsuba para multiplicar dois inteiros
__int128_t karatsuba_multiplication(__int128_t a, __int128_t b){

  //Caso base: pelo menos uma das parcelas tem menos de 32 bits (<2^32)
  if(a<KARATSUBA_BOUND || b<KARATSUBA_BOUND) return (a*b);


  //Variáveis locais
  size_t bit_shift=(a>b)?get_bit_length(a):get_bit_length(b);
  size_t bit_half=(bit_shift>>1);
  __int128_t A0, A1, B0, B1, C0, C1, C2, result;
  bool is_negative=false;
  

  //Procedimento
    //Ajuste de sinal
    if((a<0 && b>0) || (a>0 && b<0)) is_negative=true;
    if(a<0) a=(-a); if(b<0) b=(-b);

    //Calculandoa decomposição dos números a serem multiplicados
    karatusa_decomposition(&A1, &A0, a, bit_half);
    karatusa_decomposition(&B1, &B0, b, bit_half);


    //Cálculo dos coeficientes intermediários
    C2=karatsuba_multiplication(A1, B1);
    C0=karatsuba_multiplication(A0, B0);
    C1=karatsuba_multiplication(A0+A1, B0+B1);

    //Cálculo do resultado final
    result=(C2<<(2*bit_half))+((C1-C2-C0)<<bit_half)+C0;


  //Resultado
  if(is_negative) return (-result);
  else return result;


};


//******************************************************************************************************************************************
//FIM DO HEADER
#endif

