//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO binary_multiplicationl.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o binary_multiplication binary_multiplication.c -lm

//Cabeçalho
#include"binary_multiplication.h"


//Função principal
int main(){
//Variáveis locais
char number_string1[40], number_string2[40];
__int128_t p, q, r;


//Procedimentos
//Recebendo input
printf("Primeira parcela: ");
scanf("%s", number_string1);

printf("Segunda parcela: ");
scanf("%s", number_string2);


p=scanf128(number_string1);
q=scanf128(number_string2);


//Calculando o produto das duas parcelas
r=binary_multiplication(p, q);

printf("Produto: ");
printf128(r);

//Finalizando a aplicação 
return 0;
          }
