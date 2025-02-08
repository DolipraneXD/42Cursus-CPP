/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:46:33 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/06 13:46:35 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
# include <iostream>
# include <string>
# include <limits>
# include <cerrno>
# include <cmath>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void convert(char* var);
};