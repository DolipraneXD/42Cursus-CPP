/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:06:30 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/18 13:34:06 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error arguments" << std::endl;
		return 1;
	}
	RPN s;
	try {
		std::cout << s.calculator(av[1]) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}