/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:39:38 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:05:13 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>
#include <string>

struct MateriaNode
{
    AMateria* materia;
    MateriaNode* next;

    MateriaNode(AMateria* m);
};

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];
        MateriaNode* unequippedHead;

    public:
        Character(std::string const & name);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

    private:
        void clearInventory();
        void copyInventory(const Character& other);
        void clearUnequipped();
};

#endif
