/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:17:11 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/25 15:46:22 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : Value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& var)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = var;
}

Fixed& Fixed::operator=(const Fixed& var)
{
	std::cout<< "Copy assignment operator calle" << std::endl;
	if (this != &var)
		this->Value = var.Value;
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->Value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->Value = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed)
{
	out << Fixed.toFloat();
	return out;
}

Fixed::Fixed(const int intVlaue)
{
	std::cout << "Int constructor called" << std::endl;
	this->Value = intVlaue << fractionalbit;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
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
