/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:01:32 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/02 17:26:27 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_rect(char **map)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			write(1, "Error: Map is not rectangular.\n", 31);
			exit(1);
		}
		i++;
	}
}

void	map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 5 || map_name[len - 4] != '.' || map_name[len - 3] != 'b'
		|| map_name[len - 2] != 'e' || map_name[len - 1] != 'r')
	{
		write(1, "Error: Invalid map file.\n", 25);
		exit(1);
	}
}
