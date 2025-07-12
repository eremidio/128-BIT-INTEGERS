//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO mod_bin_exponentiation_gmp128.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o mod_bin_exponentiation_gmp128 mod_bin_exponentiation_gmp128.c -lm -lgmp


//Cabeçalho
#include"mod_bin_exponentiation_gmp128.h"
#include<stdio.h>


//Função principal
int main(){

  //Variáveis locais
  __int128_t a, b, m, powmod;
  char number_string1[45], number_string2[45], number_string3[45];


  //Procedimento
    //Recebendo input do usuário
    printf("Digite um número: ");
    scanf("%s", number_string1);
    a=scanf128(number_string1);

    printf("Digite um número: ");
    scanf("%s", number_string2);
    b=scanf128(number_string2);

    printf("Digite um número: ");
    scanf("%s", number_string3);
    m=scanf128(number_string3);

    //Teste das funções de exponenciação modular
    powmod=mod_bin_exponentiation_gmp128(a, b, m);
    printf("Resultado da exponencial modular: "); printf128(powmod);


  //Finalizando a aplicação
  return 0;

}
 
