#ifndef RATIONAL_H_
#define RATIONAL_H_

typedef struct Rational {
	long num;  // numérateur
	long den;  // dénominateur
} Rational;

void display_rational(const Rational r);  // affiche le nombre rationnel r

Rational radd(Rational a, Rational b);  // renvoie a+b
Rational rsub(Rational a, Rational b);  // renvoie a-b
Rational rmul(Rational a, Rational b);  // renvoie a*b
Rational rdiv(Rational a, Rational b);  // renvoie a/b

int gt(Rational a, Rational b);   // renvoie 1 si a > b,  sinon 0
int lt(Rational a, Rational b);   // renvoie 1 si a < b,  sinon 0
int gte(Rational a, Rational b);  // renvoie 1 si a >= b,  sinon 0
int lte(Rational a, Rational b);  // renvoie 1 si a <= b,  sinon 0
int eq(Rational a, Rational b);   // renvoie 1 si a == b,  sinon 0
int neq(Rational a, Rational b);  // renvoie 1 si a != b,  sinon 0

Rational max(Rational a, Rational b);  // renvoie le max entre a et b
Rational min(Rational a, Rational b);  // renvoie le min entre a et b

#endif
