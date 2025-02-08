/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:35:50 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/12 10:55:37 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 6;
	Zombie *holder = zombieHorde(N, "zizzo");
	if (!holder)
		return (0);
	for (int i = 0; i < N; i++)
	{
		holder[i].announce();
	}

	delete[] holder;

	return 0;
}
