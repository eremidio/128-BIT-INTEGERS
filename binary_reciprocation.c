//VAMOS CRIAR UM PROGRAMA PARA TESTAR NAS ROTINAS CRIADAS NO ARQUIVO binary_reciprocation.h
//COMPILAR ESTE PROGRAMA COM O COMANDO : gcc -o binary_reciprocation binary_reciprocation.c


//Cabeçalho
#include"binary_reciprocation.h"

//Função principal
int main(){
//Variáveis locais
char number_string1[40], number_string2[40];
__int128_t p, q, reciprocal,  modulus, quotient;


//Procedimentos
//Recebendo input
printf("Primeira parcela: ");
scanf("%s", number_string1);

printf("Segunda parcela: ");
scanf("%s", number_string2);


p=scanf128(number_string1);
q=scanf128(number_string2);


//Calculando o recíproco, quociente e congruência das duas parcelas
binary_modular_division_algorithm(&quotient, &modulus, p, q);

reciprocal= binary_reciprocation(p);
printf("Recíproco generalizado da 1ª parcela: ");
printf128(reciprocal);


reciprocal= binary_reciprocation(q);
printf("Recíproco generalizado da 2ª parcela: ");
printf128(reciprocal);

printf("Quociente: ");
printf128(quotient);

printf("Congruência: ");
printf128(modulus);


//Finalizando a aplicação 
return 0;
          }
