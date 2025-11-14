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
	if (this != &obj)
		this->raw = obj.raw;
	return (*this);
}

Fixed::Fixed(const int value){
	std::cout << "Int constructor called\n";
	raw = value << bits;
}

Fixed::Fixed(const float value){
	std::cout << "Float constructor called\n";
	raw = roundf(value * (1 << bits));
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

int Fixed::toInt( void ) const{
	return (raw >> bits);
}

float Fixed::toFloat( void ) const{
	return ((float)raw / (1 << bits));
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj){
	out << obj.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& obj) const {
	return (this->raw > obj.raw);
}

bool Fixed::operator<(const Fixed& obj) const{
	return (this->raw < obj.raw);
}

bool Fixed::operator<=(const Fixed& obj) const{
	return (this->raw >= obj.raw);
}

bool Fixed::operator>=(const Fixed& obj) const{
	return (this->raw >= obj.raw);
}

bool Fixed::operator==(const Fixed& obj) const{
	return (this->raw == obj.raw);
}

bool Fixed::operator!=(const Fixed& obj) const{
	return (this->raw != obj.raw);
}

Fixed Fixed::operator+(const Fixed& obj) const{
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(const Fixed& obj) const{
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(const Fixed& obj) const{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(const Fixed& obj) const{
	return (this->toFloat() / obj.toFloat());
}

Fixed Fixed::operator++(int){
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed Fixed::operator++(){
	++this->raw;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed Fixed::operator--(){
	--this->raw;
	return (*this);
}

Fixed& Fixed::min(Fixed &obj1, Fixed &obj2){
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::min(const Fixed &obj1, const Fixed &obj2){
	if (obj1 < obj2)
		return (obj1);
	return (obj2);
}

Fixed& Fixed::max(Fixed &obj1, Fixed &obj2){
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2){
	if (obj1 > obj2)
		return (obj1);
	return (obj2);
}
