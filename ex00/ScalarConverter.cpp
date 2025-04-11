/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:53:24 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/11 12:05:09 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void )
{
    std::cout << "Not instanciable lol" << std::endl;
}

ScalarConverter::ScalarConverter( const std::string& literal )
{
    std::cout << "Not instanciable lol" << std::endl;
}

ScalarConverter::ScalarConverter( const ScalarConverter& copy )
{
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

static void ScalarConverter::convert( const std::string& literal )
{

}

int detectLiteral( const std::string& literal )
{
    //Find out if the literal string is a char.
    //If there's only one letter and it's not a number.
    if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
        return (CHARACTER);
    //Find out if the literal string is an int.
    //If there's only numbers (and -)
    int i = 0;
    for (; i < literal.size(); i++)
    {
        if (!std::isdigit(literal[i]))
        {
            if (i == 0 && literal[i] == '-')
                continue;
            break;
        }
    }
    if (i == literal.size())
        return (INTEGER);
    i = 0;
    bool found_dot = false;
    bool first_part = false;
    for (; i < literal.size(); i++)
    {
        if (std::isdigit(literal[i]) && first_part == false)
            first_part = true;
        if (!std::isdigit(literal[i]))
        {
            if (i == 0 && literal[i] == '-')
                continue;
            if (literal[i] == '.' && found_dot == false && first_part == true)
                continue;
            break;
        }
    }
    if (i == static_cast<int>(literal.size()) - 1 && literal[static_cast<int>(literal.size()) - 1] == 'f')
        return (FLOAT);
    else if (i == literal.size())
        return (DOUBLE);
    return (ERROR);
}