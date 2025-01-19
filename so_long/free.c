/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:57:23 by tbaniatt          #+#    #+#             */
/*   Updated: 2025/01/07 10:13:07 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_map *map)
{
	cleanup_resources(map);
	exit(EXIT_FAILURE);
}

void	exit_game_error(t_map *map, char *message)
{
	cleanup_resources(map);
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

void	image_destroy(t_map *map)
{
	if (map->photos)
	{
		if (map->photos->wall)
			mlx_destroy_image(map->mlx, map->photos->wall);
		if (map->photos->floor)
			mlx_destroy_image(map->mlx, map->photos->floor);
		if (map->photos->player)
			mlx_destroy_image(map->mlx, map->photos->player);
		if (map->photos->collectable)
			mlx_destroy_image(map->mlx, map->photos->collectable);
		if (map->photos->exit)
			mlx_destroy_image(map->mlx, map->photos->exit);
		if (map->photos->exit_win)
			mlx_destroy_image(map->mlx, map->photos->exit_win);
		free(map->photos);
		map->photos = NULL;
	}
}

void	cleanup_resources(t_map *map)
{
	int	x;

	x = 0;
	if (map->photos)
		image_destroy(map);
	if (map->map)
	{
		while (x < map->rows)
		{
			free(map->map[x]);
			x++;
		}
		free(map->map);
	}
	if (map->mlx)
	{
		if (map->win)
			mlx_destroy_window(map->mlx, map->win);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
	}
	free(map);
}
