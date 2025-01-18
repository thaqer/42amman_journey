/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:15:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/07 10:12:23 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "../so_long/photo/wall.xpm"
# define FLOOR "../so_long/photo/floor.xpm"
# define PLAYER "../so_long/photo/player.xpm"
# define COLLECTABLE "../so_long/photo/collectable.xpm"
# define EXIT "../so_long/photo/exit.xpm"
# define EXIT_WIN "../so_long/photo/exit_win.xpm"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define WIDTH 50
# define HEIGHT 50

# include "../so_long/get_next_line/get_next_line.h"
# include "../so_long/libft/libft.h"
# include "../so_long/printf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_photos
{
	void		*wall;
	void		*floor;
	void		*player;
	void		*collectable;
	void		*exit;
	void		*exit_win;
	void		*img;
}				t_photos;

typedef struct s_map
{
	char		**map;
	void		*mlx;
	void		*win;
	int			rows;
	int			columns;
	int			player;
	int			exit;
	int			collectable;
	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			move;
	int			exit_found;
	t_photos	*photos;
}				t_map;

typedef struct s_index
{
	int			x;
	int			y;
}				t_index;

void			dimensions(char *map_name, t_map *map);
void			read_map(char *map_name, t_map *map);
void			wall_check(t_map *map);
void			required_elements(t_map *map);
void			required_error(t_map *map);
void			is_rect(char **map, t_map *map1);
void			map_name(char *map_name, t_map *map);
void			open_window(t_map *map);
int				close_window(t_map *map);
int				handle_keypress(int keycode, void *param);
void			init_photos(t_photos *photos, t_map *map);
void			put_image(t_photos *photos, t_map *map, int x, int y);
void			map_runder(t_photos *photos, t_map *map);
void			key_move(int keycode, t_map *map);
void			exit_game(t_map *map);
void			cleanup_resources(t_map *map);
void			moving(t_map *map, int new_x, int new_y);
void			update_position(t_map *map, int new_x, int new_y);
void			exit_game(t_map *map);
void			exit_game_error(t_map *map, char *message);
void			flood_fill(t_map *map, int x, int y, char **map_copy);
void			find_player(t_map *map);
void			validate_path(t_map *map);
void			move(t_map *map, int new_x, int new_y);
void			protection(int x, t_map *map, char **map_copy);

#endif