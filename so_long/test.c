/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:14:11 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/12/27 15:44:04 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Define window size
#define WIN_WIDTH 800
#define WIN_HEIGHT 600

// Keycodes (specific to MiniLibX)
#define KEY_ESC 53

typedef struct s_data {
    void *mlx_ptr;
    void *win_ptr;
    int color;
} t_data;

int key_hook(int keycode, t_data *data) {
    if (keycode == KEY_ESC) {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0); // Exit the program when ESC is pressed
    }
    data->color = (data->color == 0x00FF0000) ? 0x0000FF00 : 0x00FF0000; // Toggle colors
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, data->color, "Key Pressed!");
    return (0);
}

int main() {
    t_data data;

    // Initialize MiniLibX and create a window
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr) {
        fprintf(stderr, "Error initializing MLX\n");
        return (1);
    }
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "MiniLibX Window");
    if (!data.win_ptr) {
        fprintf(stderr, "Error creating window\n");
        return (1);
    }

    // Set initial color
    data.color = 0x00FF0000;

    // Display initial message
    mlx_string_put(data.mlx_ptr, data.win_ptr, 10, 10, data.color, "Press ESC to Exit!");

    // Handle key press events
    mlx_key_hook(data.win_ptr, key_hook, &data);

    // Start the MLX event loop
    mlx_loop(data.mlx_ptr);
    return (0);
}
