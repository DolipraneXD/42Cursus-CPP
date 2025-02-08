/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:00:28 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/12 17:01:37 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string Name; // Renamed from Name to _name to avoid shadowing

	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap& var);
		DiamondTrap& operator=(const DiamondTrap& var);
		~DiamondTrap();
		DiamondTrap(const std::string& var);

		void attack(const std::string& target);
		void whoAmI();
};

#endif
