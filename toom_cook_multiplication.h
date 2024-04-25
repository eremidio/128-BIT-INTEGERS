//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO DE TOOM-COOK PARA MULTIPLICAR DOIS INTEIROS DE 128 BITS

/*
O ALGORITMODE TOOM É UMA GENERALIZAZÇÃO DO ALGORITMO DE KARATSUBA QUE TAMBÉM SE FUNDAMENTA NA IDEIA DE REPRESENTAR UM INTEIRO SOB A FORMA DE UM POLINÔMIO
x(t)=a(0)+a(1)t+a(2)t²+.... USANDO A OPERAÇÃO DE MULTIPLICAÇÃO DE POLINÔMIOS PODEMOS COMPUTAR OS PRODUTOS DE PARCELAS MENORES E COMBINAR OS RESULTADOS DAS
PARCELAS PARA OBTER O RESULTADO FINAL. OS COEFICIENTES DE UM POLINÔMIO DE GRAU n PODEM SER DETERMINADOS RESOLVENDO UM SISTEMA DE EQUAÇÕES LINEARES USANDO O 
VALOR DO POLINÔMIO EM (n+1) PONTOS DISTINTOS.

É UM EFICIENTE MÉTODO DE MULTPLICAÇÃO PARA VALORES INTEREMEDIÁRIOS CONTENDO DA ORDEM DE 10^5-10^7 DIGITOS. PARA VALORES DE MAGNITUDES MAIORES (ACIMA DE 10^7
DÍGITOS) TÉCNICAS MAIS SOFISTICADAS BASEADAS EM TRANSFORMADA DE FOURIER DISCRETA SÃO MAIS EFICIENTES.

VAMOS IMPLEMENETAR A VARIANTE DO ALGORITMO CONHECIUDA COMO TOOM-3 QUE USA POLINÔMIOS DO SEGUNDO GRAU.

PARA MAIORES INFORMAÇÕES: Prime Numbers A computational Perspective, by Richard Crandall and Carl Pomerance
                          https://en.wikipedia.org/wiki/Toom–Cook_multiplication

*/

//*****************************************************************************************************************************************************************
//CABEÇALHO
#ifndef TOOM_COOK_MULTIPLICATION_H
#define TOOM_COOK_MULTIPLICATION_H
#include"int128.h"

//*****************************************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void split_number_tc(__int128_t, __int128_t,__int128_t[]);
__int128_t toom_cook3(__int128_t, __int128_t, __int128_t);

//*****************************************************************************************************************************************************************
//FUNÇÕES
//Função que separa um inteiro em coeficientes de um polinômio de 2º grau n=a(0)+a(1)t+a(2)t²
void split_number_tc(__int128_t number, __int128_t base,__int128_t base_coefficients[]){

 //Variáveis locais
 __int128_t B=(base*base);

 //Procedimentos
  //Calculando os coeficientes da representação de um inteiro em uma dada base
  base_coefficients[2]=number/B;
  number%=B;
  base_coefficients[1]=number/base;
  number%=base;
  base_coefficients[0]=number;
  
                                                                                      };


//Função que implementa o algoritmo de Toom-Cook para multiplicar dois inteiros de 128 bits
__int128_t toom_cook3(__int128_t base,__int128_t first, __int128_t second){

 //Caso base
 if(first<=base || second<=base)
  return (first*second);

 //Variáveis locais
 __int128_t first_coefficients[3], second_coefficients[3];
 __int128_t result=0;
 __int128_t p0, q0, p1, q1, p2, q2, p3, q3, p4, q4;
 __int128_t r0, r1, r2, r3, r4;

 
 //Procedimentos
  //Calculando os coeficientes das duas parcelas na respectiva base
  split_number_tc(first, base, first_coefficients);
  split_number_tc(second, base, second_coefficients); 

    //TESTE  USE UM /**/ APÓS O MESMO
    /*for(int c1=0; c1<3; c1++){
     printf128(first_coefficients[c1]);
     printf128(second_coefficients[c1]);
                             };*/

  //Cálculos dos coeficientes dos polinômios usando os pontos de interpolação: 0, 1, -1, -2, ∞
  p0=first_coefficients[0];
  p1=first_coefficients[0]+first_coefficients[1]+first_coefficients[2];
  p2=first_coefficients[0]-first_coefficients[1]+first_coefficients[2];
  p3=first_coefficients[0]-(2*first_coefficients[1])+(4*first_coefficients[2]);
  p4=first_coefficients[2];

  q0=second_coefficients[0];
  q1=second_coefficients[0]+second_coefficients[1]+second_coefficients[2];
  q2=second_coefficients[0]-second_coefficients[1]+second_coefficients[2];
  q3=second_coefficients[0]-(2*second_coefficients[1])+(4*second_coefficients[2]);
  q4=second_coefficients[2];

    //TESTE  USE UM /**/ APÓS O MESMO
    /*printf128(p0); printf128(p1); printf128(p2); printf128(p3); printf128(p4); 
    printf128(q0); printf128(q1); printf128(q2); printf128(q3); printf128(q4); */


  //Cálculo dos coeficientes do polinômio que expressa o produto da multplicação na base em questão
  r0=toom_cook3(base, p0, q0); //0
  r1=toom_cook3(base, p1, q2); //1
  r2=toom_cook3(base, p2, q2); //-1
  r3=toom_cook3(base, p3, q3); //-2
  r4=toom_cook3(base, p4, q4); // ∞



  r0=r0;
  r4=r4;
  r3=(r3-r1)/3;
  r1=(r1-r2)/2;
  r2=r2-r0;
  r3=((r2-r3)/2)+(2*r4);
  r2=(r2+r1-r4);
  r1=r1-r3;

    //TESTE  USE UM /**/ APÓS O MESMO
    /*printf128(r0); printf128(r1); printf128(r2); printf128(r3); printf128(r4);*/ 

  //Cálculo do resultado final
  result+=r0; 
  result+=(r1*base); base*=base;
  result+=(r2*base); base*=base;
  result+=(r3*base); base*=base;
  result+=(r4*base);
  
  //Resultado
  return  result;

                                                                       };




//*****************************************************************************************************************************************************************
//FIM DO HEADER
#endif
