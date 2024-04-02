#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	//std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	//std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	//std::cout << "ScalarConverter deconstructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this != &src)
	{
		//STUFF TO DO
	}
	return *this;
}