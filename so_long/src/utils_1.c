/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:45:21 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 14:39:53 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	close_error(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_free_split(char **rows)
{
	int	i;

	i = 0;
	if (!rows)
		return ;
	while (rows[i])
	{
		free(rows[i]);
		i++;
	}
	free(rows);
}

void	help_char_count(int noexit, int pcount, int has_collectible)
{
	if (noexit > 1 || noexit == 0)
	{
		ft_printf("Error\nProblem with exit positions\n");
		exit(1);
	}
	if (pcount != 1)
	{
		ft_printf("Error\nPlease provide only one player\n");
		exit(1);
	}
	if (!has_collectible)
	{
		ft_printf("Error\nThere is no collectible\n");
		exit(1);
	}
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*d;

	if (s1 == NULL)
		return (NULL);
	d = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}
