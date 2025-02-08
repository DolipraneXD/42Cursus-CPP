/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 12:15:43 by moel-fat          #+#    #+#             */
/*   Updated: 2024/11/02 16:15:05 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
	private:
    	Contact contacts[8];
    	int index;
    	std::string truncate(const std::string& str) const;
	public:
    	PhoneBook();
    	void add();
    	void search();
};

#endif
