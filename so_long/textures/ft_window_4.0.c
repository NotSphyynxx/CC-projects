/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_4.0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 06:36:11 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:05:49 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	close_window(void	*param)
{
	t_my_game	*game;

	game = (t_my_game *)param;
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}
