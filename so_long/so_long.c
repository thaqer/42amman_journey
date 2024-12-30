/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:17:19 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/30 11:27:58 by tbaniatt         ###   ########.fr       */
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
void    init_photos(t_photos *photos, t_map *map)
{
    int         wid;
    int         h;

    wid = 64;
    h = 64;
    photos->wall = mlx_xpm_file_to_image(map->mlx, WALL, &wid, &h);
    photos->floor = mlx_xpm_file_to_image(map->mlx, FLOOR, &wid, &h);
    photos->player = mlx_xpm_file_to_image(map->mlx, PLAYER, &wid, &h);
    photos->collectable = mlx_xpm_file_to_image(map->mlx, COLLECTABLE, &wid, &h);
    photos->exit = mlx_xpm_file_to_image(map->mlx, EXIT, &wid, &h);
} 

void    map_runder(t_photos *photos, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->rows)
    {
        j = 0;
        while (j < map->columns)
        {
            if (map->map[i][j] == '1')
                mlx_put_image_to_window(map->mlx, map->win, photos->wall, j * 64, i * 64);
            else if (map->map[i][j] == '0')
                mlx_put_image_to_window(map->mlx, map->win, photos->floor, j * 64, i * 64);
            else if (map->map[i][j] == 'P')
	    {
		mlx_put_image_to_window(map->mlx, map->win, photos->floor, j * 64, i * 64);
		mlx_put_image_to_window(map->mlx, map->win, photos->player, j * 64, i * 64);
	    }
            else if (map->map[i][j] == 'C')
                mlx_put_image_to_window(map->mlx, map->win, photos->collectable, j * 64, i * 64);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(map->mlx, map->win, photos->exit, j * 64, i * 64);
            j++;
        }
        i++;
    }
}

void open_window(t_map *map)
{
    t_photos    photos;
    
    map->mlx = mlx_init();
    map->win = mlx_new_window(map->mlx, map->columns * 64, map->rows * 64, "so_long");
    init_photos(&photos, map);
    map_runder(&photos ,map);
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