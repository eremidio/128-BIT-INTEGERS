//VAMOS CRIAR UMA ROTINA ÚTIL PARA EXPONENCIAÇÃO MODULAR DE INTEIROS DE 128 BITS USANDO A BIBLIOTECA GMP


/*

ROTINA PARA EXPONENCIAÇÃO MODULAR DE INTEIROS NA FAIXA DE 10^20 A 10^40. ESTA É UMA SUBROTINA ÚTIL PARA 
ALGORITMOS MAIS SOFISTICADOS TRABALHANDO COM INTEIROS NESSA FAIXADE VALORES.

*/


//**********************************************************************************************************
//CABEÇALHO
#ifndef MOD_BIN_EXPONENTIATION_GMP128_H
#define MOD_BIN_EXPONENTIATION_GMP128_H
#include"gmp_128bits.h"


//**********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
__int128_t mod_bin_exponentiation_gmp128(__int128_t, __int128_t, __int128_t);


//**********************************************************************************************************
//FUNÇÕES
//Função que calcula a exponencial modular de inteiros de 128 bits (≳ 64 bits)
__int128_t mod_bin_exponentiation_gmp128(__int128_t base, __int128_t exponent, __int128_t modulus){

  //Variáveis locais
  mpz_t var1, var2, var3, res;
  mpz_init(var1); mpz_init(var2); mpz_init(var3); mpz_init(res);
  __int128_t result=0;


  //Procedimentos
    //Ajuste de variáveis gmp
    set_128_si(var1, base);
    set_128_si(var2, exponent);
    set_128_si(var3, modulus);

    //Calculando a exponencial modular usando a biblioteca gmp
    mpz_powm(res, var1, var2, var3);

    //Alocando o resultado em uma variável de 128 bits
    get_128_si(res, &result);

    //Limpando o cachê de memória
    mpz_clear(var1); mpz_clear(var2); mpz_clear(var3); mpz_clear(res);

  //Resultado
  return result;

};


//**********************************************************************************************************
//FIM DO HEADER 
#endif
