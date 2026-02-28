//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O ALGORITMO TOOM-COOK 3 PARA MULTIPLICAR NÚMEROS INTEIROS DE 128 BITS

/*

O ALGORITMO DE TOOM-COOK PARA MULTIPLICAÇÃO DE NÚMEROS INTEIROS É UMA GENERALIZAÇÃO DO MÉTODO DE KARATSUBA QUE EMPREGA EFICIENTES
ROTINAS DE MULTIPLICAÇÃO DE POLINÔMIOS PARA REDUZIR O TAMANHO DOS NÚMEROS SENDO MULTIPLICADOS AO CUSTO DE OPERAÇÕES ADICIONAIS DE 
ADIÇÃO E SUBTRAÇÃO. SEJAM 'A' E 'B' SÃO DOIS NÚMEROS A SEREM MULTIPLICADOS, DECOMPONDO ESTES NÚMEROS EM UMA BASE R PODEMOS
EXPRESSÁ-LOS COMO UM POLINÔMIO DE GRAU 'd': A=a(d)R^d+a(d-1)R^(d-1)+...+a(1)d+a(0) E B=b(d)R^d+b(d-1)R^(d-1)+...+b(1)d+b(0). O
RESULTADO DA MULTIPLICAÇÃO PODE SER EXPRESSO COMO C=c(2d)R^(2d)+c(2d-1)R^(2d-1)+...+c(1)d+c(0), ONDE PARA UM DADO COEFICIENTE
VALE A RELAÇÃO: c(k)=Σa(i)b(j), COM k=i+j.

A IDEIA PRINCIPAL DO ALGORITMO É USAR UM SEGUNDO CONJUNTO DE COEFICIENTES EXPRESSO COMO UMA COMBINAÇÃO LINEAR DOS COEFICIENTES
DO POLINÔMIO. AVALIANDO-SE O POLINÔMIO RESULTANTE EM UM CONJUNTO DE PONTOS ESCOLHIDOS DE FORMA APROPRIADA É POSSÍVEL COMPUTAR SEU
VALOR POR MEIO DE UM NÚMERO REDUZIDO DE MULTIPLICAÇÕES DE NÚMEROS DE TAMANHO (STRING NÚMERICA) REDUZIDO POR UM FATOR d, AO CUSTO
DE OPERAÇÕES EXTRAS DE ADIÇÃO E SUBTRAÇÃO.

SEJA, POR EXEMPLO, d=3 DE FORMA QUE A=a(2)R²+a(1)R+a(0) E B=b(2)R²+b(1)R+b(0). TEMOS QUE C=AxB, PODE SER EXPRESSO COMO
C=c(4)R⁴+c(3)R³+c(2)R²+c(1)R+c(0), COM c(4)=a(2)b(2), c(3)=a(2)b(1)+a(1)b(2), c(2)=a(2)b(0)+a(0)b(2)+a(1)b(2),
c(1)=a(0)b(1)+a(1)b(0), c(0)=a(0)b(0).

DEFININDO UM SEGUNDO CONJUNTO DE COEFICIENTES c' AVALIADO NOS PONTOS k= ∞, 0, 1, -1, -2, PODEMOS ESCREVER:

c'(∞) = c(4) = a(2)b(2)
c'(0) = c(0) = a(0)b(0)
c'(1) = c(4)+c(3)+c(2)+c(1)+c(0) = [a(2)+a(1)+a(0)][b(2)+b(1)+b(0)]
c'(-1) = c(4)-c(3)+c(2)-c(1)+c(0) = [a(2)-a(1)+a(0)][b(2)-b(1)+b(0)]
c'(-2) = 16c(4)-8c(3)+4c(2)-2c(1)+c(0) = [4a(2)-2a(1)+a(0)][4b(2)-2b(1)+b(0)]

(OS COEFICIENTES DAS RELAÇÕES LINEARES SÃO DADOS POR 1, k, k², k³, ...; COM O CASO k=∞ CONSIDERADO ASSINTOTICAMENTE).

O SISTEMA DE EQUAÇÕES LINEARES ACIMA PODE SER EXPRESSO EM NOTAÇÃO MATRICIAL COMO [C'] = [M]x[C], COM

            C'=|c'(∞) |; C= |c(4)| ; M=|1   0   0   0   0|
               |c'(0) |     |c(3)|     |0   0   0   0   1|
               |c'(1) |     |c(2)|     |1   1   1   1   1|
               |c'(-1)|     |c(1)|     |1  -1   1  -1   1|
               |c'(-2)|     |c(0)|     |16 -8   4  -2   1|  

A MATRIZ M PODE SER INVERTIDA (SEU DETERMINANTE É NÃO NULO) DE FORMA QUE [C] = [M⁻¹]x[C'], ESTE CÁLCULO NOS PERMITE OBTER AS SEGUINTES
IDENTIDADES:

c(4) = c'(∞)
c(3) = [12c'(∞)-3c'(0)+c'(1)+3c'(-1)-c'(-2)]/6
c(2) = [(-2)c'(∞)-2c'(0)+c'(1)+c'(-1)]/2
c(1) = [(-12)c'(∞)+3c'(0)+2c'(1)-6c'(-1)+c'(-2)]/6
c(0) = c'(0) 

DESTA FORMA O RESULTADO FINAL É OBTIDO POR MEIO DA MULTIPLICAÇÃO DE MÚMEROS CUJOS DÍGITOS SÃO REDUZIDOS POR UM FATOR 3. ESTE É O
ALGORITMO TOOM-COOK 3. AS FÓRMULAS ACIMA PODEM SER GENERALIZADAS PARA UM POLINÕMIO DE GRAU QUALQUER. O ALGORITMO PODE SER EMPREGADO
RECURSIVAMENTE ATÉ QUE OS NÚMEROS A SEREM MULTIPLICADOS TENHAM UM TAMANHO PEQUENO O SUFICIENTE PARA EMPREGAR O ALGORITMO  TRADICIONAL
(CUJA COMPLEXIDADE É DE O(n²) PARA STRINGS DE n BITS). O ALGORITMO DE TOOM-COOK k TEM COMPLEXIDADE  O(n^{log(2k-1)/log(k)}) PARA
MULTIPLICAR NÚMEROS DE n BITS.


O MÉTODO DE TRANSFORMADA DE FOURIER RÁPIDA GENERALIZA ESTE PROCEDIMENTO POR MEIO DA AVALIAÇÃO DE POLINÔMIOS EM k-RAÍZES DA UNIDADE
ζ(k; N)=ω(N)^k=e^(2πik/N) (É POSSÍVEL USAR APENAS NÚMEROS INTEIROS EM MANIPULAÇÕES ARITMÉTICAS DE RAÍZES DA UNIDADE).


PARA MAIORES INFORMAÇÕES: Computational Number Theory by Abhijit Das

*/


