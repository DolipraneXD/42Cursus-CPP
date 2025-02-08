/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:37:37 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/14 16:01:53 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string Name;
		unsigned int Hit;
		unsigned int Energy;
		unsigned int Attack;

	public:
		// Constructors and Destructor
		ClapTrap();
		ClapTrap& operator=(const ClapTrap& other);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap(const std::string& name);
		// Member Functions
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif
