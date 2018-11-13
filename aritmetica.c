#include "aritmetica.h"

void mdc_estendido (mpz_t g, mpz_t x, mpz_t y, const mpz_t a, const mpz_t b){
	mpz_t r;
	mpz_set (r, a);
	mpz_t r1;
	mpz_set (r, b);
	mpz_t u;
	mpz_set_ui (u, 1); 
	mpz_t v;
	mpz_set_ui (v, 0);  
	mpz_t u1;
	mpz_set_ui (u1, 0); 
	mpz_t v1;
	mpz_set_ui (v1, 1);

	mpz_t rs, us, vs, q, aux, aux2; 
	mpz_init(rs);
	mpz_init(us);
	mpz_init(vs);
	mpz_init(q);
	mpz_init(aux);
	mpz_init(aux2);

	while ( mpz_cmp_ui (r1, 0) != 0 ){
		mpz_cdiv_q (q, r, r1);
		mpz_set (rs, r);
		mpz_set (us, u);
		mpz_set (vs, v);
		mpz_set (r, r1);
		mpz_set (u, u1);
		mpz_set (v, v1);
		
		mpz_mul (aux, q, r1);
		mpz_sub (r1, rs, aux);


		mpz_mul (aux, q, u);
		mpz_sub (u1, us, aux);


		mpz_mul (aux, q, v);
		mpz_sub (v1, vs, aux);
	}
	mpz_mul (aux, a, u);
	mpz_mul (aux2, b, v);

	mpz_add (aux, aux, aux2);

	if (mpz_cmp (aux, g) == 0)
		printf("Correto\n");

}

//https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
//https://pt.wikipedia.org/wiki/Algoritmo_de_Euclides_estendido

