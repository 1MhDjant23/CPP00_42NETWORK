/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:35:50 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/16 16:57:51 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

Contact::Contact() { }

Contact::~Contact() { }

void	Contact::set_contact_info( t_info type, std::string info )
{
	 
	if ( type == FIRST_NAME )
		_first_name = info;
	else if ( type == LAST_NAME )
		_last_name = info;
	else if ( type == NICKNAME )
		_nickname = info;
	else if ( type == PHONE_NUMBER )
		_phone_number = info;
	else if ( type == DARKEST_SECRET )
		_darkest_secret = info;
}

std::string	Contact::get_contact_info( t_info type )
{
	if (type == FIRST_NAME)
		return (_first_name);
	if (type == LAST_NAME)
		return (_last_name);
	if (type == NICKNAME)
		return (_nickname);
	if (type == PHONE_NUMBER)
		return (_phone_number);
	return (_darkest_secret);
}

void	search( PhoneBook my_book )
{
	std::string	input;

	my_book.display_all_contacts();
	std::cout << "\nEnter index of contact:\n> ";
	if ( !getline(std::cin, input) )
		exit(EXIT_FAILURE);
	std::size_t posLeft = input.find_first_not_of(" \t" );
	std::size_t	posRight = input.find_last_not_of( " \t" );
	if ( posRight == std::string::npos && posLeft == std::string::npos )
		return ;
	input = input.substr( posLeft, posRight - posLeft + 1 );
	if ( input.size() == 1 && std::isdigit( input[0] ) )
		my_book.display_specific_contact( input[0] - 48 );
	else
		std::cerr << "Error, invalid index" << std::endl;
}
