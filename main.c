#include <stdio.h>
#include "aritmetica.h"
#include "primalidade.h"

int main(){

	mpz_t a;
	mpz_init(a);
	gmp_scanf("%Zd", a);

	mpz_t n;
	mpz_init(n);
	gmp_scanf("%Zd", n);

	mpz_t n1;
	mpz_init(n1);
	mpz_sub_ui(n1, n1, 1);

	unsigned long int t = 0;
	while(mpz_divisible_2exp_p(n1, t)){
		t++;
	}
	t--;

	mpz_t aux;
	mpz_init(aux);
	mpz_set_ui(aux, 2);
	mpz_powm_ui(aux, aux, t, n);

	mpz_t q;
	mpz_init(q);
	mpz_divexact(q, n1, aux);

	// unsigned int iter;
	// scanf("%u", &iter);
	// gmp_randstate_t rnd;
	// gmp_randinit_default(rnd);
	// gmp_randseed_ui(rnd, 12345678910);
	// if(mpz_probab_prime_p(n, iter)){
	// 	printf("mpz: Probably Prime\n");
	// } else {
	// 	printf("mpz: Not Prime\n");
	// }

	if(talvez_primo(a, n, n1, t, q)){
		printf("Not Prime\n");
	} else {
		printf("Probably Prime\n");
	}

	gmp_printf("a: %Zd\n", a);
	gmp_printf("n: %Zd\n", n);
	gmp_printf("n1: %Zd\n", n1);
	printf("%ld\n", t);
	gmp_printf("q: %Zd\n", q);
	gmp_printf("aux: %Zd\n", aux);
	
}
