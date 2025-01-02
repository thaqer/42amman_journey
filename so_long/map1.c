/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:01:32 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/01 15:03:22 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rect(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x != (int)ft_strlen(map[0]))
		{
			write(1, "Error: Map is not rectangular.\n", 31);
			exit(1);
		}
		y++;
	}
}

void	map_name(char *map_name)
{
	int		len;

	len = ft_strlen(map_name);
	if (len < 5 || map_name[len - 4] != '.' || map_name[len - 3] != 'b'
		|| map_name[len - 2] != 'e' || map_name[len - 1] != 'r')
	{
		write(1, "Error: Invalid map file.\n", 25);
		exit(1);
	}
}
