/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:21:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/04 19:21:33 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_map *map)
{
	t_photos	*photos;

	photos = malloc(sizeof(t_photos));
	if (!photos)
		exit_game(map);
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		free(photos);
		exit_game(map);
	}
	map->win = mlx_new_window(map->mlx, map->columns * WIDTH, map->rows
			* HEIGHT, "so_long");
	if (!map->win)
	{
		free(photos);
		exit_game(map);
	}
	init_photos(photos, map);
	map->photos = photos;
	map_runder(photos, map);
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_hook(map->win, 2, 1L << 0, handle_keypress, map);
	mlx_loop(map->mlx);
}

void	update_position(t_map *map, int new_x, int new_y)
{
	map->map[new_y][new_x] = 'P';
	map->map[map->player_y][map->player_x] = '0';
	map->player_x = new_x;
	map->player_y = new_y;
}

void	moving(t_map *map, int new_x, int new_y)
{
	if (map->map[new_y][new_x] == '0')
		update_position(map, new_x, new_y);
	else if (map->map[new_y][new_x] == 'C')
	{
		update_position(map, new_x, new_y);
		map->collectable--;
	}
	else if (map->map[new_y][new_x] == 'E' && map->collectable == 0)
	{
		update_position(map, new_x, new_y);
		write(1, "You win!\n", 9);
		cleanup_resources(map);
		exit(0);
	}
}

void	key_move(int keycode, t_map *map)
{
	int	new_x;
	int	new_y;

	new_x = map->player_x;
	new_y = map->player_y;
	if (map->map[new_y][new_x] == '1')
		return ;
	if (keycode == W || keycode == UP)
		new_y--;
	else if (keycode == S || keycode == DOWN)
		new_y++;
	else if (keycode == A || keycode == LEFT)
		new_x--;
	else if (keycode == D || keycode == RIGHT)
		new_x++;
	if (new_x < 0 || new_x >= map->columns || new_y < 0 || new_y >= map->rows
		|| map->map[new_y][new_x] == '1' || (map->map[new_y][new_x] == 'E'
			&& map->collectable != 0))
		return ;
	else
		moving(map, new_x, new_y);
	mlx_clear_window(map->mlx, map->win);
	map_runder(map->photos, map);
}
