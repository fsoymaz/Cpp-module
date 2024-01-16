#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed {
private:
    int fixedPointValue;
    static const int fractionalBits = 8;

public:
    Fixed();
    Fixed(const int intToFix);
    Fixed(const float floatToFix);
    ~Fixed();
    Fixed(const Fixed &copy);
    float toFloat( void ) const;
    int toInt( void ) const;

    int getFixedPointValue() const;

    void setFixedPointValue(int fixedPointValue);


    bool operator>(const Fixed &number);
    bool operator<(const Fixed &number);
    bool operator>=(const Fixed &number);
    bool operator<=(const Fixed &number);
    bool operator==(const Fixed &number);
    bool operator!=(const Fixed &number);
    Fixed &operator=(const Fixed &number);
    Fixed operator+(const Fixed &number);
    Fixed operator-(const Fixed &number);
    Fixed operator*(const Fixed &number);
    Fixed operator/(const Fixed &number);
    Fixed operator++(int);
    Fixed &operator++();
    Fixed operator--(int);
    Fixed &operator--();
    static Fixed &min(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);
};


std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
