/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:19:06 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/10 18:38:56 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
# define FragTrap_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap& var);
		FragTrap& operator=(const FragTrap& var);
		~FragTrap();
		FragTrap(const std::string &name);
		void attack(const std::string& target);
		void highFivesGuys(void);
};

#endif
