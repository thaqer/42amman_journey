/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:17:19 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/28 00:18:21 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
    (void)param;
    exit(0);
}

int	handle_keypress(int keycode, void *param)
{
    (void)param;
    if (keycode == 65307) // Keycode for Esc on Linux
        exit(0);
    return (0);
}

int	main(void)
{
    void	*mlx;
    void	*mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_hook(mlx_win, 17, 0, close_window, NULL);        // Handle window close event
    mlx_hook(mlx_win, 2, 1L << 0, handle_keypress, NULL); // Handle keypress events
    mlx_loop(mlx);
}
