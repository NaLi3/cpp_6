/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:28:32 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/14 17:20:42 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define RED "\033[31m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define BLUE  "\033[34m"
# define RESET  "\033[0m"

typedef struct Data
{
	std::string name;
	size_t		age;
	Data		*next;
}				Data;

class Serializer
{
	private:
		Serializer( void );
		Serializer( const uintptr_t raw );
		Serializer( const Serializer& copy );
		Serializer& operator=( const Serializer& src );
		~Serializer( void );
	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*		deserialize( uintptr_t raw );
};

#endif
