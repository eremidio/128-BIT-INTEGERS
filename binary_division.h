//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA ROTINAS PARA O CÁLCULO DE DIVISÃO DE INTEIROS DE 128 BITS



//*****************************************************************************************************************************************
//CABEÇALHO
#ifndef BINARY_DIVISION_H
#define BINARY_DIVISION_H
#include"int128.h"
#include<assert.h>

//*****************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
__int128_t binary_division(__int128_t, __int128_t);


//*****************************************************************************************************************************************
//FUNÇÕES

//Função que calcula o quociente ou limitante inferior deste valor para dois inteiros de 128 bits
__int128_t binary_division(__int128_t x, __int128_t n){

  //Restriçao
  assert(x>=n);


  //Variáveis locais
  __int128_t m=n;
  __int128_t t=(m<<1);
  __int128_t a=0, c=0;
  int b=0, j; 


  //Procedimentos 
    //Cálculo dos parâmetros m e b usados no algoritmo
    while(1){
      if(m<=x && x<=t) break;
      b++;
      m<<=1;
      t<<=1;
    };


    //Loop principal
    for(j=0; j<=b; ++j){
      c<<=1;
      a=x-m;

      if(a>=0){
        c++;
        x=a;
      };

      m>>=1;

    };


  //Resultado 
  return c;

};

//*****************************************************************************************************************************************
//FIM DO HEADER
#endif
