#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "invalid unput only one argument is allowed" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return 0;
}