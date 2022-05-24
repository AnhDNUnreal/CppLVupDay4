#include <iostream>
using namespace std;

class CFraction
{
	friend CFraction operator+ (const CFraction& f1, const CFraction& f2);
	friend CFraction operator- (const CFraction& f1, const CFraction& f2);
	friend CFraction operator* (const CFraction& f1, const CFraction& f2);
	friend CFraction operator/ (const CFraction& f1, const CFraction& f2);

public:
	CFraction(int, int);
	void Input(CFraction& fr);
	void Display();
	int GCD(int n, int d);
	void reFrac(int n, int d);

private:
	int num;
	int den;
};

CFraction::CFraction(int n, int d)
{
	num = n;
	den = d;
}

/****************************
* Function name: Input()
* Description: Input Fraction
* Parameter: CFraction [I]
* Return: void
****************************/
void CFraction::Input(CFraction& fr)
{
	cout << "Input numerator:   ";
	cin >> fr.num;
	do
	{
		cout << "Input denominator: ";
		cin >> fr.den;
	} while (fr.num == 0);
}

/************************************************************************
* Function name: GCD()
* Description: find Greatest Common Divisor of numerator and denominator
* Parameter: int [I], int [I]
* Return: Greatest Common Divisor of numerator and denominator
************************************************************************/
int CFraction::GCD(int n, int d)
{
	if (n % d == 0)
		return d;
	return GCD(d, n % d);
}

/*********************************
* Function name: reFrac()
* Description: reduce the fraction
* Parameter: int [I], int [I]
* Return: void
*********************************/
void CFraction::reFrac(int a, int b)
{
	int i = GCD(a, b);
	a = a / i;
	b = b / i;
	if ((a < 0 && b < 0) || (a > 0 && b < 0))
	{
		a = -a;
		b = -b;
	}
	if (a % b == 0) cout << a / b << '\n';
	else cout << a << "/" << b << '\n';
}

/***********************************
* Function name: Display()
* Description:  Display the fraction
* Parameter: NIL
* Return: void
************************************/
void CFraction::Display()
{
	reFrac(num, den);
}

// Overloading the Arithmetic Operators:
CFraction operator +(const CFraction& fr1, const CFraction& fr2)	
{
	CFraction res(1,1);
	res.num = fr1.num * fr2.den + fr1.den * fr2.num;
	res.den = fr1.den * fr2.den;
	return res;
}

CFraction operator -(const CFraction& fr1, const CFraction& fr2)
{
	CFraction res(1, 1);
	res.num = fr1.num * fr2.den - fr1.den * fr2.num;
	res.den = fr1.den * fr2.den;
	return res;
}

CFraction operator *(const CFraction& fr1, const CFraction& fr2)
{
	CFraction res(1, 1);
	res.num = fr1.num * fr2.num;
	res.den = fr1.den * fr2.den;
	return res;
}

CFraction operator /(const CFraction& fr1, const CFraction& fr2)
{
	CFraction res(1, 1);
	res.num = fr1.num * fr2.den;
	res.den = fr1.den * fr2.num;
	return res;
}

int main()
{
	CFraction frac1(1, 1), frac2(1, 1), fracRes(1, 1);

	cout << "-Fraction 1-\n";
	frac1.Input(frac1);
	cout << "\n-Fraction 2-\n";
	frac2.Input(frac2);	
	cout << "===========================================\n";	
	cout << "\nThe addition of 2 fractions is:       ";
	fracRes = frac1 + frac2;
	fracRes.Display();

	cout << "\nThe subtraction of 2 fractions is:    ";
	fracRes = frac1 - frac2;
	fracRes.Display();

	cout << "\nThe multiplication of 2 fractions is: ";
	fracRes = frac1 * frac2;
	fracRes.Display();

	cout << "\nThe division of 2 fractions is:       ";
	fracRes = frac1 / frac2;
	fracRes.Display();
}