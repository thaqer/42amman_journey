/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:01:32 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/19 17:19:00 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rect(t_map *map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map->map[0]);
	while (map->map[i])
	{
		if (ft_strlen(map->map[i]) != len)
			exit_game_error(map, "Map is not a rectangle");
		i++;
	}
}

void	map_name(char *map_name, t_map *map)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 5 || map_name[len - 4] != '.' || map_name[len - 3] != 'b'
		|| map_name[len - 2] != 'e' || map_name[len - 1] != 'r')
		exit_game_error(map, "Map file is not a .ber file");
}

void	wall_check(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	ft_printf("%d\n%d", map->rows, map->columns);
	while (y <= map->rows - 1)
	{
		x = 0;
		while (x <= map->columns - 1)
		{
			if (y == 0 || y == map->rows - 1 || x == 0 || x == map->columns - 1)
			{
				if (map->map[y][x] != '1')
					exit_game_error(map, "Map is not surrounded by walls");
			}
			x++;
		}
		y++;
	}
}

void	remove_newline(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '\n')
				map->map[i][j] = '\0';
			j++;
		}
		i++;
	}
}
