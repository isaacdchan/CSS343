#include "Poly.h"
#include <iostream>
#include <sstream>


using namespace std;

int TotalPassed = 0;
int TotalTests = 0;

template <typename T> void isOK(const T& actual, const T& expected) {
	++TotalTests;
	if (actual == expected) {
		++TotalPassed;
		cout << "OK:" << endl;
		cout << "\tMatches: " << actual << endl;
	}
	else {
		cout << "ERR:" << endl;
		cout << "\tActual: " << actual << endl << "\tExpected: " << expected << endl;
	}
}

void testAdditionSubtraction() {
	stringstream Ss;
	Poly P0(1, 0);
	Poly P1(1, 0);

	Poly P2(2, 1);
	Poly P3(3, 2);
	Poly P4(4, 3);
	
	P0 += (P2 + P3 + P4);
	P1 -= (P2 + P3 + P4);

	Ss << P0;
	isOK(Ss.str(), "+4X^3+3X^2+2X^1+1\n"s);
	Ss.str("");
	Ss << P1;
	isOK(Ss.str(), "-4X^3-3X^2-2X^1+1\n"s);
}

void testMultiplication() {
	stringstream Ss;
	Poly P0(1, 1);
	Poly P1(2, 2);
	Poly P2 = P0 + P1;
	Poly P3(2, 2);
	Poly P4(3, 3);
	Poly P5 = P3 + P4;

	Poly P6 = P2 * P5;

	Ss << P6;
	isOK(Ss.str(), "+6X^5+7X^4+2X^3\n"s);
	Ss.str("");

	Poly P7(-1, 0);
	P6 *= P7;
	Ss << P6;
	isOK(Ss.str(), "-6X^5-7X^4-2X^3\n"s);
}


void testEquivalencies() {
	stringstream Ss;

	Poly P0(1, 1);
	Poly P1(2, 2);

	Poly P0_Copy = P0;

	isOK((P0 == P1), false);
	isOK((P0 == P0_Copy), true);
	isOK((P0 != P0_Copy), false);

}

void testInsertion() {
	stringstream Ss;

	Poly P0(5, 5);
	cin >> P0;
	Ss << P0;
	cout << Ss.str() << endl;
}

int main() {
	//testAdditionSubtraction();
	//testMultiplication();
	//testEquivalencies();
	//testInsertion();

	cout << endl << "Passed: " << TotalPassed << "/" << TotalTests << endl;
	return 0;

}