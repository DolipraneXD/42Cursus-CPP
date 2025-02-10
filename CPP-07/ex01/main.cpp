/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:53:25 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/08 11:15:11 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(T& element)
{
    std::cout << element << " ";
}


void increment(int& element)
{
    element += 1;
}


void toUpper(std::string& str)
{
    for (size_t i = 0; i < str.length(); ++i)
    {
        str[i] = toupper(str[i]);
    }
}

int main()
{
	// Test with an array of integers
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original int array: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intLength, increment);
	std::cout << "After increment: ";
	iter(intArray, intLength, printElement<int>);
	std::cout << std::endl;

	// Test with an array of strings
	std::string strArray[] = {"hello", "world", "cpp"};
	size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << "Original string array: ";
	iter(strArray, strLength, printElement<std::string>);
	std::cout << std::endl;

	iter(strArray, strLength, toUpper);
	std::cout << "After toUpper: ";
	iter(strArray, strLength, printElement<std::string>);
	std::cout << std::endl;

	return 0;
}