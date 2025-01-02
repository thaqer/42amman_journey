/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 15:21:00 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/01 20:07:44 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_window(t_map *map)
{
	t_photos	photos;

        map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->columns * 64
                        , map->rows * 64, "so_long");
	init_photos(&photos, map);
	map_runder(&photos, map);
	mlx_hook(map->win, 17, 0, close_window, map);
        mlx_key_hook(map->win, handle_keypress, map);
	mlx_loop(map->mlx);
}

void	key_move(int keycode, t_map *map)
{
        int	new_x;
        int	new_y;

        new_x = map->player_x;
        new_y = map->player_y;
        if (keycode == W)
                new_y++;
        else if (keycode == S)
                new_y--;
        else if (keycode == A)
                new_x--;
        else if (keycode == D)
                new_x++;
        if (map->map[new_y][new_x] == '0')
        {
                map->map[new_y][new_x] = 'P';
                map->map[map->player_y][map->player_x] = '0';
                map->player_x = new_x;
                map->player_y = new_y;
        }   
        mlx_clear_window(map->mlx, map->win);
        runder_map(&map->photos, map);
}

void    runder_map(t_photos *photos, t_map *map)
{
        int     x;
        int     y;

        y = 0;
        while (y < map->rows)
        {
                x = 0;
                while (x < map->columns)
                {
                        put_image(photos, map, x, y);
                        x++;
                }
                y++;
        }
}