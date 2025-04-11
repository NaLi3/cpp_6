/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 10:29:10 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/11 10:37:23 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert [parameter_to_be_converted]" << std::endl;
        return (1);
    }
    std::string param = argv[1]; 
    // 1) Detect the type of literal passed as parameter.
    
    // 2) Convert the string to the type of literal found.
    // 3) Convert it EXPLICITLY to the three other data types
    // 4) Display with the format given as example.
    return (0);
}