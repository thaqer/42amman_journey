/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:17:19 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/03 23:18:19 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window( t_map *map)
{
	exit_game(map);
	exit(0);
}

int	handle_keypress(int keycode, void *param)
{
	t_map	*map;

	if (keycode == ESC)
	{
		map = (t_map *)param;
		exit_game(map);
	}
	if (keycode == W || keycode == A || keycode == S || keycode == D
		|| keycode == UP || keycode == DOWN || keycode == LEFT
		|| keycode == RIGHT)
		key_move(keycode, param);
	return (0);
}

void	init_photos(t_photos *photos, t_map *map)
{
	int	wid;
	int	h;

	wid = WIDTH;
	h = HEIGHT;
	photos->wall = mlx_xpm_file_to_image(map->mlx, WALL, &wid, &h);
	photos->floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &wid, &h);
	photos->player = mlx_xpm_file_to_image(map->mlx, PLAYER, &wid, &h);
	photos->collectable = mlx_xpm_file_to_image(map->mlx, COLLECTABLE, &wid,
			&h);
	photos->exit = mlx_xpm_file_to_image(map->mlx, EXIT, &wid, &h);
	if (!photos->wall || !photos->floor || !photos->player
		|| !photos->collectable || !photos->exit)
		exit_game(map);
}

void	put_image(t_photos *photos, t_map *map, int x, int y)
{
	if (map->map[y][x] == '1')
		photos->img = photos->wall;
	else if (map->map[y][x] == '0')
		photos->img = photos->floor;
	else if (map->map[y][x] == 'P')
		photos->img = photos->player;
	else if (map->map[y][x] == 'C')
		photos->img = photos->collectable;
	else if (map->map[y][x] == 'E')
		photos->img = photos->exit;
	if (photos->img)
		mlx_put_image_to_window(map->mlx, map->win, photos->img, x * WIDTH, y
			* HEIGHT);
}

void	map_runder(t_photos *photos, t_map *map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->map[y][x] == 'P')
			{
				map->player_x = x;
				map->player_y = y;
			}
			put_image(photos, map, x, y);
			x++;
		}
		y++;
	}
}
