#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed();
		Fixed(const Fixed &);
		Fixed(const int);
		Fixed(const float);
		~Fixed();
		Fixed & operator=(Fixed const &);
		void setRawBits(int const);
		int getRawBits(void) const;
		float toFloat(void) const;
		int	toInt(void) const;
	private:
		int	_fixedPoint;
		static const int fractionBits = 8;
};

std::ostream &operator<<(std::ostream &out, Fixed const &rhs);
#endif