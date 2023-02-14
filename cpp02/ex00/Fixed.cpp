#include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	_fixedPoint_nbr = 0;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator = (Fixed const & rhs)
{
	std::cout << "Operator overload called" << std::endl;
	if (this != &rhs)
	{
		this->_fixedPoint_nbr = rhs.getRawBits();
	}
	return *this;
}

void Fixed::setRawBits(int const raw){
	this->_fixedPoint_nbr = raw;
}

int Fixed::getRawBits(void)const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint_nbr;
}