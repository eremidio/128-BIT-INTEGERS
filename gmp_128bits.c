//VAMOS CRIAR UM PROGRAMA PARA TESTAR AS ROTINAS CRIADAS NO ARQUIVO gmp_128bits.h
//COMPILAR ESTE PROGRAMA COM O COMANDO: gcc -o gmp_128bits gmp_128bits.c -lm -lgmp


//Cabeçalho
#include"gmp_128bits.h"


//Função principal
int main(){

  //Variáveis locais
  __int128_t n;
  mpz_t N; mpz_init(N);
  char number_string[40];


  //Procedimentos
    //Recebendo input
    printf("Digite um número: ");
    scanf("%s", number_string);
    n=scanf128(number_string);
    printf("TESTE 1 (128 bits): "); printf128(n);


    //Alocando um inteiro de 128 bits em uma variável mpz_t (gmp)
    set_128_si(N, n);
    gmp_printf("Variável gmp: %Zd\n", N);  
    n=0;

    //Alocando o valor de uma variável gmp em um inteiro de 128bits
    get_128_si(N, &n);
    printf("TESTE 2 (128 bits): "); printf128(n);

    //Limpando o cachê de memória
    mpz_clear(N);


  //Finalizando a aplicação
  return 0;

};
