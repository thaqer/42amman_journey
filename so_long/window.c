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

void open_window(t_map *map)
{
    t_photos *photos;

    photos = malloc(sizeof(t_photos));
    if (!photos)
    {
        perror("malloc for photos failed");
        exit(EXIT_FAILURE);
    }
    map->mlx = mlx_init();
    if (!map->mlx)
    {
        perror("Failed to initialize mlx");
        exit(EXIT_FAILURE);
    }
    map->win = mlx_new_window(map->mlx, map->columns * WIDTH, map->rows * HEIGHT, "so_long");
    if (!map->win)
    {
        perror("Failed to create window");
        exit(EXIT_FAILURE);
    }
    init_photos(photos, map);
    map->photos = photos;
    map_runder(photos, map);
    mlx_hook(map->win, 17, 0, close_window, map);
    mlx_key_hook(map->win, handle_keypress, map);
    mlx_loop(map->mlx);
}


void key_move(int keycode, t_map *map)
{
    int new_x = map->player_x;
    int new_y = map->player_y;

    if (map->map[new_y][new_x] == '1')
        return;

    if (keycode == W)
        new_y--;
    else if (keycode == S)
        new_y++;
    else if (keycode == A)
        new_x--;
    else if (keycode == D)
        new_x++;

    if (new_x < 0 || new_x >= map->columns || new_y < 0 || new_y >= map->rows)
        return;

    if (map->map[new_y][new_x] == '0')
    {
        map->map[new_y][new_x] = 'P';
        map->map[map->player_y][map->player_x] = '0';
        map->player_x = new_x;
        map->player_y = new_y;
    }

    mlx_clear_window(map->mlx, map->win);
    map_runder(map->photos, map);
    mlx_put_image_to_window(map->mlx, map->win, map->photos->player,
                             new_x * WIDTH, new_y * HEIGHT);
}
