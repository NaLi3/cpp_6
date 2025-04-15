/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:28:34 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/14 17:58:05 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	Data ptr2;
	ptr2.name = "Viego";
	ptr2.age = 42;
	ptr2.next = NULL;

	Data ptr;
	ptr.name = "Isolde";
	ptr.age = 42;
	ptr.next = &ptr2;


	std::cout << "Here are the original structs:" <<
				"\n\taddress: " << &ptr <<
				"\n\tname: " << ptr.name <<
				"\n\tage: " << ptr.age <<
				"\n\taddress next: " << ptr.next <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tname: " << ptr2.name <<
				"\n\tage: " << ptr2.age <<
				"\n\taddress next: " << ptr2.next <<
	std::endl << std::endl;

	uintptr_t serialized_ptr = Serializer::serialize(&ptr);
	Data *reserialized_struct = Serializer::deserialize(serialized_ptr);

	std::cout << "Here are the reserialized structs:" <<
				"\n\taddress: " << reserialized_struct <<
				"\n\tname: " << reserialized_struct->name <<
				"\n\tage: " << reserialized_struct->age <<
				"\n\taddress next: " << reserialized_struct->next <<
	std::endl;
	std::cout << "\taddress ptr2: " << &ptr2 <<
				"\n\tname: " << ptr2.name <<
				"\n\tage: " << ptr2.age <<
				"\n\taddress next: " << ptr2.next <<
	std::endl << std::endl;
	return (0);
}
