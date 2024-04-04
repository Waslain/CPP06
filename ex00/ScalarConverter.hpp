#pragma once

#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <cmath>

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
		static void printInt(int n, bool isPrintable);
		static void printFloat(float n, bool isPrintable);
		static void printDouble(double n, bool isPrintable);
		
		static bool isFloatRound(float n);
		static bool isDoubleRound(double n);
		
		static char strToChar(const std::string &str);
		static int strToInt(const std::string &str);
		static float strToFloat(const std::string &str);
		static double strToDouble(const std::string &str);

		static void convertChar(char c);
		static void convertInt(int n);
		static void convertFloat(float n);
		static void convertDouble(double n);

		static int whatType(const std::string &str);
};