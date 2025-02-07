/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:36:10 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/06 10:00:08 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define	PHONEBOOK_HPP
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Contact.hpp"
#define	PRINT_PIPE std::cout << '|';

class	PhoneBook
{
	private:
    	Contact arr[8];
	public:
		PhoneBook();
		void	add_contact( int index );
		void	display_specific_contact( int index );
		void	display_all_contacts();
};

void	set_border( t_info typ );
void	search( PhoneBook my_book );

#endif
