/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:17:19 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/01 20:05:24 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	handle_keypress(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		close_window(param);
	if (keycode == W || keycode == A || keycode == S || keycode == D)
		key_move(keycode, param);
	return (0);
}

void	init_photos(t_photos *photos, t_map *map)
{
	int	wid;
	int	h;

	wid = WIDTH;
	h = WIDTH;
	photos->wall = mlx_xpm_file_to_image(map->mlx, WALL, &wid, &h);
	photos->floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &wid, &h);
	photos->player = mlx_xpm_file_to_image(map->mlx, PLAYER, &wid, &h);
	photos->collectable = mlx_xpm_file_to_image(map->mlx, COLLECTABLE,
			&wid, &h);
	photos->exit = mlx_xpm_file_to_image(map->mlx, EXIT, &wid, &h);
}

void	put_image(t_photos *photos, t_map *map, int x, int y)
{
	photos->img = NULL;
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
		mlx_put_image_to_window(map->mlx, map->win, photos->img,
			x * WIDTH, y * HEIGHT);
}

void	map_runder(t_photos *photos, t_map *map)
{
	t_index	index;

	index.y = 0;
	while (index.y < map->rows)
	{
		index.x = 0;
		while (index.x < map->columns)
		{
			put_image(photos, map, index.x, index.y);
			index.x++;
		}
		index.y++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write(1, "Error: Invalid number of arguments.\n", 36);
		exit(1);
	}
	map_name(argv[1]);
	dimensions(argv[1], &map);
	read_map(argv[1], &map);
	is_rect(map.map);
	wall_check(&map);
	required_elements(&map);
	open_window(&map);
	return (0);
}