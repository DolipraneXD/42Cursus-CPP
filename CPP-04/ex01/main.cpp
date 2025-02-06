/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-fat <moel-fat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:03:53 by moel-fat          #+#    #+#             */
/*   Updated: 2024/12/29 16:22:03 by moel-fat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main() {
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\nTesting deep copies:" << std::endl;
    Dog dog1;
    dog1.makeSound();

    Dog dog2 = dog1;
    Dog dog3;
    dog3 = dog1;

    Cat cat1;
    cat1.makeSound();

    Cat cat2 = cat1;
    Cat cat3;
    cat3 = cat1;

    return 0;
}
