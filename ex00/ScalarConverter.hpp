#pragma once

#include <iostream>

class ScalarConverter
{
	public:
		virtual ~ScalarConverter();
		
		ScalarConverter &operator=(const ScalarConverter &src);
		
		static void convert(const std::string &input);
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);

		enum e_type {
			INT,
			FLOAT,
			CHAR,
			DOUBLE
		};

		static void printChar(char c, bool isPrintable);
};