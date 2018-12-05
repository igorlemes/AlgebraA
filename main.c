#include <stdio.h>
#include "aritmetica.h"
#include "primalidade.h"

int main(){
	mpz_t b;
	mpz_init(b);
	gmp_scanf("%Zd", b);

	mpz_t e;
	mpz_init(e);
	gmp_scanf("%Zd", e);

	mpz_t n;
	mpz_init(n);
	gmp_scanf("%Zd", n);

	mpz_t r;
	mpz_init(r);

	exp_binaria(r, b, e, n);
	

	gmp_printf("b: %Zd\n", b);
	gmp_printf("e: %Zd\n", e);
	gmp_printf("n: %Zd\n", n);
	gmp_printf("r: %Zd\n", r);
}
