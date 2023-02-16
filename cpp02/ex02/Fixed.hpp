#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed const &);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		void setRawBits(int const);
		int getRawBits(void) const;
		int toInt(void) const;
		float toFloat(void) const;

		bool	operator>(Fixed const &)const;
		bool	operator <(Fixed const &)const;
		bool	operator >=(Fixed const &)const;
		bool	operator <=(Fixed const &)const;
		bool	operator ==(Fixed const &)const;
		bool	operator !=(Fixed const &)const;
		Fixed&	operator =(Fixed const &);
		Fixed	operator +(Fixed const &)const;
		Fixed	operator -(Fixed const &)const;
		Fixed	operator *(Fixed const &)const;
		Fixed	operator /(Fixed const &)const;
		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static Fixed&	min(Fixed &obj1, Fixed &obj2);
		static Fixed&	max(Fixed &obj1, Fixed &obj2);
		static const Fixed&	min(Fixed const &obj1, Fixed const &obj2);
		static const Fixed& max(Fixed const &obj1, Fixed const&obj2);

	private:
		int	_fixedPoint;
		static const int fractionBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &rhs);
#endif