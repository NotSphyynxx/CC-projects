#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed{
	private:
		int raw;
		static const int bits;
	public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed& obj);
	Fixed(const int value);
	Fixed(const float value);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &num);

#endif