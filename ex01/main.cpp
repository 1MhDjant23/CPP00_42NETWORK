/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:56:44 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/16 09:21:43 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string	parseInput( std::string& str ) {
	std::size_t	posLeft = str.find_first_not_of( " \t" );
	std::size_t	posRight = str.find_last_not_of( " \n" );
	return (( posLeft == std::string::npos && posRight == std::string::npos ) ? "" : str.substr( posLeft, posRight - posLeft + 1 ));
}

int	main()
{
	PhoneBook	my_book;
	std::string	user;
	int	index = 0;
	while ( true )
	{
		std::cout << "\n Enter one of the following command:\n"
			<< "\n* ADD 				( to save a new contact ).\n"
			<< "* SEARCH 			( to display saved contacts ).\n"
			<< "* EXIT 				( to quit program ).\n>";
		if ( !getline(std::cin, user) )
			exit(EXIT_FAILURE) ;
		user = parseInput( user );
		if ( user == "ADD" )
		{
			if ( index >= 8 )
				index = 0;
			my_book.add_contact( index );
			index++;
		}
		else if ( user == "SEARCH" )
			search( my_book );
		else if ( user == "EXIT" )
			exit(EXIT_SUCCESS);
	}
	return (0);
}
