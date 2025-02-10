/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytest.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:25:41 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/09 11:31:13 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

int main()
{
	try{
		Array<int> arr(5);

		for (int i = 0; i < 5 ;i++)
		{
			arr [i] = (i * 10) +1;
		}

		for (int i = 0; i < 5 ;i++)
		{
			std::cout << arr[i] << '\n';
		}
			std::cout << arr[5] << '\n';
	}catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}