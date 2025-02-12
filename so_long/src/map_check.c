/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:56:34 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:09:26 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_lines(char *file_name)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (-1);
	}
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count += ft_strlen(line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

char	*map_reader(char *file_name)
{
	int		fd;
	char	*map;
	char	*line;
	int		size;

	size = ft_count_lines(file_name);
	if (size <= 0)
		return (NULL);
	map = malloc(sizeof(char) * (size + 1));
	if (!map)
		return (NULL);
	map[0] = '\0';
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit_with_error(map);
	line = get_next_line(fd);
	while (line)
	{
		map = app_strings(map, line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map);
}

void	map_parsing(int ac, char **av)
{
	char		*min_onestring;
	char		**map;
	t_my_game	game;

	if (ac < 2)
		return ;
	min_onestring = map_reader(av[1]);
	if (!min_onestring)
	{
		ft_printf("Error\nFailed to read map\n");
		exit(1);
	}
	map = ft_split(min_onestring, '\n');
	free(min_onestring);
	check_shape(map);
	check_char(map);
	check_fl_row(map);
	check_walls(map);
	check_char_count(map);
	invalid_path(map);
	get_map_size(av[1], &game, map);
}

char	*app_strings(char *dst, char *src)
{
	size_t	dst_len;
	size_t	src_len;
	char	*new_str;

	if (!dst || !src)
		return (NULL);
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	new_str = copy_strings(dst, src, dst_len, src_len);
	free(dst);
	return (new_str);
}

int	main(int ac, char **av)
{
	if (ac == 2)
		map_parsing(ac, av);
	else
	{
		ft_printf("Error\nPlease provide 1 file\n");
		exit(1);
	}
	return (0);
}
