/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:52:04 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/07 13:13:15 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dimensions(char *map_name, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		exit_game_error(map, "Map file not found");
	line = get_next_line(fd);
	if (!line)
		exit_game_error(map, "Map file is empty");
	map->columns = ft_strlen(line) - 2;
	map->rows = 0;
	while (line)
	{
		map->rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	read_map(char *map_name, t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		exit_game(map);
	map->map = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->map)
		exit_game_error(map, "Malloc failed");
	line = get_next_line(fd);
	if (!line)
		exit_game_error(map, "Map file is empty");
	while (line)
	{
		map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}

void	checker(t_map *map, int x, int y)
{
	if (map->map[y][x] != '1' && map->map[y][x] != '0'
		&& map->map[y][x] != 'P' && map->map[y][x] != 'E'
		&& map->map[y][x] != 'C')
		exit_game_error(map, "Map contains invalid characters");
	if (map->map[y][x] == 'P')
		map->player++;
	if (map->map[y][x] == 'E')
		map->exit++;
	if (map->map[y][x] == 'C')
		map->collectable++;
}

void	required_elements(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->player = 0;
	map->exit = 0;
	map->collectable = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns - 1)
		{
			checker(map, x, y);
			x++;
		}
		y++;
	}
	required_error(map);
}

void	required_error(t_map *map)
{
	if (map->player != 1)
		exit_game_error(map, "Map has no player or has more than one player");
	if (map->exit != 1)
		exit_game_error(map, "Map has no exit or has more than one exit");
	if (map->collectable <= 0)
		exit_game_error(map, "Map has no collectables");
	if (map->columns < 3 || map->rows < 3)
		exit_game_error(map, "Map is too small");
}
