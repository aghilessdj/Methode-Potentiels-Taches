#include <stdio.h>
#include <stdlib.h>
#include "rational.h"

/*
 * renvoie le PGCD des a et b
 */
static long gcd(long a, long b) {
	// A faire
	return;
}

/*
 * garantit que:
 * - le dénominateur n'est pas zéro,
 * - le numérateur et le dénominateur sont premiers entre eux,
 * - si le nombre rationnel est négatif, alors le numérateur est négatif
 *   et le dénominateur est positif.
 */
static void simplify(Rational *r) {
	if ((*r).den == 0) {
		printf("Rational.simplify: division by zero: ");
		display_rational(*r);
		printf("\n");
		exit(1);
	}

	long d = gcd(labs((*r).num), labs((*r).den));
	(*r).num /= d;
	(*r).den /= d;

	if ((*r).den < 0) {
		(*r).num *= -1;
		(*r).den *= -1;
	}
}

/*
 * affiche le nombre rationnel r
 */
void display_rational(const Rational r) {
	printf("%ld/%ld", r.num, r.den);
}

/*
 * renvoie a+b
 */
Rational radd(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie a-b
 */
Rational rsub(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie a*b
 */
Rational rmul(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie a/b
 */
Rational rdiv(Rational a, Rational b) {
	// A faire
	return ;
}

/*
 * renvoie 1 si a > b,  sinon 0
 */
int gt(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie 1 si a < b,  sinon 0
 */
int lt(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie 1 si a >= b,  sinon 0
 */
int gte(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie 1 si a <= b,  sinon 0
 */
int lte(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie 1 si a == b,  sinon 0
 */
int eq(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie 1 si a != b,  sinon 0
 */
int neq(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie le max entre a et b
 */
Rational max(Rational a, Rational b) {
	// A faire
	return;
}

/*
 * renvoie le min entre a et b
 */
Rational min(Rational a, Rational b) {
	// A faire
	return;
}
