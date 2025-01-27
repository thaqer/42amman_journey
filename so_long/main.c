/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:12:02 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/19 17:22:39 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		write(1, "Error: Invalid number of arguments.\n", 36);
		exit(1);
	}
	map = ft_calloc(1, sizeof(t_map));
	if (map == NULL)
	{
		perror("Error: Memory allocation for map failed");
		exit(EXIT_FAILURE);
	}
	map_name(argv[1], map);
	dimensions(argv[1], map);
	read_map(argv[1], map);
	wall_check(map);
	is_rect(map);
	required_elements(map);
	validate_path(map);
	required_elements(map);
	open_window(map);
	cleanup_resources(map);
	free(map);
	return (0);
}

void	special_cleanup_resources(t_map *map)
{
	if (map->photos)
		image_destroy(map);
	if (map->map)
	{
		free(map->map);
		map->map = NULL;
	}
	if (map->mlx)
	{
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		map->mlx = NULL;
	}
	free(map);
}

void	n_remo(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == '\n')
				map->map[y][x] = '\0';
			x++;
		}
		y++;
	}
}
