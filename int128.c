//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS DO HEADER int128.h
//COMPILAR ESTE PROGRAMA COM: gcc -o int128 int128.c -lm


//Cabeçalho
#include"int128.h"
#include<stdio.h>

//Função principal
int main(){
//Variáveis locais
__int128_t tester;
char number_string[40];

//Procedimentos
//Recebendo input
printf("Digite um número: ");
scanf("%s", number_string);


printf("TESTE (regular printf): %s\n", number_string);

tester=scanf128(number_string);

//Printando um número na tela
printf128(tester);

//Finalizando a aplicação
return 0;
          };
