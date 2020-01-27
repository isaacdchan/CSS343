#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class Poly {
	friend ostream& operator<<(ostream& Out, const Poly& P);
	friend istream& operator>>(istream& Out, const Poly& P);

public:
	Poly(int startingCoefficient, int maxExpArg);
	Poly(const Poly& original);
	~Poly();
	
	int getCoeff(int power);
	bool setCoeff(int power, int coeff);


	Poly operator=(const Poly& other);

	Poly operator+(const Poly& other);
	Poly operator+=(const Poly& other);

	Poly operator-(const Poly& other);
	Poly operator-=(const Poly& other);

	Poly operator*(const Poly& other);
	Poly operator*=(const Poly& other);

	bool operator==(const Poly& other);
	bool operator!=(const Poly& other);


private:
	int* Terms;
	int maxExp;
};