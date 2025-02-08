/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 11:36:20 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/06 16:10:02 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return (NULL);

	Zombie* ptr = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		ptr[i].setName(name);
	}

	return (ptr);
}
