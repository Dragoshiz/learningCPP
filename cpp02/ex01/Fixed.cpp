#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int _fixedP){
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPoint = _fixedP << this->fractionBits;
}

Fixed::Fixed(const float _fixedP):
	_fixedPoint(roundf(_fixedP * (1 << this->fractionBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


float Fixed::toFloat(void)const{
	return (float)this->_fixedPoint / (1 << this->fractionBits);
}

int Fixed::toInt(void)const{
	return roundf(this->_fixedPoint /(1 << this->fractionBits));
}


void Fixed::setRawBits(int const raw){
	this->_fixedPoint = raw;
}

int Fixed::getRawBits(void)const{
	return this->_fixedPoint;
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out ,Fixed const &rhs){
	return out << rhs.toFloat();
}