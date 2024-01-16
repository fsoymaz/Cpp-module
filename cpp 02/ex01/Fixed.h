#ifndef FIXED_H
# define FIXED_H

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int fixedPointValue;
	static const int fractionalBits = 8;

  public:
	Fixed();
	Fixed(const int intValue);
	Fixed(const float floatValue);
	Fixed(const Fixed &copy);
	~Fixed();

	float toFloat() const;
	int toInt() const;

	Fixed &operator=(const Fixed &copy);

	int getFixedPointValue() const;

	void setFixedPointValue(int fixedPointValue);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
#endif
