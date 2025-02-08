/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:54 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/25 16:08:27 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <ostream>
#include <cmath>

class Fixed
{
	private:
		int Value;
		static const int fractionalbit = 8;
	public:

		Fixed();
		Fixed(const Fixed& var);
		Fixed& operator=(const Fixed& var);
		~Fixed();
		Fixed(const int intVlaue);
		Fixed(const float floatValue);

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
		// first part (>, <, >=, <=, ==, and !=)
		bool operator > (const Fixed &var) const;
		bool operator < (const Fixed &var) const;
		bool operator >= (const Fixed &var) const;
		bool operator <= (const Fixed &var) const;
		bool operator == (const Fixed &var) const;
		bool operator != (const Fixed &var) const;

		//second part + - * /
		Fixed operator + (const Fixed &var) const;
		Fixed operator - (const Fixed &var) const;
		Fixed operator * (const Fixed &var) const;
		Fixed operator / (const Fixed &var) const;

		//three part ++ --
		Fixed operator ++();
		Fixed operator ++(int);
		Fixed operator --();
		Fixed operator --(int);

		//four part
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& Fixed);
#endif
