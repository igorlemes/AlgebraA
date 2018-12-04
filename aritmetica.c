#include <stdio.h>
#include "aritmetica.h"

void mdc_estendido (mpz_t g, mpz_t x, mpz_t y, const mpz_t a, const mpz_t b){
	// Criando outras variáveis para preservar o valor de a e b 
	mpz_t r;
	mpz_init(r);
	mpz_set (r, a);
	
	mpz_t r1;
	mpz_init(r1);
	mpz_set (r1, b);


	// Os valores iniciais para o calculo, são:
	mpz_set_ui (x, 1); 
	mpz_set_ui (y, 0);

	mpz_t u1;
	mpz_init(u1);
	mpz_set_ui (u1, 0); 
	
	mpz_t v1;
	mpz_init(v1);
	mpz_set_ui (v1, 1);


	// Definição de variaveis auxiliares, para os calculos iterativos
	mpz_t rs, xs, ys, q, aux, aux2; 
	mpz_init(rs);
	mpz_init(xs);
	mpz_init(ys);
	mpz_init(q);
	mpz_init(aux);
	mpz_init(aux2);

	// Enquanto o resto não for 0, o calculo continuará
	while ( mpz_cmp_ui(r1, 0) != 0 ){
		mpz_fdiv_q (q, r, r1);
		mpz_set (rs, r);
		mpz_set (xs, x);
		mpz_set (ys, y);
		mpz_set (r, r1);
		mpz_set (x, u1);
		mpz_set (y, v1);
		
		mpz_mul (aux, q, r1);
		mpz_sub (r1, rs, aux);

		mpz_mul (aux, q, x);
		mpz_sub (u1, xs, aux);

		mpz_mul (aux, q, y);
		mpz_sub (v1, ys, aux);
	}

	// calculando q atribuindo o valor de g
	mpz_mul(aux, x, a);
	mpz_mul(aux2, y, b);

	mpz_add(g, aux, aux2);
}

int inverso_modular(mpz_t r, const mpz_t a, const mpz_t n){

	mpz_t x;
	mpz_init(x);
	mpz_t y;
	mpz_init(y);
	mpz_t g;
	mpz_init(g);

	mdc_estendido (g, x, y, n, a);

	if( mpz_cmp_ui (g, 1) == 0){
		mpz_set (r, y);
		return 1;
	} else
		return 0;
}

void exp_binaria(mpz_t r, const mpz_t b, const mpz_t e, const mpz_t n){
	mpz_t b1;
	mpz_init(b1);
	mpz_set (b1, b);
	
	mpz_t aux;
	mpz_init(aux);
	mpz_set_ui (aux, 1);
	
	mpz_t e1;
	mpz_init(e1);
	mpz_set (e1, e);
	
	if(mpz_cmp_ui (e1, 0) == 0){
		mpz_set_ui (r, 1);
		return;
	}

	while( mpz_cmp_ui (e1, 1) > 0){
		if(mpz_cmp (b1, n) > 0)
			mpz_mod (b1, b1, n);
				
		if(mpz_even_p (e1) != 0){
			mpz_mul (b1, b1, b1);
			mpz_divexact_ui (e1, e1, 2);
		} else {
			mpz_mul (aux, aux, b1);
			mpz_mul (b1, b1, b1);
			mpz_sub_ui (e1, e1, 1);
			mpz_divexact_ui (e1, e1, 2);
		}
	}
	mpz_mul (r, b1, aux);
	
	if(mpz_cmp (r, n) > 0)
		mpz_mod (r, r, n);
}
//https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/
//https://pt.wikipedia.org/wiki/Algoritmo_de_Euclides_estendido
// https://simple.wikipedia.org/wiki/Exponentiation_by_squaring


