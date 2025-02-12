/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:07:11 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:15:53 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_shape(char **map)
{
	size_t	line_length;
	size_t	i;

	if (!map || !map[0])
		exit(1);
	i = 1;
	line_length = ft_strlen(map[0]);
	while (map[i])
	{
		if (line_length != ft_strlen(map[i]))
		{
			ft_printf("Error\nThe map is not rectangular !\n");
			exit(1);
		}
		i++;
	}
}

void	check_char(char **map)
{
	char	*characters;
	int		i;
	int		k;

	characters = "01PEC";
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (!ft_strchr(characters, map[i][k]))
			{
				ft_printf("Invalid Character\n");
				exit(1);
			}
			k++;
		}
		i++;
	}
}

void	check_fl_row(char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (map[i][k])
	{
		if (!ft_strchr("1", map[i][k]))
		{
			ft_printf("Error\nProblem with top wall\n");
			close_error(map);
		}
		k++;
	}
	i++;
	check_bottom_wall(i, j, k, map);
}

void	check_walls(char **map)
{
	int	i;
	int	j;

	if (!map || !map[0])
	{
		ft_printf("Error\nEmpty map\n");
		close_error(map);
	}
	i = 0;
	check_fl_row(map);
	while (map[++i] && map[i + 1])
	{
		j = ft_strlen(map[i]);
		if (map[i][0] != '1' || map[i][j - 1] != '1')
		{
			ft_printf("Error\nProblem with side walls\n");
			close_error(map);
		}
	}
}

void	check_char_count(char **map)
{
	int	p_count;
	int	no_exit;
	int	has_collectible;

	p_count = 0;
	no_exit = 0;
	has_collectible = 0;
	char_check(map, &p_count, &no_exit, &has_collectible);
}
