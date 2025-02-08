#pragma once 
# include <iostream>
# include <string>
# include <limits>
# include <cerrno>
# include <cmath>
# include <climits>
# include <cfloat>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	private:
        ScalarConverter();

    public:
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();
        
        static void convert(char* var);
};