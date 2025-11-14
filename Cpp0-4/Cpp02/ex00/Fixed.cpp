#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called\n";
	raw = 0;
}

Fixed::Fixed(const Fixed &obj){
	std::cout << "Copy constructor called\n";
	this->raw = obj.raw;
}

Fixed& Fixed::operator=(const Fixed& obj){
	std::cout << "Copy assignment operator called\n";
	this->raw = obj.raw;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called\n";
	return (bits);
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called\n";
	this->raw = raw;
}