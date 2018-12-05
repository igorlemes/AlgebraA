#include <stdio.h>
#include <gmp.h>

int talvez_primo(const mpz_t a, const mpz_t n, const mpz_t n1, unsigned int t, const mpz_t q);
int provavelmente_primo(const mpz_t n, unsigned int iter, gmp_randstate_t rnd);
void numero_aleatorio(mpz_t r, const mpz_t n, gmp_randstate_t rnd);