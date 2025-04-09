/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:34:56 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/26 12:56:46 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isAllDigits(const std::string& str)
{
	size_t i = 0;
	if(str[0] == '+' || str[0] == '-')
		i++;
	for(; i < str.length(); i++)
	{
		if(!std::isdigit(str[i]))
			return false;
	}
	return !str.empty();
}

bool check_input(int ac , char **av)
{
	for (int i = 1; i < ac; i++)
	{
		std::string tmp = av[i];

		if (!isAllDigits(tmp))
			return false;

		char* endPtr;
		long n = strtol(tmp.c_str(), &endPtr, 10);
		if (n < 0 || n > INT_MAX)
			return false;
	}
	return true;
}

template<typename T>
void Fill_Container(T &con, int ac, char **av)
{
	for (int i = 1; i < ac; i++)
		con.push_back(atoi(av[i]));
}

template<typename T>
void Print_Container(const T &con)
{
	typename T::const_iterator it;
	for (it=con.begin(); it != con.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
}

void Print_input(int ac, char **av)
{
	std::cout << "Before: ";
	for (int i = 1; i < ac; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if(ac < 2 || !check_input(ac, av))
	{
		std::cerr << "Error" <<std::endl;
		return 1;
	}

	Print_input(ac,av);

	std::clock_t start_v = std::clock();
	std::vector<int> vec;
	Fill_Container(vec, ac, av);
	PmergeMe::merge_insert_vec(vec);
	std::clock_t end_v = std::clock();

	std::cout << "After: ";
	Print_Container(vec);


	std::clock_t start_d = std::clock();
	std::deque<int> deq;
	Fill_Container(deq, ac, av);
	PmergeMe::merge_insert_deq(deq);
	std::clock_t end_d = std::clock();

	double time_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_v << " us" << std::endl;

	double time_d = static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC * 1000;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << time_d << " us" << std::endl;

	return 0;
}