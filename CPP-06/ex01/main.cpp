/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:17:39 by moel-fat          #+#    #+#             */
/*   Updated: 2025/02/06 12:39:08 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{

	Data originalData (42, "Serializer Test");

	// Serialize: Convert pointer to uintptr_t
	uintptr_t raw = Serializer::serialize(&originalData);

	// Deserialize: Convert uintptr_t back to Data*
	Data* deserializedData = Serializer::deserialize(raw);

	// Output and verification
	std::cout << "Original Data Address: " << &originalData << std::endl;
	std::cout << "Serialized Value: " << raw << std::endl;
	std::cout << "Deserialized Data Address: " << deserializedData << std::endl;

	if (deserializedData == &originalData) {
		std::cout << "Success: Deserialized pointer matches the original pointer!" << std::endl;
	} else {
		std::cout << "Error: Deserialized pointer does not match the original pointer!" << std::endl;
	}

	// Verify data integrity
	std::cout << "Deserialized Data ID: " << deserializedData->id << std::endl;
	std::cout << "Deserialized Data Name: " << deserializedData->name << std::endl;

	return 0;
}
