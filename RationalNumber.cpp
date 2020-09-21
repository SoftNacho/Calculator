#include "RationalNumber.h"
#include <math.h>

/*
 * AUTHOR:       Lisa Gentil
 * NETID:        gentil2
 * LECTURE:      BL2
 * DISCUSSION:   BD4
 * MP/LAB:       MP12: This week's machine problem was a sort of calculator that accepts as
 *                      inputs real numbers, rational numbers and complex numbers. 
 *                      This class focuses on rational numbers and the different methods will use 
 *                      that number as the first operator and the second operator may be
 *                      another rational, a real or a complex number. For an operation with a 
 *                      real the output value will be a real (so a decimal),for any 
 *                      operation with another rational number, the output will be a new rational. 
 * 			Finally when a rational is modified with a complex number the result 
 *			will be a new complex number.
 *
 *
 * TERM:         Spring 2016
 * PARTNERS:     N/A
 */


//empty constructor
RationalNumber::RationalNumber()
{
	NumberType = RATIONAL;
	numerator = 0;
	denominator = 1;
}//end empty constructor

//complete constructor
RationalNumber::RationalNumber(int numer, int denom)
{
	NumberType = RATIONAL;
	numerator = numer;
	denominator = denom;
}//end complete constructor

//Setter and getter
void RationalNumber::set_numerator(int numer)
{
	numerator = numer;
}//end setter for numer

void RationalNumber::set_denominator(int denom)
{
	denominator = denom;
}//end stter for denom

int RationalNumber::get_numerator(void) const
{
	return numerator;
}//end getter for numer

int RationalNumber::get_denominator(void) const
{
	return denominator;
}//end getter for denom

//Class member
void RationalNumber::set_value(int numer, int denom)
{
	int temp_gcd = gcd(numer, denom);
	set_numerator(numer / temp_gcd);
	set_denominator(denom / temp_gcd);
}//end set value

int RationalNumber::gcd(int a, int b)
{
	for(int i = 2; i <= a && i <= b; i++)
	{
		if(a%i == 0 && b%i == 0)
		{
			return i;
		}//end if
	}//end for
	return 1;
}//end gcd

double RationalNumber::magnitude()
{
	return abs(numerator / denominator);
}//end magnitude

double RationalNumber::decimal_value() const
{
	return numerator / denominator;
}//end decimal value

/************************************TWO RATIONAL NUMBERS********************************************/
RationalNumber RationalNumber::operator+(const RationalNumber& arg)
{
	//creating new variable
	RationalNumber result;

	//adding the two reals
	int temp_numerator = numerator * arg.get_denominator() + arg.get_numerator() * denominator;
	int temp_denominator = denominator * arg.get_denominator();
	int i = 0;
	while(i != 1)
	{
		i = gcd(temp_numerator, temp_denominator);
		temp_numerator = temp_numerator / i;
		temp_denominator = temp_denominator / i;
	}//end while loop
	result.numerator = temp_numerator;
	result.denominator = temp_denominator;
	return result;
}//end plus

RationalNumber RationalNumber::operator-(const RationalNumber& arg)
{
	//creating new variable
	RationalNumber result;

	//substracting the two reals
	int temp_numerator = numerator * arg.get_denominator() - arg.get_numerator() * denominator;
	int temp_denominator = denominator * arg.get_denominator();
	int i = 0;
	while(i != 1)
	{
		i = gcd(temp_numerator, temp_denominator);
		temp_numerator = temp_numerator / i;
		temp_denominator = temp_denominator / i;
	}//end while loop
	result.numerator = temp_numerator;
	result.denominator = temp_denominator;
	return result;
}//end minus

RationalNumber RationalNumber::operator*(const RationalNumber& arg)
{
	//creating new variable
	RationalNumber result;

	//mutiplying the two reals
	int temp_numerator = numerator * arg.get_numerator();
	int temp_denominator = denominator * arg.get_denominator();
	int i = 0;
	while(i != 1)
	{
		i = gcd(temp_numerator, temp_denominator);
		temp_numerator = temp_numerator / i;
		temp_denominator = temp_denominator / i;
	}//end while loop
	result.numerator = temp_numerator;
	result.denominator = temp_denominator;
	return result;
}//end times

RationalNumber RationalNumber::operator/(const RationalNumber& arg)
{
	//creating new variable
	RationalNumber result;

	//dividing the two reals
	int temp_numerator = numerator * arg.get_denominator();
	int temp_denominator = denominator * arg.get_numerator();
	int i = 0;
	while(i != 1)
	{
		i = gcd(temp_numerator, temp_denominator);
		temp_numerator = temp_numerator / i;
		temp_denominator = temp_denominator / i;
	}//end while loop
	result.numerator = temp_numerator;
	result.denominator = temp_denominator;
	return result;
}//end divides

/*************************************RATIONAL & COMPLEX*********************************************/
ComplexNumber RationalNumber::operator+(const ComplexNumber& arg)
{
	//adding a rational and a complex
	return ComplexNumber((numerator + arg.get_realComponent() * denominator) / denominator, arg.get_imagComponent());

}//end plus

ComplexNumber RationalNumber::operator-(const ComplexNumber& arg)
{
	//substracting a rational and a complex
	return ComplexNumber((numerator - arg.get_realComponent() * denominator) / denominator, - arg.get_imagComponent());

}//end minus

ComplexNumber RationalNumber::operator*(const ComplexNumber& arg)
{
	//multiplying a rational and a complex
	return ComplexNumber((numerator * arg.get_realComponent()) / denominator, (numerator * arg.get_imagComponent()) / denominator);

}//end times 

ComplexNumber RationalNumber::operator/(const ComplexNumber& arg)
{
	//dividing a rational and a complex
	//p/q / (a+ib) = pqa/(a^2q^2 + b^2q^2) - i pqb/(a^2q^2 + b^2q^2)
	return ComplexNumber((numerator * denominator * arg.get_realComponent()) / (denominator * denominator * arg.get_realComponent() * arg.get_realComponent() + denominator * denominator * arg.get_imagComponent() * arg.get_imagComponent()), -(numerator * denominator * arg.get_imagComponent()) / (denominator * denominator * arg.get_realComponent() * arg.get_realComponent() + denominator * denominator * arg.get_imagComponent() * arg.get_imagComponent()));

}//end divides

/***************************************RATIONAL & REAL**********************************************/
RealNumber RationalNumber::operator+(const RealNumber& arg)
{
	//adding a rational and a real
	return RealNumber((arg.get_value() * denominator + numerator) / denominator);

}//end plus

RealNumber RationalNumber::operator-(const RealNumber& arg)
{
	//substracting a rational and a real
	return RealNumber((numerator - arg.get_value() * denominator) / denominator);

}//end minus

RealNumber RationalNumber::operator*(const RealNumber& arg)
{
	//multiplying a rational and a real
	return RealNumber((numerator * arg.get_value()) / denominator);

}//end times

RealNumber RationalNumber::operator/(const RealNumber& arg)
{
	//dividing a rational and a real
	return RealNumber(numerator / (denominator * arg.get_value()));
	
}//end divides


//to_String converts numerator and denominator to string of type num/denom
string RationalNumber::to_String(void){
	stringstream my_output;
	my_output << numerator << "/" << denominator;
	return my_output.str();
}
