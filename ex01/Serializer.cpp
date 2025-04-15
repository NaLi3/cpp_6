/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:28:28 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/14 15:36:50 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void )
{
    std::cout << "Not instanciable lol" << std::endl;
}

Serializer::Serializer( const uintptr_t raw )
{
    (void) raw;
    std::cout << "Not instanciable lol" << std::endl;
}

Serializer::Serializer( const Serializer& copy )
{
    (void) copy;
    std::cout << "Not instanciable lol" << std::endl;
}

Serializer::~Serializer( void )
{
    std::cout << "Not instanciable lol" << std::endl;
}

Serializer& Serializer::operator=( const Serializer& src )
{
    (void) src;
    std::cout << "Not instanciable lol" << std::endl;
    return (*this);
}

uintptr_t	Serializer::serialize( Data *ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data		*Serializer::deserialize( uintptr_t raw )
{
	return(reinterpret_cast<Data *>(raw));
}
