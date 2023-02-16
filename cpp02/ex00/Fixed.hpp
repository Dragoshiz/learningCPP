#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed & operator=(Fixed const & rhs);
		void setRawBits(int const raw);
		int getRawBits(void) const;
	private:
		int	_fixedPoint_nbr;
		static const int _fractionBits = 8;
};
#endif