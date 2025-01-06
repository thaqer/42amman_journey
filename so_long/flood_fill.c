/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:10:51 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/06 22:38:42 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_map *map, int x, int y, char **map_copy)
{
	if (x < 0 || y < 0 || x >= map->rows || y >= map->columns)
		return ;
	if (map_copy[x][y] == '1' || map_copy[x][y] == 'V')
		return ;
	if (map_copy[x][y] == 'E')
	{
		map->exit_found = 1;
		return ;
	}
	if (map_copy[x][y] == 'C')
		map->collectable--;
	map_copy[x][y] = 'V';
	flood_fill(map, x + 1, y, map_copy);
	flood_fill(map, x, y - 1, map_copy);
	flood_fill(map, x, y + 1, map_copy);
	flood_fill(map, x - 1, y, map_copy);
}

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->columns)
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = i;
				map->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
	exit_game_error(map, "Player not found on map");
}

void	validate_path(t_map *map)
{
	int		x;
	char	**map_copy;

	find_player(map);
	map_copy = malloc(sizeof(char *) * map->rows);
	if (!map_copy)
		exit_game_error(map, "Memory allocation failed");
	x = 0;
	while (x < map->rows)
	{
		map_copy[x] = malloc(sizeof(char) * (map->columns + 1));
		if (!map_copy[x])
			protection (x, map, map_copy);
		ft_memcpy(map_copy[x], map->map[x], map->columns + 1);
		x++;
	}
	map->exit_found = 0;
	flood_fill(map, map->player_x, map->player_y, map_copy);
	while (--x >= 0)
		free(map_copy[x]);
	free(map_copy);
	if (map->collectable > 0 || !map->exit_found)
		exit_game_error(map, "Map has no valid path");
}

void	protection(int x, t_map *map, char **map_copy)
{
	while (--x >= 0)
		free(map_copy[x]);
	free(map_copy);
	exit_game_error(map, "Memory allocation failed");
}
