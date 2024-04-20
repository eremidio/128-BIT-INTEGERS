//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO karatsuba_multiplication.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o karatsuba_multiplication karatsuba_multiplication.c 


//Cabeçalho
#include"karatsuba_multiplication.h"

//Função principal
int main(){

 //Variáveis locais
 char number_string1[40], number_string2[40], number_string3[40];
 __int128_t first, second, base , result;


 //Procedimentos

 //Recebendo input
 printf("Primeira parcela: ");
 scanf("%s", number_string1);


 printf("Segunda parcela: ");
 scanf("%s", number_string2);

 printf("Base de redução: ");
 scanf("%s", number_string3);

 first=scanf128(number_string1);
 second=scanf128(number_string2);
 base=scanf128(number_string3);

 //Calculando o produto das duas parcelas
 result=karatsuba_multiplication(base, first, second);

 printf("Resultado: ");
 printf128(result);

 
 //Finalizando a aplicação
 return 0;

          }
