/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:01:32 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/04 18:56:14 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rect(char **map_copy, t_map *map1)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map_copy[0]);
	while (map_copy[i])
	{
		if (ft_strlen(map_copy[i]) != len)
			exit_game_error(map1, "Map is not a rectangle");
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
