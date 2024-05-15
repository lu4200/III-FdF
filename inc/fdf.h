/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:15:13 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/15 12:41:29 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# ifndef WIDTH
#  define WIDTH 1920
# endif
# ifndef HEIGHT
#  define HEIGHT 1080
# endif
# ifndef MY_PI
#  define MY_PI 3.14159265358979323846
# endif

//#define _USE_MATH_DEFINES
//#include <math.h>

typedef struct s_pixel
{
	double			z[2];
	double			x[2];
	double			y[2];
	unsigned int	color;
}	t_pixel;

typedef struct s_tab
{
	t_pixel	**pixel;
	int		rows;
	int		lines;
	double	z;
	double	scaling;
	double	x_iso;
	double	y_iso;
	double	z_iso;
	double	angle;
	int		x_offset;
	int		y_offset;
}	t_tab;

#endif