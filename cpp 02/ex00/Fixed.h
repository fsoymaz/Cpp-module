#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
  private:
	int value;
	static const int bits = 8;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	int getRawBits() const;
	void setRawBits(int const raw);
	~Fixed();
};

#endif
