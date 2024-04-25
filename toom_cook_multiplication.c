//VAMOS CRIAR UM PROGRAMA QUE TESTA AS ROTINAS CRIADAS NO ARQUIVO toom_cook_multiplication.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o toom_cook_multiplication toom_cook_multiplication.c


//Cabeçalho
#include"toom_cook_multiplication.h"


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
 result=toom_cook3(base, first, second);

 printf("Resultado: ");
 printf128(result);

 
 //Finalizando a aplicação
 return 0;


          }
