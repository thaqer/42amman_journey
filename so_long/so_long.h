/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:15:06 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/29 20:18:29 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define WALL "../so_long/photos/wall.xpm"
# define FLOOR "../so_long/photos/floor.xpm"
# define PLAYER "../so_long/photos/player.xpm"
# define COLLECTABLE "../so_long/photos/collectable.xpm"
# define EXIT "../so_long/photos/exit.xpm"

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
}			t_photos;

typedef struct s_map
{
	char	**map;
	void	*mlx;
	void	*win;
	int		rows;
	int		columns;
	int		player;
	int		exit;
	int		collectable;
	t_photos	photos;
}			t_map;

void		dimensions(char *map_name, t_map *map);
void		read_map(char *map_name, t_map *map);
void		wall_check(t_map *map);
void		required_elements(t_map *map);
void		required_error(t_map *map);
void		is_rect(char **map);
void		open_window(t_map *map);
int			close_window(void *param);
int			handle_keypress(int keycode, void *param);


#endif