#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &input)
{
	int type = ScalarConverter::whatType(input);

	if (type == ScalarConverter::CHAR) {
		char c = ScalarConverter::strToChar(input);
		ScalarConverter::convertChar(c);
	}
	else if (type == ScalarConverter::INT) {
		int n = ScalarConverter::strToInt(input);
		ScalarConverter::convertInt(n);
	}
	else if (type == ScalarConverter::FLOAT) {
		float n = ScalarConverter::strToFloat(input);
		ScalarConverter::convertFloat(n);
	}
	else if (type == ScalarConverter::DOUBLE) {
		double n = ScalarConverter::strToDouble(input);
		ScalarConverter::convertDouble(n);
	}
}

void ScalarConverter::printChar(char c, bool isPrintable)
{
	std::cout << "char: ";
	if (isPrintable)
		std::cout << "impossible" << std::endl;
	else if (c < 33 || c > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

}
void ScalarConverter::printInt(int n, bool isPrintable)
{
	std::cout << "int: ";
	if (isPrintable)
		std::cout << "impossible" << std::endl;
	else
		std::cout << n << std::endl;
}
void ScalarConverter::printFloat(float n, bool isPrintable)
{
	std::cout << "float: ";
	if (isPrintable)
		std::cout << "impossible" << std::endl;
	else
	{
		if (isinff(n) && n > 0)
			std::cout << "+";
		std::cout << n << (ScalarConverter::isFloatRound(n) ? ".0" : "") << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double n, bool isPrintable)
{
	std::cout << "double: ";

	if (isPrintable)
		std::cout << "impossible" << std::endl;
	else
	{
		if (std::isinf(n) && n > 0)
			std::cout << "+";
		std::cout << n << (ScalarConverter::isDoubleRound(n) ? ".0" : "") << std::endl;
	}
}

bool ScalarConverter::isFloatRound(float n)
{
	return std::fabs(n - static_cast<float>(static_cast<int>(n))) == 0;
}

bool ScalarConverter::isDoubleRound(double n)
{
	return std::fabs(n - static_cast<double>(static_cast<int>(n))) == 0;
}

char ScalarConverter::strToChar(const std::string &str)
{
	return (str[0]);
}

int ScalarConverter::strToInt(const std::string &str)
{
	const long convertion = std::strtol(str.c_str(), NULL, 10);

	if (convertion > INT_MAX || convertion < INT_MIN)
		throw std::out_of_range("int overflow");
		
	return (static_cast<int>(convertion));
}

float ScalarConverter::strToFloat(const std::string &str)
{
	const float convertion = std::strtof(str.c_str(), NULL);

	if (errno == ERANGE)
		throw std::out_of_range("float overflow");
	
	return (convertion);
}

double ScalarConverter::strToDouble(const std::string &str)
{
	const double convertion = std::strtod(str.c_str(), NULL);

	if (errno == ERANGE)
		throw std::out_of_range("double overflow");
	
	return (convertion);
}

void ScalarConverter::convertChar(char c)
{
	ScalarConverter::printChar(c, 0);
	ScalarConverter::printInt(static_cast<int>(c), 0);
	ScalarConverter::printFloat(static_cast<float>(c), 0);
	ScalarConverter::printDouble(static_cast<double>(c), 0);
}

void ScalarConverter::convertInt(int n)
{
	ScalarConverter::printChar(static_cast<char>(n), (n < 0 || n > 127));
	ScalarConverter::printInt(n, 0);
	ScalarConverter::printFloat(static_cast<float>(n), 0);
	ScalarConverter::printDouble(static_cast<double>(n), 0);
}

void ScalarConverter::convertFloat(float n)
{
	ScalarConverter::printChar(static_cast<char>(n), (n < 0.0f || n > 127.0f || std::isnan(n) || isinff(n)));
	ScalarConverter::printInt(static_cast<int>(n), (std::isnan(n) || isinff(n) || (static_cast<double>(n) > INT_MAX || static_cast<double>(n) <= INT_MIN)));
	ScalarConverter::printFloat(n, 0);
	ScalarConverter::printDouble(static_cast<double>(n), 0);
}

void ScalarConverter::convertDouble(double n)
{
	ScalarConverter::printChar(static_cast<char>(n), (n < 0.0 || n > 127.0 || std::isnan(n) || std::isinf(n)));
	ScalarConverter::printInt(static_cast<int>(n), (std::isnan(n) || std::isinf(n)));
	ScalarConverter::printFloat(static_cast<float>(n), 0);
	ScalarConverter::printDouble(n, 0);
}
int ScalarConverter::whatType(const std::string &str)
{
	if (str.length() == 0)
		throw std::invalid_argument("Empty string");
	if (str.length() == 1)
	{
		if (std::isdigit(str[0]))
			return (ScalarConverter::INT);
		else
			return (ScalarConverter::CHAR);
	}
	
	if (str.compare("-inff") == 0 || str.compare("+inff") == 0 || str.compare("nanf") == 0)
		return (ScalarConverter::FLOAT);

	if (str.compare("-inf") == 0 || str.compare("+inf") == 0 || str.compare("nan") == 0)
		return (ScalarConverter::DOUBLE);
	
	bool hasPoint = false;
	for (long unsigned int i = (str[0] == '-'); i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			if (str[i] == '.' && !hasPoint && i != str.length() - 1)
				hasPoint = true;
			else if ((str[i] == 'f') && hasPoint && (i == str.length() - 1) && i != 0 && str[i - 1] != '.')
				return (ScalarConverter::FLOAT);
			else
				throw (std::invalid_argument("Invalid argument"));
		}
	}

	char *end;
	if (hasPoint)
		return (ScalarConverter::DOUBLE);
	else if (std::strtol(str.c_str(), &end, 10) > INT_MAX || std::strtol(str.c_str(), &end, 10) < INT_MIN)
		return (ScalarConverter::FLOAT);
	else
		return (ScalarConverter::INT);
}