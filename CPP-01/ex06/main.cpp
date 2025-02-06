/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:09:59 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/12 16:18:14 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
	Harl first;
	if (ac != 2)
	{
		std::cout << "error: bad arguments" <<std::endl;
		return (1);
	}
	std::string level;
	level = av[1];
	first.complain(level);

}
