//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO binary_modular_multiplication.h 
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o binary_modular_multiplication binary_modular_multiplication.c


//Cabeçalho
#include"binary_modular_multiplication.h"

//Função principal
int main(){
//Variáveis locais
char number_string1[40], number_string2[40], number_string3[40];
__int128_t a, b, m, r;


//Procedimentos
//Recebendo input
printf("Primeira parcela: ");
scanf("%s", number_string1);

printf("Segunda parcela: ");
scanf("%s", number_string2);

printf("Congruente: ");
scanf("%s", number_string3);

a=scanf128(number_string1);
b=scanf128(number_string2);
m=scanf128(number_string3);

//Calculando o produto das duas parcelas
r=binary_modular_multiplication(a, b, m);

printf("Resultado: ");
printf128(r);

//Finalizando a aplicação 
return 0;
          }

