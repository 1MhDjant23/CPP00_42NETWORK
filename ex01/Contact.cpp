/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:35:50 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/06 09:53:08 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
Contact::Contact() { }

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
	int	index;
	std::string	input;

	my_book.display_all_contacts();
	std::cout << "\nEnter index of contact:\n> ";
	if ( !getline(std::cin, input) )
		exit(EXIT_FAILURE);
	std::stringstream	inputTreat( input );
	inputTreat >> index;
	if ( inputTreat.fail() && !inputTreat.eof() )
		std::cerr << "Error, invalid index" << std::endl;
	else if ( index >= 1 && index <= 8 )
		my_book.display_specific_contact( index - 1 );
	else if ( inputTreat.eof() && input.empty() )
		std::cout << ">>> You got nothing in, so re-start again <<<" << std::endl;
	else if ( index < 1 || index > 8 )
		std::cerr << "Index you entered is out of range {1,8}" << std::endl;
}
