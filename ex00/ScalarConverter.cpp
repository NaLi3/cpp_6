/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:53:24 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/14 13:48:59 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
    std::cout << "Not instanciable lol" << std::endl;
}

ScalarConverter::ScalarConverter( const std::string& literal )
{
	(void) literal;
    std::cout << "Not instanciable lol" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
	(void) copy;
    std::cout << "Not instanciable lol" << std::endl;
}

ScalarConverter::~ScalarConverter( void )
{
    std::cout << "Not instanciable lol" << std::endl;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter& src )
{
    (void) src;
    std::cout << "Not instanciable lol" << std::endl;
    return (*this);
}

void ScalarConverter::convert( const std::string& literal )
{
	char	c;
	int		i;
	float	f;
	double	d;
	int		type;

	type = detectLiteral(literal);
	switch (type)
	{
		case CHARACTER:
			c = literal[0];
			i = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break;
		case INTEGER:
			i = std::atoi(literal.c_str());
			c = static_cast<char>(i);
			f = static_cast<float>(i);
			d = static_cast<double>(i);
			break;
		case FLOAT:
			f = std::strtof(literal.c_str(), NULL);
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case DOUBLE:
			d = std::strtod(literal.c_str(), NULL);
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		case NAN_INF:
			f = std::strtof(literal.c_str(), NULL);
			d = std::strtod(literal.c_str(), NULL);
			i = 0;
			c = 0;
			break;
		default:
			std::cout << "Conversion error\n";
			return;
	}
	// Print char
	if (type != NAN_INF && std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else if (type != NAN_INF)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: impossible\n";
	// Print int
	if (type != NAN_INF)
		std::cout << "int: " << i << "\n";
	else
		std::cout << "int: impossible\n";
	// Print float
	std::cout << "float: " << f << "f\n";
	// Print double
	std::cout << "double: " << d << "\n";
}

int detectLiteral( const std::string& literal )
{
	bool found_dot = false;
	bool has_digit = false;
	bool has_f = false;
	int start = 0;

	if (literal.compare("-inff") == 0 || literal.compare("+inff") == 0\
		|| literal.compare("nanf") == 0 || literal.compare("-inf") == 0 \
			|| literal.compare("+inf") == 0 || literal.compare("nan") == 0)
		return (NAN_INF);
	if (literal.empty())
		return (ERROR);
	if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (CHARACTER);
	if (literal[start] == '-' || literal[start] == '+')
		start = 1;
	for (int i = start; i < static_cast<int>(literal.size()); i++)
	{
		if (std::isdigit(literal[i]))
		{
			has_digit = true;
			continue;
		}
		if (literal[i] == '.' && found_dot == false)
		{
			found_dot = true;
			continue;
		}
		if (literal[i] == 'f' && i == static_cast<int>(literal.size() - 1))
		{
			has_f = true;
			continue;
		}
		return (ERROR);
	}
	if (!has_digit)
		return (ERROR);
	if (found_dot && has_f)
		return (FLOAT);
	if (found_dot)
		return (DOUBLE);
	if (!found_dot && !has_f)
		return (INTEGER);
	return (ERROR);
}
