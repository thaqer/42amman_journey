/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:15:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/01 17:16:09 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "../so_long/photos/wall.xpm"
# define FLOOR "../so_long/photos/floor.xpm"
# define PLAYER "../so_long/photos/player.xpm"
# define COLLECTABLE "../so_long/photos/collectable.xpm"
# define EXIT "../so_long/photos/exit.xpm"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define WIDTH 64
# define HEIGHT 64

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
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectable;
	void	*exit;
	void	*img;
}	t_photos;

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
	t_photos	*photos;
}	t_map;

typedef struct s_index
{
	int		x;
	int		y;
}	t_index;

void	dimensions(char *map_name, t_map *map);
void	read_map(char *map_name, t_map *map);
void	wall_check(t_map *map);
void	required_elements(t_map *map);
void	required_error(t_map *map);
void	is_rect(char **map);
void	map_name(char *map_name);
void	open_window(t_map *map);
int		close_window(void *param);
int		handle_keypress(int keycode, void *param);
void	init_photos(t_photos *photos, t_map *map);
void	put_image(t_photos *photos, t_map *map, int x, int y);
void	map_runder(t_photos *photos, t_map *map);
void	key_move(int keycode, t_map *map);
void    runder_map(t_photos *photos, t_map *map);


#endif