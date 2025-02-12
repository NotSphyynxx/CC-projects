/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:48:55 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 14:44:07 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	size_t	i;

	i = 0;
	ch = (char)c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (ch == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	char_check(char **map, int *p_count, int *no_exit, int *has_collectible)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		k = 0;
		while (map[i][k])
		{
			if (map[i][k] == 'E')
				(*no_exit)++;
			if (map[i][k] == 'C')
				*has_collectible = 1;
			if (map[i][k] == 'P')
				(*p_count)++;
			k++;
		}
		i++;
	}
	help_char_count(*no_exit, *p_count, *has_collectible);
}

void	check_bottom_wall(int i, int j, int k, char **map)
{
	while (map[i])
		i++;
	j = i - 1;
	k = 0;
	while (map[j][k])
	{
		if (!ft_strchr("1", map[j][k]))
		{
			ft_printf("Error\nProblem with bot wall\n");
			close_error(map);
		}
		k++;
	}
}

void	exit_with_error(char *map)
{
	write(2, "Error\nPlease provide a valid file\n", 34);
	free(map);
	exit(1);
}

char	*copy_strings(char *dst, char *src, size_t dst_len, size_t src_len)
{
	size_t	i;
	char	*new_str;

	new_str = malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < dst_len)
	{
		new_str[i] = dst[i];
		i++;
	}
	i = 0;
	while (i < src_len)
	{
		new_str[dst_len + i] = src[i];
		i++;
	}
	new_str[dst_len + i] = '\0';
	return (new_str);
}
