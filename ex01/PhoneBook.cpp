/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:50:29 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/06 09:58:21 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	geting_line(std::string &str)
{
	if (!getline(std::cin, str))
		exit(EXIT_FAILURE);
	while (str.empty())
	{
		std::cout << "fill this field to continue\n>";
		if (!getline(std::cin, str))
			exit(EXIT_FAILURE);
	}
}
void	set_border(t_info type)
{
	if (type == TOP)
		std::cout << " -------------------------------------------" << std::endl;
	else if (type == BOTTOM)
		std::cout << "|-------------------------------------------|" << std::endl;
	else if (type == CENTER)
		std::cout << "--------------------------------" << std::endl;
}

PhoneBook::PhoneBook() { }

void	PhoneBook::add_contact(int index) {
	std::string	temp;
	set_border( CENTER );
	std::cout << std::right << std::setw( 18 ) << "Contact[" << ( index + 1 ) << "/8]" << std::endl;
	set_border(CENTER);
	std::cout << "\nEnter first name:\n>";
	geting_line(temp);
	arr[ index ].set_contact_info( FIRST_NAME, temp );
	std::cout << "Enter last name:\n>";
	geting_line(temp);
	arr[ index ].set_contact_info( LAST_NAME, temp );
	std::cout << "Enter Nickname:\n>";
	geting_line(temp);
	arr[ index ].set_contact_info( NICKNAME, temp );
	std::cout << "Enter Phone Number:\n>";
	geting_line( temp );
	arr[ index ].set_contact_info( PHONE_NUMBER, temp );
	std::cout << "Enter a Darkest Secret:\n>";
	geting_line( temp );
	arr[ index ].set_contact_info( DARKEST_SECRET, temp );
	std::cout << "\n>>>>> contact [" << ( index + 1 ) << "] saved succesfuly <<<<<" << std::endl;
}

void	PhoneBook::display_all_contacts()
{
	int	index = 0;
	set_border( TOP );
	PRINT_PIPE;
	std::cout
		<< std::setw( 10 ) << std::right << "index" << '|' 
		<< std::setw( 10 ) << "first name" << '|'
		<< std::setw( 10 )<< "last name" << '|'
		<< std::setw( 10 ) << "nickname" << '|' << std::endl;
	set_border( BOTTOM );
	while ( ++index <= 8 && arr[ index - 1 ].get_contact_info( FIRST_NAME ).length() > 0 )
	{
		PRINT_PIPE;
		std::cout << std::setw(10) << std::right << (index) << '|'
			<< std::setw(10) << std::right
			<< ( arr[ index - 1 ].get_contact_info( FIRST_NAME ).length() > 10 ? arr[ index - 1 ].get_contact_info( FIRST_NAME ).substr( 0, 9 ) + "." : arr[ index - 1 ].get_contact_info( FIRST_NAME  ))  << '|'
			<< std::setw(10) << std::right
			<< ( arr[ index - 1 ].get_contact_info( LAST_NAME ).length() > 10 ? arr[ index - 1 ].get_contact_info( LAST_NAME ).substr( 0, 9 ) + "." : arr[ index - 1 ].get_contact_info( LAST_NAME ) ) << '|'
			<< std::setw(10) << std::right
			<< ( arr[ index - 1] .get_contact_info( NICKNAME ).length() > 10 ? arr[ index - 1 ].get_contact_info( NICKNAME ).substr( 0, 9 ) + "." : arr[ index - 1 ].get_contact_info( NICKNAME ) ) << '|' << std::endl;	
			
		set_border(BOTTOM);
	}
}

void	PhoneBook::display_specific_contact( int index )
{
	if ( index < 1 && index > 8  )
		std::cout << "Index is out of range {1,8}" << std::endl;
	else
	{
		if ( arr[ index ].get_contact_info( FIRST_NAME ).length() == 0 ) {
			std::cout << "\nContact `" << index + 1 << "` not found!"<< std::endl; 
			return ;
		}
		std::cout << arr[ index ].get_contact_info( FIRST_NAME ) << std::endl;
		std::cout << arr[ index ].get_contact_info( LAST_NAME ) << std::endl;
		std::cout << arr[ index ].get_contact_info( NICKNAME ) << std::endl;
		std::cout << arr[ index ].get_contact_info( PHONE_NUMBER ) << std::endl;
		std::cout << arr[ index ].get_contact_info( DARKEST_SECRET ) << std::endl;
	}
}