// VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O CÁLCULO DO RECÍPROCO GENERALIZADO DE
// UM INTEIRO DE 128 BITS E APLICAÇÕES PARA ARITMÉTICA MODULAR ESSE ALGORITMO DE
// DIVISÃO E ARITMÉTICA MODULAR É UMA VERSÃO DO ALGORITMO DE BARRET PARA
// INTEIROS DE 128 BITS.

//****************************************************************************************************************************************
// CABEÇALHO
#ifndef BINARY_RECIPROCATION_H
#define BINARY_RECIPROCATION_H
#include "binary_division.h"
#include "binary_multiplication.h"

//****************************************************************************************************************************************
// DECLARAÇÕES DE FUNÇÕES
short bit_counter(__int128_t);
__int128_t binary_reciprocation(__int128_t);
void binary_modular_division_algorithm(__int128_t*, __int128_t*, __int128_t,
                                       __int128_t);

//****************************************************************************************************************************************
// FUNÇÕES
// Função que computa o número de bits na string binária de um inteiro de 128
// bits
short bit_counter(__int128_t number) {
  // Variáveis locais
  short counter = 0;

  // Procedimento
  // Loop principal
  while (number > 0) {
    counter++;
    number >>= 1;
  };

  // Resultado
  return counter;
};

// Função que calcula o recíproco generalizado para um inteiro de 128 bits
__int128_t binary_reciprocation(__int128_t n) {
  // Variáveis locais
  short bit_size = bit_counter(n);
  __int128_t r = (2 << (bit_size - 1));
  __int128_t denominator = r;
  __int128_t s = r;
  __int128_t y;

  // Procedimentos
  // Loop principal
  do {
    __int128_t temp = binary_division(binary_multiplication(r, r), denominator);
    __int128_t temp2 = binary_multiplication(n, temp);
    __int128_t temp3 = binary_division(temp2, denominator);

    r <<= 1;
    r -= temp3;

    if (s >= r) break;

    s = r;

  } while (1);

  // Ajuste fino do resultado
  y = (2 << (2 * bit_size - 1)) - binary_multiplication(n, r);

  while (y < 0) {
    r--;
    y += n;
  };

  // Resultado
  return r;
};

// Função que retorna a relação de congruência e limitante inferior do quociente
// de inteiros de 128 bits usando a redução de Barret
void binary_modular_division_algorithm(__int128_t* quotient,
                                       __int128_t* modulus, __int128_t x,
                                       __int128_t N) {
  // Variáveis locais
  __int128_t div = 0;
  __int128_t R = binary_reciprocation(N);
  __int128_t d;
  short s = (2 * (bit_counter(R) - 1));

  // Procedimentos
  // Loop principal: redução de Barret
  while (1) {
    d = binary_division(binary_multiplication(x, R), (2 << (s - 1)));
    x = x - binary_multiplication(N, d);

    if (x >= N) {
      x -= N;
      d++;
    };

    div += d;

    if (x < N) break;
  };

  // Resultado
  (*quotient) = div;
  (*modulus) = x;
};

//****************************************************************************************************************************************
// FIM DO HEADER
#endif
