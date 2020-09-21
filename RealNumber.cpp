#include "RealNumber.h"
#include <math.h>

/*
 * AUTHOR:       Lisa Gentil
 * NETID:        gentil2
 * LECTURE:      BL2
 * DISCUSSION:   BD4
 * MP/LAB:       MP12: This week's machine problem was a sort of calculator that accepts as
 * 			inputs real numbers, rational numbers and complex numbers. 
 *			This class focuses on real numbers and the different methods will use 
 *			that real number as the first operator and the second operator may be
 *			another real, a rational or a complex number. For an operation with a 
 *			real the output value will be a real (so a decimal), same for any 
 *			operation with a rational number. Finally when a real is modified with
 *			a complex number the result will be a new complex number.
 *
 *
 * TERM:         Spring 2016
 * PARTNERS:     N/A
 */


//empty constructor
RealNumber::RealNumber()
{
	NumberType = REAL;
	value = 0.0;
}//end empty constructor

//constructor
RealNumber::RealNumber(double rval)
{
	NumberType = REAL;
	value = rval;
}//end constructor

//Setter and getter
void RealNumber::set_value(double rval)
{
	value = rval;
}//end setter

double RealNumber::get_value(void) const
{
	return value;
}//end getter

//class member function
double RealNumber::magnitude()
{
	return abs(value);
}//end magnitude

/************************************TWO REAL NUMBERS********************************************/
RealNumber RealNumber::operator+(const RealNumber& arg)
{
	//creating new variable
	 return RealNumber(value + arg.get_value());

	//adding the two reals
//	result.value = value + arg.get_value();
//	return result;
}//end plus

RealNumber RealNumber::operator-(const RealNumber& arg)
{
        //creating new variable
        RealNumber result;

	//substracting the two reals
	result.value = value - arg.get_value();
	return result;
}//end minus

RealNumber RealNumber::operator*(const RealNumber& arg)
{
	//creating new variable
	RealNumber result;

	//multiplying the two reals
	result.value = value * arg.get_value();
	return result;
}//end times

RealNumber RealNumber::operator/(const RealNumber& arg)
{
	//creating new variable
	RealNumber result;

	//dividing the two reals
	result.value = value / arg.get_value();
	return result;
}//end divided

/*************************************REAL & COMPLEX*********************************************/
ComplexNumber RealNumber::operator+(const ComplexNumber& arg)
{
	//adding a real and a complex number
	return ComplexNumber(value + arg.get_realComponent(), arg.get_imagComponent());

}//end plus

ComplexNumber RealNumber::operator-(const ComplexNumber& arg)
{
	//substracting a real and a complex
	return ComplexNumber(value - arg.get_realComponent(), - arg.get_imagComponent());

}//end minus

ComplexNumber RealNumber::operator*(const ComplexNumber& arg)
{
	//multiplying a real and a complex
	return ComplexNumber(value * arg.get_realComponent(), value * arg.get_imagComponent());

}//end times

ComplexNumber RealNumber::operator/(const ComplexNumber& arg)
{
	//dividing a real by a complex
	// d / (a + ib) = (da/(a^2 + b^2)) + i(-db/(a^2+b^2))
	return ComplexNumber((value * arg.get_realComponent()) / (arg.get_realComponent() * arg.get_realComponent() + arg.get_imagComponent()* arg.get_imagComponent()), -(value * arg.get_imagComponent()) / (arg.get_realComponent() * arg.get_realComponent() + arg.get_imagComponent() * arg.get_imagComponent()));

}//end divide

/*************************************REAL & RATIONAL********************************************/

RealNumber RealNumber::operator+(const RationalNumber& arg)
{
	//adding a real and a rational
	return RealNumber((arg.get_numerator() + value * arg.get_denominator()) / arg.get_denominator());

}//end plus

RealNumber RealNumber::operator-(const RationalNumber& arg)
{
	//substracting a real and a rational
	return RealNumber((value * arg.get_denominator() - arg.get_numerator()) / arg.get_denominator());

}//end minus

RealNumber RealNumber::operator*(const RationalNumber& arg)
{
	//multiplying a real and a rational
	return RealNumber(value * arg.get_numerator() / arg.get_denominator());

}//end times

RealNumber RealNumber::operator/(const RationalNumber& arg)
{
	//dividing a real and a rational
	return RealNumber(value * arg.get_denominator() / arg.get_numerator());

}//end divided

//to_String converts real and imaginary components to string of type a+bi
string RealNumber::to_String(void){
	stringstream my_output;
	my_output << value;
	return my_output.str();
}//end to_String
