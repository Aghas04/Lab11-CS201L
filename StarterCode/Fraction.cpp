// Your Name : Alex Ghasemi
// Today's date : 4/10/2024
// Lab 9

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing

Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

Fraction::Fraction(int numerator, int denominator) {
	this->denominator = denominator;
	this->numerator = numerator;
}

int Fraction::getNumerator() { return numerator; }
int Fraction::getDenominator() { return denominator; }
void Fraction::setNumerator(int num) { numerator = num; }
void Fraction::setDenominator(int num) { denominator = num; }


int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
	if (denominator < 0) {
		numerator *= -1;
	}
}

bool Fraction::operator==(Fraction rhs) {
	if (this->numerator / this->denominator == rhs.numerator / rhs.denominator) {
		return true;
	}
	else {
		return false;
	}
}

Fraction Fraction::operator+(Fraction rhs) {
	Fraction tempF;
	tempF.numerator = this->numerator * rhs.denominator + this->denominator * rhs.numerator;
	tempF.denominator = this->denominator * rhs.denominator;
	tempF.reduce();
	return tempF;
}
Fraction Fraction::operator-(Fraction rhs) {
	Fraction tempF;
	tempF.numerator = this->numerator * rhs.denominator - this->denominator * rhs.numerator;
	tempF.denominator = this->denominator * rhs.denominator;
	tempF.reduce();
	return tempF;
}

Fraction Fraction::operator/(Fraction rhs) {
	Fraction tempF;
	tempF.numerator = this->numerator * rhs.denominator;
	tempF.denominator = this->denominator * rhs.numerator;
	tempF.reduce();
	return tempF;
}
Fraction Fraction::operator*(Fraction rhs) {
	Fraction tempF;
	tempF.numerator = this->numerator * rhs.numerator;
	tempF.denominator = this->denominator * rhs.denominator;
	tempF.reduce();
	return tempF;
}


istream& operator>>(istream& in, Fraction& fract) {
	char ignore;
	int num, denom;
	in >> num;
	fract.setNumerator(num);
	in >> ignore;
	in >> denom;
	fract.setDenominator(denom);
	return in;
}

ostream& operator<<(ostream& out, Fraction& fract) {
	out << fract.getNumerator() << " / " << fract.getDenominator();
	return out;
}
 