/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-taj <mait-taj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:32:17 by mait-taj          #+#    #+#             */
/*   Updated: 2025/02/05 11:10:05 by mait-taj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		exit(EXIT_SUCCESS);
	}
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			std::cout << static_cast<char>(std::toupper(av[i][j++]));
		i++;
	}
	std::cout << std::endl;
	return (0);
}
