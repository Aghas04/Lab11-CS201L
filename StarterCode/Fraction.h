#pragma once
// Your Name
// Today's date
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{

	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	
	int numerator = 0;
	int denominator = 0;
public:
	//Constructors
	Fraction(); // constructor
	Fraction(int numerator, int denominator); //overloaded constructor
	//getters
	int getNumerator();
	int getDenominator();
	//setters
	void setNumerator(int num);
	void setDenominator(int num);
	
	//other
	int getGCD(int num1, int num2);
	void reduce();
	bool operator==(Fraction rhs);
	Fraction operator+(Fraction rhs);
	Fraction operator-(Fraction rhs);
	Fraction operator/(Fraction rhs);
	Fraction operator*(Fraction rhs);

	//friend operators in & out streams
	friend istream& operator>> (istream& in, Fraction& n);
	friend ostream& operator<< (ostream& out, Fraction& c);
};

