/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:16:12 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/11/20 14:43:01 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctype.h>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		for (int i = 1;av[i];i++)
		{
			for (int j = 0;av[i][j];j++)
			{
				if (isalpha(av[i][j])){
					av[i][j] = toupper(av[i][j]);
					std::cout << av[i][j];
				}
				else
					std::cout << av[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
