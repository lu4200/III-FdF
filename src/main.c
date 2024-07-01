/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 13:29:59 by lucas             #+#    #+#             */
/*   Updated: 2024/07/01 16:24:17 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include <stdio.h>

#define MALLOC_ERROR	1

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_pixel_put_img(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (x * (img->bits_per_pixel / 8) + y * img->line_length);
	*(unsigned int *)dst = color;
}

int	main(void)
{
	void	*mlx_connect;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;

	mlx_connect = mlx_init();
	if (NULL == mlx_connect)
	{
		fprintf(stderr, "Error: Failed to initialize mlx connection\n");
		return (MALLOC_ERROR);
	}
	mlx_win = mlx_new_window(mlx_connect, 1680, 900, "FDF");
	if (!mlx_win)
	{
		fprintf(stderr, "Error: Failed to create a new window\n");
		mlx_destroy_display(mlx_connect);
		free(mlx_connect);
		return (MALLOC_ERROR);
	}
	img.img = mlx_new_image(mlx_connect, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	i = -1;
	while (++i < 500)
	{
		j = -1;
		while (++j < 500)
			my_pixel_put_img(&img, i, j, 0xFF0000);
	}
	mlx_put_image_to_window(mlx_connect, mlx_win, img.img, 590, 225);
	mlx_loop(mlx_connect);

	// mlx_destroy_image(mlx, mlx_win);
	// mlx_destroy_window(mlx, mlx_win);
	return (0);
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int	i;
// 	int	j;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 			&img.endian);
// 	i = -1;
// 	while (++i < 500)
// 	{
// 		j = -1;
// 		while (++j < 500)
// 			my_mlx_pixel_put_img(&img, i, j, 0xFF0000);
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }