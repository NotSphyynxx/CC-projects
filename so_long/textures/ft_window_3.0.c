/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_3.0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:16:26 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:05:17 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_handler(int keycode, void *param)
{
	t_my_game	*game;

	game = (t_my_game *)param;
	if (keycode == KEY_W)
		update_player_pos(game, 0, -1);
	else if (keycode == KEY_S)
		update_player_pos(game, 0, 1);
	else if (keycode == KEY_A)
		update_player_pos(game, -1, 0);
	else if (keycode == KEY_D)
		update_player_pos(game, 1, 0);
	else if (keycode == KEY_ESC)
		end_game(game);
	return (0);
}

int	is_valid_move(t_my_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_x >= game->map_w || new_y >= game->map_h)
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	else if (game->map[new_y][new_x] == 'C')
		collect_exe(game, new_y, new_x);
	else if (game->map[new_y][new_x] == 'E')
		exit_check(game);
	return (1);
}

void	update_player_pos(t_my_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->px + dx;
	new_y = game->py + dy;
	if (is_valid_move(game, new_x, new_y))
	{
		game->move++;
		ft_printf("%d move\n", game->move);
		game->px = new_x;
		game->py = new_y;
		render_map(game, game->map, game->map_h, game->map_w);
	}
}

void	player_pos(t_my_game *game, char **map, int map_h, int map_w)
{
	int	y;
	int	x;

	y = 0;
	while (y < map_h)
	{
		x = 0;
		while (x < map_w)
		{
			if (map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	end_game(t_my_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_window(game->mlx, game->win);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	exit(0);
}
