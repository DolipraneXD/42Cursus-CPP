/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:23:09 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:19:18 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
# include <string>
# include <iostream>

class ICharacter;
class AMateria
{
    protected:
        std::string type;
    
    public:
        AMateria();
        AMateria(const AMateria& other);
        AMateria& operator=(const AMateria& other);
        virtual ~AMateria();
    
        AMateria(std::string const & type);
        std::string const & getType() const;
    
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
