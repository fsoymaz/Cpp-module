/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsoymaz <fsoymaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 20:05:39 by fsoymaz           #+#    #+#             */
/*   Updated: 2023/10/24 20:32:48 by fsoymaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr <<  "LOUD AND UNBEARABLE FEEDBACK NOISE" << std::endl;
		return (1);
	}
	for (int i = 1; av[i]; i++)
	{
		for (int j = 0; av[i][j]; j++)
			std::cout << (char)toupper(av[i][j]);
		if (av[i + 1] != NULL)
			std::cout << ' ';
	}
	return (0);
}
