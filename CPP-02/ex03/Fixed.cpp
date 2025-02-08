/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:17:11 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/28 14:48:35 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : Value(0)
{

}

Fixed::Fixed(const Fixed& var)
{
	*this = var;
}

Fixed& Fixed::operator=(const Fixed& var)
{
	if (this != &var)
		this->Value = var.getRawBits();
	return *this;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits() const
{
	return this->Value;
}

void Fixed::setRawBits(int const raw)
{
	this->Value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed)
{
	out << Fixed.toFloat();
	return out;
}

Fixed::Fixed(const int intVlaue)
{
	this->Value = intVlaue << fractionalbit;
}

Fixed::Fixed(const float floatValue)
{
	this->Value = static_cast<int>(roundf(floatValue * (1 << fractionalbit)));
}

int Fixed::toInt() const
{
	return (this->Value >> fractionalbit);
}

float Fixed::toFloat() const
{
	return (static_cast<float>(this->Value) / (1 << fractionalbit));
}
// first part
bool Fixed::operator > (const Fixed &var) const
{
	return (this->Value > var.Value);
}

bool Fixed::operator < (const Fixed &var) const
{
	return (this->Value < var.Value);
}

bool Fixed::operator >= (const Fixed &var) const
{
	return (this->Value >= var.Value);
}

bool Fixed::operator <= (const Fixed &var) const
{
	return (this->Value <= var.Value);
}

bool Fixed::operator == (const Fixed &var) const
{
	return (this->Value == var.Value);
}

bool Fixed::operator != (const Fixed &var) const
{
	return (this->Value != var.Value);
}

//second part * / - +

Fixed Fixed::operator + (const Fixed &var) const
{
	return Fixed(this->toFloat() + var.toFloat());
}

Fixed Fixed::operator - (const Fixed &var) const
{
	return Fixed(this->toFloat() - var.toFloat());
}

Fixed Fixed::operator * (const Fixed &var) const
{
	return (this->toFloat() * var.toFloat());
}

Fixed Fixed::operator / (const Fixed &var) const
{
	if(var.Value == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / var.toFloat());
}

//three part

Fixed Fixed::operator ++ ()
{
	this->Value++;
	return *this;
}

Fixed Fixed::operator ++ (int)
{
	Fixed tmp = *this;
	++(*this);
	return tmp;
}

Fixed Fixed::operator -- ()
{
	this->Value--;
	return *this;
}

Fixed Fixed::operator -- (int)
{
	Fixed tmp = *this;
	--(*this);
	return tmp;
}

//four part

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return ((a <= b) ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a <= b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return ((a >= b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a >= b) ? a : b);
}
