#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		~Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		bool	operator>(Fixed const &fixed) const;
		bool	operator>=(Fixed const &fixed) const;
		bool	operator<(Fixed const &fixed) const;
		bool	operator<=(Fixed const &fixed) const;
		bool	operator==(Fixed const &fixed) const;
		bool	operator!=(Fixed const &fixed) const;
		Fixed	operator+(Fixed const &fixed) const;
		Fixed	operator-(Fixed const &fixed) const;
		Fixed	operator*(Fixed const &fixed) const;
		Fixed	operator/(Fixed const &fixed) const;
		Fixed	&operator++(void);
		const Fixed	operator++(int);
		Fixed	&operator--(void);
		const Fixed	operator--(int);
		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(Fixed const &a, Fixed const &b);
		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(Fixed const &a, Fixed const &b);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					fixed_point_number;
		static const int	fractional_bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif