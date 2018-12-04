#include <stdio.h>
#include "primalidade.h"
#include "aritmetica.h"
// a = base, n = numero cuja primalidade esta sendo testada
// n1 = variável auxiliar n-1, t = variável auxiliar n-1 = (2^t)q
// q = variável auxiliar n-1 = (2^t)q

int talvez_primo(const mpz_t a, const mpz_t n, const mpz_t n1, unsigned int t, const mpz_t q){
	mpz_t r;
	mpz_init(r);

	exp_binaria (r, a, q, n);
	
	if( mpz_cmp_ui (r, 1) == 0 || mpz_cmp_ui (r, n1) == 0 ){
		return 1;
	} else {
		while (mpz_cmp_ui (r, 1) == 0 || mpz_cmp_ui (r, n1) == 0){
			mpz_set_ui (q, 2);
			exp_binaria (r, r, q, n);
		}
	}

	if( mpz_cmp_ui (r, 1) == 0 ){
		return 1;
	else if (mpz_cmp_ui (r, n1) == 0)
		return 0;
}

int provavelmente_primo(const mpz_t n, unsigned int iter, gmp_randstate_t rnd){
	mpz_t r;
	mpz_init(r);

	mpz_t n1;
	mpz_init(n1);
	mpz_sub_ui(n1, n, 1);
	

	for (int i = 0; i < iter; i++){	
		// gerar uma base aleatória a entre 2 e n−1
		numero_aleatorio(r, n, rnd);

		if( talvez_primo(r, n, n1,  ) )
	}





	return 1;
}
void numero_aleatorio(mpz_t r, const mpz_t n, gmp_randstate_t rnd){
	mp_bitcnt_t num_bits = mpz_sizeinbase(n, 2);
	do {
		mpz_urandomb(r, rnd, num_bits);
	} while (!(mpz_cmp_ui(r, 2) >= 0 && mpz_cmp(r, n) < 0));
}