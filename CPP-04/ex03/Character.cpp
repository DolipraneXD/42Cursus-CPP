/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:39:31 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:19:00 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

MateriaNode::MateriaNode(AMateria* m) : materia(m), next(NULL) {}

Character::Character(std::string const & name) : 
    name(name), 
    unequippedHead(NULL)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
}

Character::Character(const Character& other) : 
    name(other.name), 
    unequippedHead(NULL)
{
    for (int i = 0; i < 4; ++i)
        inventory[i] = NULL;
    copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        clearInventory();
        clearUnequipped();
        name = other.name;
        copyInventory(other);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
    clearUnequipped();
}

std::string const & Character::getName() const
{
    return name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;

    for (int i = 0; i < 4; ++i) {
        if (!inventory[i]) {
            inventory[i] = m;
            return;
        }
    }
    // If inventory is full, add to unequipped list
    MateriaNode* newNode = new MateriaNode(m);
    newNode->next = unequippedHead;
    unequippedHead = newNode;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        MateriaNode* newNode = new MateriaNode(inventory[idx]);
        newNode->next = unequippedHead;
        unequippedHead = newNode;
        inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx]) {
        inventory[idx]->use(target);
    }
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; ++i) {
        delete inventory[i];
        inventory[i] = NULL;
    }
}

void Character::clearUnequipped()
{
    while (unequippedHead) {
        MateriaNode* toDelete = unequippedHead;
        unequippedHead = unequippedHead->next;
        delete toDelete->materia;
        delete toDelete;
    }
}

void Character::copyInventory(const Character& other)
{
    // Copy inventory
    for (int i = 0; i < 4; ++i) {
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = NULL;
    }
    
    // Copy unequipped list
    MateriaNode* current = other.unequippedHead;
    MateriaNode** tail = &unequippedHead;
    
    while (current) {
        *tail = new MateriaNode(current->materia->clone());
        tail = &((*tail)->next);
        current = current->next;
    }
    *tail = NULL;
}
