/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:32:54 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/15 16:56:02 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

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
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif
