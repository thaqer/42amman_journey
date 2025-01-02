/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 17:52:04 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/01 18:08:15 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dimensions(char *map_name, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		write(1, "open map Error\n", 16);
		exit(1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		write(1, "Error: Empty map\n", 17);
		exit(1);
	}
	map->columns = ft_strlen(line) - 1;
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
	if (fd == -1)
	{
		write(1, "open map Error\n", 16);
		exit(1);
	}
	map->map = malloc(sizeof(char *) * (map->rows + 1));
	line = get_next_line(fd);
	while (line)
	{
		map->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map->map[i] = NULL;
	close(fd);
}

void	wall_check(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if ((y == 0 || y == map->rows - 1 || x == 0
			|| x == map->columns - 1) && map->map[y][x] != '1')
			{
				write(1, "Error: Map not enclosed by walls.\n", 33);
				exit(1);
			}
			x++;
		}
		y++;
	}
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
		while (x < map->columns)
		{
			if (map->map[y][x] == 'P')
				map->player++;
			if (map->map[y][x] == 'E')
				map->exit++;
			if (map->map[y][x] == 'C')
				map->collectable++;
			x++;
		}
		y++;
	}
	required_error(map);
}

void	required_error(t_map *map)
{
	if (map->player != 1)
	{
		write(1, "Error: Player not found or too many players.\n", 45);
		exit(1);
	}
	if (map->exit != 1)
	{
		write(1, "Error: Exit not found or too many exits.\n", 41);
		exit(1);
	}
	if (map->collectable <= 0)
	{
		write(1, "Error: No collectables found.\n", 31);
		exit(1);
	}
	if (map->columns < 3 || map->rows < 3)
	{
		write(1, "Error: Map is too small.\n", 25);
		exit(1);
	}
}

// void	print_map(t_map *map)
// {
// 	int	y;

// 	y = 0;
// 	while (y < map->rows)
// 	{
// 		ft_printf("%s\n", map->map[y]);
// 		y++;
// 	}
// }
