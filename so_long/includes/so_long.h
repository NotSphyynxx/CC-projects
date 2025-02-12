/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilarhrib <ilarhrib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:30:39 by ilarhrib          #+#    #+#             */
/*   Updated: 2025/02/12 15:09:56 by ilarhrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define TILE_SIZE 50
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53
# define RED_CROSS 17

typedef struct s_size
{
	int	rows;
	int	columns;
}	t_size;

typedef struct s_game
{
	int		px;
	int		py;
	void	*mlx;
	void	*win;
	void	*player;
	void	*exit;
	void	*wall;
	void	*floor;
	void	*collectibles;
	int		coll_count;
	char	**map;
	int		map_h;
	int		map_w;
	int		collected;
	int		move;
}	t_my_game;

char	*read_and_stock(int fd, char *line);
void	exit_with_error(char *map);
char	*copy_strings(char *dst, char *src, size_t dst_len, size_t src_len);
void	check_bottom_wall(int i, int j, int k, char **map);
void	char_check(char **map, int *p_count,
			int *no_exit, int *has_collectible);
int		close_window(void *param);
void	collect_exe(t_my_game *game, int new_y, int new_x);
void	exit_check(t_my_game *game);
void	coll_check(t_my_game *game, char **map);
int		is_valid_move(t_my_game *game, int new_x, int new_y);
int		key_handler(int keycode, void *param);
void	player_pos(t_my_game *game, char **map, int map_h, int map_w);
void	end_game(t_my_game *game);
void	check_path(char **map, char **cmap, int *player);
void	free_map(char **map);
void	update_player_pos(t_my_game *game, int dx, int dy);
void	get_map_size(char *filename, t_my_game *game, char **map);
void	render_obj(t_my_game *game, void *obj, int x, int y);
void	fill_map(t_my_game *game, char **map);
void	render_map(t_my_game *game, char **map, int map_h, int map_w);
void	test_render(t_my_game *game);
void	load_pixels(t_my_game *game);
char	*get_next_line(int fd);
void	map_pix(char **map);
void	pixeling_the_map(char **map, t_my_game *game, int map_h, int map_w);
void	cr_window(t_my_game *game, int map_h, int map_w);
char	*get_till_n_line(char *line);
char	*new_line_exe(char *line);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *line, char *buff);
void	close_error(char **map);
void	check_shape(char **map);
void	check_walls(char **map);
void	check_char_count(char **map);
void	help_char_count(int noexit, int pcount, int has_collectible);
void	ft_free_split(char **rows);
void	check_char(char **map);
void	invalid_path(char **map);
char	**dup_map(char **map, int rows);
void	free_row(char **cmap, int j);
char	*ft_strdup(const char *s1);
int		*find_p(char **map);
char	**ft_split(char const *s, char c);
void	check_rectangular(char *map);
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int nb);
int		ft_put_unsigned(unsigned int nb);
int		ft_put_hexa(unsigned int num, const char format);
void	ft_hexa_converter(unsigned int num, const char format);
int		ft_hexa_len(unsigned int num);
int		ft_put_ptr(unsigned long num);
void	check_fl_row(char **map);
char	*app_strings(char *dst, char *src);
void	map_parsing(int ac, char **av);
char	*map_reader(char *file_name);
int		ft_count_lines(char *file_name);

#endif
