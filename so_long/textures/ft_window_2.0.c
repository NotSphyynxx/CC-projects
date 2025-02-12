/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_2.0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:24:00 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:04:31 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_my_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			render_obj(game, game->floor, x, y);
			x++;
		}
		y++;
	}
}

void	get_map_size(char *filename, t_my_game *game, char **map)
{
	int		fd;
	char	*line;
	int		map_height;
	int		map_width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	map_height = 0;
	line = get_next_line(fd);
	if (line)
		map_width = ft_strlen(line) - 1;
	while (line)
	{
		map_height++;
		free(line);
		line = get_next_line(fd);
	}
	cr_window(game, map_height, map_width);
	pixeling_the_map(map, game, map_height, map_width);
	close(fd);
}

void	collect_exe(t_my_game *game, int new_y, int new_x)
{
	game->collected++;
	game->map[new_y][new_x] = '0';
	render_obj(game, game->floor, new_y, new_x);
}

void	exit_check(t_my_game *game)
{
	if (game->coll_count == game->collected)
	{
		ft_printf("You won !!");
		exit(0);
	}
}

void	coll_check(t_my_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				game->coll_count++;
			x++;
		}
		y++;
	}
}
