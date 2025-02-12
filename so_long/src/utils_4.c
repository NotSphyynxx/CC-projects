/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:24:33 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 14:45:05 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_path(char **map, char **cmap, int *player)
{
	int	j;
	int	k;

	k = -1;
	j = -1;
	while (map[++j])
	{
		k = -1;
		while (map[j][++k])
		{
			if ((map[j][k] == 'C' || map[j][k] == 'E') &&
				cmap[j][k] != 'V')
			{
				ft_printf("Error\nInvalid path\n");
				free(player);
				free_map(cmap);
				exit(1);
			}
		}
	}
}

void	free_row(char **cmap, int j)
{
	while (j > 0)
	{
		free(cmap[j - 1]);
		j--;
	}
	free(cmap);
}
