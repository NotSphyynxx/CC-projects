/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:22:26 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 14:29:44 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(char **cmap, int x, int y, t_size size)
{
	if (x >= size.rows || y >= size.columns || x < 0 || y < 0)
		return ;
	if (cmap[y][x] == '1' || cmap[y][x] == 'V')
		return ;
	cmap[y][x] = 'V';
	flood_fill(cmap, x + 1, y, size);
	flood_fill(cmap, x - 1, y, size);
	flood_fill(cmap, x, y + 1, size);
	flood_fill(cmap, x, y - 1, size);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	invalid_path(char **map)
{
	char	**cmap;
	int		*player;
	t_size	size;

	size.rows = ft_strlen(map[0]);
	size.columns = 0;
	while (map[size.columns])
		size.columns++;
	player = find_p(map);
	if (!player)
	{
		ft_printf("Error\nPlayer not found\n");
		exit(1);
	}
	cmap = dup_map(map, size.columns);
	if (!cmap)
	{
		ft_printf("Error\nMemory allocation failed\n");
		free(player);
		exit(1);
	}
	flood_fill(cmap, player[1], player[0], size);
	check_path(cmap, map, player);
	free(player);
	free_map(cmap);
}

int	*find_p(char **map)
{
	int	i;
	int	k;
	int	*pos;

	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	i = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'P')
			{
				pos[0] = i;
				pos[1] = k;
				return (pos);
			}
			k++;
		}
		i++;
	}
	free(pos);
	return (NULL);
}

char	**dup_map(char **map, int rows)
{
	char	**cmap;
	int		i;

	if (rows <= 0)
		return (NULL);
	cmap = malloc(sizeof(char *) * (rows + 1));
	if (!cmap)
		return (NULL);
	i = 0;
	while (map[i])
	{
		cmap[i] = ft_strdup(map[i]);
		if (!cmap[i])
		{
			free_map(cmap);
			return (NULL);
		}
		i++;
	}
	cmap[i] = NULL;
	return (cmap);
}
