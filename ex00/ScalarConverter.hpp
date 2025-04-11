/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:20:47 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/11 12:03:17 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <stdexcept>
# include <cctype>

enum type_literal 
{
    CHARACTER,
    INTEGER,
    FLOAT,
    DOUBLE,
    ERROR
};

class ScalarConverter
{
    private:
        //Private constructors to avoid instantiability by user
        ScalarConverter( void );
        ScalarConverter( const std::string& lit );
        ScalarConverter( const ScalarConverter& copy );
        ScalarConverter& operator=( const ScalarConverter& src );
        ~ScalarConverter( void );
        
    public:
        static void convert( const std::string& literal );
};

int detectLiteral( const std::string& literal );

#endif