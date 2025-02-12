/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:27:55 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:06:15 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	pixeling_the_map(char **map, t_my_game *game, int map_h, int map_w)
{
	game->map = map;
	game->map_h = map_h;
	game->map_w = map_w;
	coll_check(game, map);
	load_pixels(game);
	player_pos(game, map, map_h, map_w);
	render_map(game, map, map_h, map_w);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_key_hook(game->win, key_handler, game);
	mlx_loop(game->mlx);
}

void	cr_window(t_my_game *game, int map_h, int map_w)
{
	int	w_w;
	int	w_h;

	w_w = map_w * TILE_SIZE;
	w_h = map_h * TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nFailed to initialize the mlx");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, w_w, w_h, "my game");
	if (!game->win)
	{
		ft_printf("Error\nFailed to open a window");
		exit(1);
	}
}

void	load_pixels(t_my_game *game)
{
	int	w;
	int	h;

	w = TILE_SIZE;
	h = TILE_SIZE;
	game->wall = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &w, &h);
	game->floor = mlx_xpm_file_to_image(game->mlx, "images/floor.xpm", &w, &h);
	game->exit = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &w, &h);
	game->collectibles = mlx_xpm_file_to_image(game->mlx,
			"images/collectibles.xpm", &w, &h);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"images/player.xpm", &w, &h);
	if (!game->wall || !game->floor || !game->player
		|| !game->collectibles || !game->exit)
	{
		ft_printf("Error\nFailed to load objects\n");
		exit(1);
	}
}

void	render_obj(t_my_game *game, void *obj, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, obj,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_my_game *game, char **map, int map_h, int map_w)
{
	int	y;
	int	x;

	fill_map(game, map);
	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			if (map[y][x] == '0')
				render_obj(game, game->floor, x, y);
			else if (map[y][x] == '1')
				render_obj(game, game->wall, x, y);
			else if (map[y][x] == 'C')
				render_obj(game, game->collectibles, x, y);
			else if (map[y][x] == 'E')
				render_obj(game, game->exit, x, y);
			x++;
		}
		y++;
	}
	render_obj(game, game->player, game->px, game->py);
}
