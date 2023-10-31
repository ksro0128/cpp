#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = num << this->fractional_bits;
}
Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number = roundf(num * (1 << this->fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &fixed)
		return (*this);
	this->fixed_point_number = fixed.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}
bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed rt(this->toFloat() + fixed.toFloat());
	return (rt);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed rt(this->toFloat() - fixed.toFloat());
	return (rt);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed rt(this->toFloat() * fixed.toFloat());
	return (rt);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed rt(this->toFloat() / fixed.toFloat());
	return (rt);
}

Fixed	&Fixed::operator++(void)
{
	(this->fixed_point_number)++;
	return (*this);
}

const Fixed	Fixed::operator++(int)
{
	const Fixed rt(*this);

	(this->fixed_point_number)++;
	return (rt);
}

Fixed	&Fixed::operator--(void)
{
	(this->fixed_point_number)--;
	return (*this);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed rt(*this);

	(this->fixed_point_number)--;
	return (rt);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_point_number);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixed_point_number = raw;
}

int	Fixed::toInt(void) const
{
	return (this->fixed_point_number >> this->fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)this->fixed_point_number / (float)(1 << this->fractional_bits));
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}