//*******************************************************************************************************
//CABEÇALHO
#ifndef TOOM_COOK_MULTIPLICATION_H
#define TOOM_COOK_MULTIPLICATION_H
#include"int128.h"
#include<stdbool.h>


//CONSTANTES GLOBAIS
const uint32_t TOOM_COOK_BOUND=65536;//2^16


//*******************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
size_t get_bit_length(__int128_t);
void toom_cook_decomposition(__int128_t*, __int128_t*, __int128_t*, __int128_t, size_t);
__int128_t toom_cook_multiplication(__int128_t, __int128_t);


//*******************************************************************************************************
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


//Função que decompõe um inteiro em parcelas com números reduzidos de bits
void toom_cook_decomposition(__int128_t* N2, __int128_t* N1, __int128_t* N0, __int128_t n, size_t bit_third){

  //Variáveis locais
  __int128_t reducer0=((__int128_t)1<<bit_third)-1;
  __int128_t reducer1=((__int128_t)1<<(2*bit_third))-1;


  //Resultado
  (*N2)=(n>>(2*bit_third));//N2=n/(2^{2k})
  (*N1)= ((n&reducer1)>>bit_third);//N1=(n mod 2^{2k})/(2^k)
  (*N0)= (n&reducer0);//N0= n mod 2^{k}

};


//Função que implementa o alçgoritmo de Toom-Cook para multiplicação de números inteiros
__int128_t toom_cook_multiplication(__int128_t a, __int128_t b){

  //Caso base: pelo menos uma das parcelas tem menos de 16 bits (<2^32)
  if(a<TOOM_COOK_BOUND || b<TOOM_COOK_BOUND) return (a*b);


  //Variáveis locais
  size_t bit_shift=(a>b)?get_bit_length(a):get_bit_length(b);
  size_t bit_third=((bit_shift+2)/3);
  __int128_t A0, A1, A2, B0, B1, B2;
  __int128_t C0, C1, C2, C3, C4;
  __int128_t c0, c1, c2, c3, c4;
  __int128_t result;

  bool is_negative=false;
  

  //Procedimento
    //Ajuste de sinal
    if((a<0 && b>0) || (a>0 && b<0)) is_negative=true;
    if(a<0) a=(-a); if(b<0) b=(-b);

    //Calculando a decomposição dos números a serem multiplicados
    toom_cook_decomposition(&A2, &A1, &A0, a, bit_third);
    toom_cook_decomposition(&B2, &B1, &B0, b, bit_third);


    //Calculando os coeficientes intermediários usados no cálculo
    c4=toom_cook_multiplication(A2, B2);//c'(∞)
    c3=toom_cook_multiplication(A0, B0);//c'(0)
    c2=toom_cook_multiplication(A0+A1+A2, B0+B1+B2);//c'(1)
    c1=toom_cook_multiplication(A0-A1+A2, B0-B1+B2);//c'(-1)
    c0=toom_cook_multiplication( ((A2<<2)-(A1<<1)+A0), ((B2<<2)-(B1<<1)+B0) );//c'(-2)

    C4 = c4;
    C3 = (12*c4 - 3*c3 + c2 + 3*c1 - c0) / 6;
    C2 = ((-2*c4) - 2*c3 + c2 + c1) / 2;
    C1 = ((-12*c4) + 3*c3 + 2*c2 - 6*c1 + c0) / 6;
    C0 = c3;

    //Cálculo do resultado final
    result = (C4<<(4*bit_third))+(C3<<(3*bit_third))+(C2<<(2*bit_third))+(C1<<bit_third)+C0;


  //Resultado
  if(is_negative) return (-result);
  else return result;

};


//*******************************************************************************************************
//FIM DO HEADER
#endif
