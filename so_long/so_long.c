/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:17:19 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/30 10:27:57 by tbaniatt         ###   ########.fr       */
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
    if (keycode == 65307) // Keycode for Esc on Linux
        exit(0);
    return (0);
}
void open_window(t_map *map)
{
    t_photos    photos;
    int         wid;
    int         h;

    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->columns * 64, map->rows * 64, "so_long");
    if (!map->win)
    {
        write(1, "Error creating window\n", 23);
        exit(1);
    }
    mlx_hook(map->win, 17, 1L << 17, close_window, map);
    mlx_hook(map->win, 2, 1L << 0, handle_keypress, map);
    mlx_hook(map->win, 17, 1L << 17, close_window, map);
    mlx_loop(map->mlx);
}


int main(int argc, char **argv)
{
    t_map    map;

    if (argc != 2)
    {
        write(1, "Error: Invalid number of arguments\n", 36);
        return (1);
    }
    dimensions(argv[1], &map);
    read_map(argv[1], &map);
    wall_check(&map);
    required_elements(&map);
    open_window(&map);
    
}