/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:46:46 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/07 14:29:15 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "invalid unput only one argument is allowed" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);

	return 0;
}