/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 21:12:02 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/06 22:32:19 by tbaniatt         ###   ########.fr       */
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
	is_rect(map->map, map);
	required_elements(map);
	validate_path(map);
	required_elements(map);
	open_window(map);
	cleanup_resources(map);
	free(map);
	return (0);
}
