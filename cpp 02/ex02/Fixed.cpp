#include "Fixed.h"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(const int intValue) : fixedPointValue(intValue
	* (1 << fractionalBits))
{
}

Fixed::Fixed(const float floatValue) : fixedPointValue(roundf(floatValue
		* (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed &copy)
{
	fixedPointValue = copy.fixedPointValue;
	getFixedPointValue();
}

Fixed::~Fixed()
{
}

float Fixed::toFloat() const
{
	return (float(fixedPointValue) / (1 << fractionalBits));
}

int Fixed::toInt() const
{
	return (fixedPointValue >> fractionalBits);
}

Fixed &Fixed::operator=(const Fixed &copy)
{
	fixedPointValue = copy.fixedPointValue;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

int Fixed::getFixedPointValue() const
{
	return (fixedPointValue);
}

void Fixed::setFixedPointValue(int fixedPointValue)
{
	this->fixedPointValue = fixedPointValue;
}

bool Fixed::operator>(const Fixed &number)
{
	return (this->fixedPointValue > number.fixedPointValue);
}

bool Fixed::operator<(const Fixed &number)
{
	return (this->fixedPointValue < number.fixedPointValue);
}

bool Fixed::operator>=(const Fixed &number)
{
	return (this->fixedPointValue >= number.fixedPointValue);
}

bool Fixed::operator<=(const Fixed &number)
{
	return (this->fixedPointValue <= number.fixedPointValue);
}

bool Fixed::operator==(const Fixed &number)
{
	return (this->fixedPointValue == number.fixedPointValue);
}

bool Fixed::operator!=(const Fixed &number)
{
	return (this->fixedPointValue != number.fixedPointValue);
}

Fixed Fixed::operator+(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() + number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator-(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() - number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator*(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() * number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator/(const Fixed &number)
{
	Fixed returnvalue(this->toFloat() / number.toFloat());
	return (returnvalue);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->fixedPointValue++;
	return (tmp);
}

Fixed &Fixed::operator++()
{
	this->fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->fixedPointValue--;
	return (tmp);
}

Fixed &Fixed::operator--()
{
	this->fixedPointValue--;
	return (*this);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.fixedPointValue < f2.fixedPointValue)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.fixedPointValue > f2.fixedPointValue)
		return (f1);
	return (f2);
}