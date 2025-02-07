/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:42:36 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/06 10:00:35 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP
#include "PhoneBook.hpp"

typedef	enum s_info
{
	FIRST_NAME,
	LAST_NAME,
	NICKNAME,
	PHONE_NUMBER,
	DARKEST_SECRET,
    TOP,
    BOTTOM,
    CENTER
}	t_info;

class   Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;
    public:
        Contact();
        std::string get_contact_info( t_info type );
        void	    set_contact_info( t_info type, std::string info );
};

#endif