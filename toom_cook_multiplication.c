//VAMOS CRIASR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO toom_cook_multiplication.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o toom_cook_multiplication toom_cook_multiplication.c -O3


//Cabeçalho
#include"toom_cook_multiplication.h"

//Função principal
int main(){

  //Variáveis locais
  char number_string1[40], number_string2[40];
  __int128_t first, second, result;


 //Procedimentos
    //Recebendo input
    printf("Primeira parcela: ");
    if(scanf("%s", number_string1)<1) return 0;


    printf("Segunda parcela: ");
    if(scanf("%s", number_string2)<1) return 0;


    first=scanf128(number_string1);
    second=scanf128(number_string2);

    //Calculando o produto das duas parcelas
    result=toom_cook_multiplication(first, second);

    printf("Resultado: ");
    printf128(result);

 
  //Finalizando a aplicação
  return 0;


}
