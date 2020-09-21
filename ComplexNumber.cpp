#include "ComplexNumber.h"
#include <math.h>

/*
 * AUTHOR:       Lisa Gentil
 * NETID:        gentil2
 * LECTURE:      BL2
 * DISCUSSION:   BD4
 * MP/LAB:       MP12: This week's machine problem was a sort of calculator that accepts as
 *                      inputs real numbers, rational numbers and complex numbers. 
 *                      This class focuses on complex numbers and the different methods will use 
 *                      that complex number as the first operator and the second operator may be
 *                      another complex, a real or a rational number. For any operation and any
 *			second operand (real, rational or complex) the result will be a new
 *			complex number.
 *
 *
 * TERM:         Spring 2016
 * PARTNERS:     N/A
 */

//empty constructor
ComplexNumber::ComplexNumber()
{
	NumberType = COMPLEX;
	realComponent = 0.0;
	imagComponent = 0.0;
}//end empty constructor

//complete constructor
ComplexNumber::ComplexNumber(double real, double imag)
{
	NumberType = COMPLEX;
	realComponent = real;
	imagComponent = imag;
}//end complete constructor

//setters and getters
void ComplexNumber::set_realComponent(double rval)
{
	realComponent = rval;
}//end setter real val

void ComplexNumber::set_imagComponent(double ival)
{
	imagComponent = ival;
}//end setter imag val

double ComplexNumber::get_realComponent(void) const
{	
	return realComponent;
}//end getter real val

double ComplexNumber::get_imagComponent(void) const
{	
	return imagComponent;
}//end getter imag val

void ComplexNumber::set_value (double rval, double ival)
{
	set_realComponent(rval);
	set_imagComponent(ival);
}//end setter value

//Class member
double ComplexNumber::magnitude()
{
	double mag = sqrt(realComponent * realComponent + imagComponent * imagComponent);
	return mag;
}//end magnitude

/************************************TWO COMPLEX NUMBERS********************************************/
ComplexNumber ComplexNumber::operator+(const ComplexNumber& arg)
{
	//creating new variable
	ComplexNumber result;

	//adding the two complex
	result.realComponent = realComponent + arg.get_realComponent();
	result.imagComponent = imagComponent + arg.get_imagComponent();
	return result;
}//end plus

ComplexNumber ComplexNumber::operator-(const ComplexNumber& arg)
{
	//creating new variable
	ComplexNumber result;

	//substracting the two complex
	result.realComponent = realComponent - arg.get_realComponent();
	result.imagComponent = imagComponent - arg.get_imagComponent();
	return result;
}//end minus

ComplexNumber ComplexNumber::operator*(const ComplexNumber& arg)
{
	//creating new variable
	ComplexNumber result;

	//multiplying the two complex
	// (a + ib) * (c + id) = ac - bd + i(bc + ad)
	result.realComponent = realComponent * arg.get_realComponent() - imagComponent * arg.get_imagComponent();
	result.imagComponent = imagComponent * arg.get_realComponent() + realComponent * arg.get_imagComponent();
	return result;
}//end times

ComplexNumber ComplexNumber::operator/(const ComplexNumber& arg)
{
	//creating new variable
	ComplexNumber result;

	//dividing the two complex
	// (a + ib) / (c + id) = (ac + bd + i(bc - ad)) / c^2 + d^2
	result.realComponent = (realComponent * arg.get_realComponent() + imagComponent * arg.get_imagComponent()) / (arg.get_realComponent() * arg.get_realComponent() + arg.get_imagComponent() * arg.get_imagComponent());
	result.imagComponent = (imagComponent * arg.get_realComponent() - realComponent * arg.get_imagComponent()) / (arg.get_realComponent() * arg.get_realComponent() + arg.get_imagComponent() * arg.get_imagComponent());
	return result;
}//end divides

/**************************************COMPLEX AND REAL*********************************************/
ComplexNumber ComplexNumber::operator+(const RealNumber& arg)
{
	//adding a complex and a real
	return ComplexNumber(realComponent + arg.get_value(), imagComponent);

}//end plus

ComplexNumber ComplexNumber::operator-(const RealNumber& arg)
{
	//substracting a complex and a real
	return ComplexNumber(realComponent - arg.get_value(), imagComponent);

}//end minus

ComplexNumber ComplexNumber::operator*(const RealNumber& arg)
{
	//multiplying a complex and a real
	return ComplexNumber(realComponent * arg.get_value(), imagComponent * arg.get_value());

}//end times

ComplexNumber ComplexNumber::operator/(const RealNumber& arg)
{
	//dividing a complex and a real
	return ComplexNumber(realComponent / arg.get_value(), imagComponent / arg.get_value());

}//end divides

/************************************COMPLEX AND RATIONAL*******************************************/
ComplexNumber ComplexNumber::operator+(const RationalNumber& arg)
{
	//adding a complex and a rational
	return ComplexNumber((arg.get_numerator() + realComponent * arg.get_denominator()) / arg.get_denominator(), imagComponent);

}//end plus

ComplexNumber ComplexNumber::operator-(const RationalNumber& arg)
{
	//substracting a complex and a rational
	return ComplexNumber((realComponent * arg.get_denominator() - arg.get_numerator()) / arg.get_denominator(), imagComponent);

}//end minus

ComplexNumber ComplexNumber::operator*(const RationalNumber& arg)
{
	//multiplying a complex and a rational
	return ComplexNumber(realComponent * arg.get_numerator() / arg.get_denominator(), imagComponent * arg.get_numerator() / arg.get_denominator());

}//end times

ComplexNumber ComplexNumber::operator/(const RationalNumber& arg)
{
	//dividing a complex and a rational
	return ComplexNumber(realComponent * arg.get_denominator() / arg.get_numerator(), imagComponent * arg.get_denominator() / arg.get_numerator());

}//end divides

//to_String converts real and imaginary components to string of type a+bi
string ComplexNumber::to_String(void){
	stringstream my_output;
	my_output << realComponent;
	if(imagComponent >= 0){
		my_output << " + " << imagComponent << "i";
	}
	else if(imagComponent < 0){
		my_output << "-" << imagComponent*(-1) << "i";
	}
	return my_output.str();
}
