#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	Fixed::_fixedPoint = other.getRawBits();
}

Fixed::Fixed(const int _fixedP){
	this->_fixedPoint = _fixedP << this->fractionBits;
}

Fixed::Fixed(const float _fixedP):
	_fixedPoint(round(_fixedP * (1 << this->fractionBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}


float Fixed::toFloat(void)const{
	return this->_fixedPoint / (1 << this->fractionBits);
}

int Fixed::toInt(void)const{
	return round(this->_fixedPoint);
}

Fixed & Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Operator overload called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPoint = rhs.getRawBits();
	}
	return *this;
}

void Fixed::setRawBits(int const raw){
	this->_fixedPoint = raw;
}

int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

std::ostream &operator<<(std::ostream &out ,Fixed const &rhs){
	return out << rhs.toFloat();
}