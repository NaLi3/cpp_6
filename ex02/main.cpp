/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 11:19:59 by ilevy             #+#    #+#             */
/*   Updated: 2025/04/15 12:42:18 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

Base	*generate( void );
void	identify( Base *p );
void 	identify(Base &p);


int	main( void )
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		std::cout << "--------------------------------------" << std::endl;
		Base *p = generate();
		Base& p_ref = *p;
		std::cout << "Here is the pointer identification method:" << std::endl;
		identify(p);
		std::cout << "Here is the reference identification method:" << std::endl;
		identify(p_ref);
		delete p;
		if (i != 4)
			std::cout << "\n" << std::endl;
	}
}
