#include "Poly.h"

ostream& operator<<(ostream& Out, const Poly& P) {
	int i, Coeff, Exp;
	string Sign;

	//for (i = 0; i < P.maxExp; i++)
	//	cout << P.Terms[i] << " " << i << endl;

	for (i = P.maxExp; i > 0; i--) {
		Coeff = P.Terms[i];
		Exp = i;

		if (Coeff == 0)
			continue;

		Sign = (Coeff > 0) ? "+" : "";
		Out << Sign << to_string(Coeff) << "X" << "^" << to_string(Exp);
	}

	if (P.Terms[0] != 0) {
		Coeff = P.Terms[0];
		Sign = (Coeff > 0) ? "+" : "";
		Out << Sign << to_string(Coeff);
	}

	Out << endl;

	return Out;
}

istream& operator>>(istream& Input, const Poly& P) {
	int Exp, Coef;

	while (1) {
		Input >> Exp;
		Input >> Coef;

		if ((Exp == -1) && (Coef == -1))
			return Input;
		if (Exp > P.maxExp) {
			cout << "Input exponent larger than max exponent!" << endl;
			continue;
		}
		//setcoeff
		P.Terms[Exp] = Coef;
	}

	for (int i = 0; i < P.maxExp; i++)
		cout << P.Terms[i] << " " << i << endl;

	return Input;
}


// constructors
Poly::Poly(int startingCoefficient, int maxExpArg = 0) {
	maxExp = maxExpArg;

	Terms = new int[maxExp + 1] {0};
	Terms[maxExp] = startingCoefficient;
}
Poly::Poly(const Poly& original)
	:maxExp(original.maxExp)  {
	
	int i, Coeff;
	Terms = new int[maxExp + 1]{ 0 };

	// self-asSignment guard
	if (this == &original) {
		delete[] Terms;
		return;
	}

	for (i = 0; i <= maxExp; i++) {
		Coeff = original.Terms[i];
		Terms[i] = Coeff;
	}
}

// destructor
Poly::~Poly() {
	delete[] Terms;
}

int Poly::getCoeff(int power) {
	if (power > maxExp)
		return -1; //unsure what the default behavior
	return Terms[power];
}

Poly Poly::operator=(const Poly& Other) {
	Poly newPoly = Poly(*this);
	return newPoly;
}

Poly Poly::operator+=(const Poly& Other) {
	int i, newMaxExp;
	newMaxExp = (maxExp > Other.maxExp) ? maxExp : Other.maxExp;

	int* oldTerms = Terms;
	Terms = new int[newMaxExp + 1]{ 0 };

	for (i = 0; i <= maxExp; i++)
		Terms[i] += oldTerms[i];
	for (i = 0; i <= Other.maxExp; i++)
		Terms[i] += Other.Terms[i];

	maxExp = newMaxExp;
	delete[] oldTerms;
	return *this;
}
Poly Poly::operator+(const Poly& Other) {
	Poly newPoly = Poly(*this);
	return newPoly += Other;
}

Poly Poly::operator-=(const Poly& Other) {
	int i, newMaxExp;

	newMaxExp = (maxExp > Other.maxExp) ? maxExp : Other.maxExp;

	int* oldTerms = Terms;
	Terms = new int[newMaxExp + 1]{ 0 };

	for (i = 0; i <= maxExp; i++)
		Terms[i] += oldTerms[i];
	for (i = 0; i <= Other.maxExp; i++)
		Terms[i] -= Other.Terms[i];

	maxExp = newMaxExp;
	delete[] oldTerms;

	return *this;
}

Poly Poly::operator-(const Poly& Other) {
	Poly newPoly = Poly(*this);
	return newPoly -= Other;
}


Poly Poly::operator*=(const Poly& Other) {
	int exp1, exp2, Coeff1, Coeff2, newCoeff, newExp, newMaxExp;

	newMaxExp = maxExp + Other.maxExp + 1;

	int* oldTerms = Terms;

	Terms = new int[newMaxExp + 1]{ 0 };

	for (exp1 = 0; exp1 <= maxExp; exp1++) {
		Coeff1 = oldTerms[exp1];

		for (exp2 = 0; exp2 <= Other.maxExp; exp2++) {
			Coeff2 = Other.Terms[exp2];

			newExp = exp1 + exp2;
			newCoeff = Coeff1 * Coeff2;

			Terms[newExp] += newCoeff;

			exp1, exp2, Coeff1, Coeff2, newCoeff, newExp;
		}
	}

	maxExp = newMaxExp;

	return *this;
}
Poly Poly::operator*(const Poly& Other) {
	Poly newPoly = Poly(*this);
	return newPoly *= Other;
}




bool Poly::operator==(const Poly& Other) {
	if (maxExp != Other.maxExp)
		return false;
	
	for (int i = 0; i <= maxExp; i++) {
		if (Terms[i] != Other.Terms[i])
			return false;
	}

	return true;
}

bool Poly::operator!=(const Poly& Other) {
	return !((*this) == Other);
}