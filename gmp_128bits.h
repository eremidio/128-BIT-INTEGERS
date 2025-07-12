//VAMOS CRIAR UM WRAPPER PARA USAR INTEIROS DE 128 BITS DIRETAMENTE COM BIBLIOTECA GMP

/*

SUBROTINA ÚTIL EM ALGUNS ALGORITMOS QUANDO INTEIROS DE PRECISÃO MÚLTIPLOS SÃO REQUERIDOS.
PERMITE UMA MAIOR FLEXIBILIDADE AO USAR INTEIROS DE 128 BITS JUNTO COM A BIBLIOTECA GMP,
AO USAR INTEIROS DE 128 BITS QUE COBREM UM ESPECTRO DE VALORES DE ~ 10^20 A 10^40.


*/ 


//**********************************************************************************************************
//CABEÇALHO
#ifndef GMP_128_H
#define GMP_128_H
#include"int128.h"
#include<gmp.h>
#include<stdbool.h>


//**********************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void set_128_si(mpz_t, __int128_t);
void get_128_si(mpz_t, __int128_t*);


//**********************************************************************************************************
//FUNÇÕES
//Função que aloca um inteiro de 128 bits em  uma variável tipo (gmp) mpz_t
void set_128_si(mpz_t N, __int128_t n) {

  // Caso base: o número em questão pode ser alocado em um inteiro de 64 bits
  if (n >= INT64_MIN && n <= INT64_MAX) {
    mpz_set_si(N, (int64_t)n);
    return;
  }

  // Ajuste de sinal
  bool is_negative = (n < 0);
  if (is_negative) n = -n;

  //Variáveis locais
  uint64_t high = (uint64_t)(n >> 64);
  uint64_t low  = (uint64_t)(n & 0xFFFFFFFFFFFFFFFFULL/*bit mask*/);
  mpz_t high_mpz, low_mpz;
  mpz_init(high_mpz); mpz_init(low_mpz);


  //Procedimentos
    //Ajuste de valores
    mpz_set_ui(high_mpz, high);
    mpz_set_ui(low_mpz, low);
    mpz_mul_2exp(high_mpz, high_mpz, 64); // high <<= 64
    mpz_add(N, high_mpz, low_mpz);        // N = high + low

    //Ajuste de sinal do resultado
    if (is_negative)
        mpz_neg(N, N);

    //Limpando o cachê de memória
    mpz_clear(high_mpz);
    mpz_clear(low_mpz);

};

// Função que aloca o valor de uma variável do tipo mpz_t em uma variável do tipo __int128_t
void get_128_si(mpz_t N, __int128_t* n) {

  // Variáveis locais
  mpz_t temp1, temp2, absN;
  mpz_init(temp1);
  mpz_init(temp2);
  mpz_init(absN);
  bool is_negative = false;


  //Procedimentos
    // Ajuste de sinal
    if(mpz_sgn(N) < 0) {
      mpz_neg(absN, N);
      is_negative = true;
    }
    else {
      mpz_set(absN, N);
    }


    // Checando se o número cabe em um inteiro de 64 bits
    if (mpz_fits_slong_p(absN)) {
      int64_t value = mpz_get_si(absN);
      (*n) = is_negative ? -(__int128_t)value : (__int128_t)value;
      mpz_clears(temp1, temp2, absN, NULL);
      return;
    }

 
    //Decompondo em duas parcelas: high e low
    mpz_fdiv_q_2exp(temp1, absN, 64);  // high = absN >> 64
    mpz_fdiv_r_2exp(temp2, absN, 64);  // low  = absN & ((1ULL << 64) - 1)

    uint64_t high = mpz_get_ui(temp1);
    uint64_t low  = mpz_get_ui(temp2);

    (*n) = ((__int128_t)high << 64) + (__int128_t)low;
  
    if(is_negative) {
      (*n) = -(*n);
    }

    //Limpando o cachê de memória
    mpz_clears(temp1, temp2, absN, NULL);

}

//**********************************************************************************************************
//FIM DO HEADER
#endif
