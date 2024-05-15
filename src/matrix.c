/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 12:24:35 by lumaret           #+#    #+#             */
/*   Updated: 2024/05/15 13:30:12 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fdf.h"

void	matrix_x(double rot_mat[3][3], double angle)
{
	double	radiant_cos;
	double	radiant_sin;

	radiant_cos = cos(angle * MY_PI / 180);
	radiant_sin = sin(angle * MY_PI / 180);
	rot_mat[0][0] = 1;
	rot_mat[0][1] = 0;
	rot_mat[0][2] = 0;
	rot_mat[1][0] = 0;
	rot_mat[1][1] = radiant_cos;
	rot_mat[1][2] = -radiant_sin;
	rot_mat[2][0] = 0;
	rot_mat[2][1] = radiant_sin;
	rot_mat[2][2] = radiant_cos;
}

void	matrix_y(double rot_mat[3][3], double angle)
{
	double	radiant_cos;
	double	radiant_sin;

	radiant_cos = cos(angle * MY_PI / (double)180);
	radiant_sin = sin(angle * MY_PI / (double)180);
	rot_mat[0][0] = radiant_cos;
	rot_mat[0][1] = 0;
	rot_mat[0][2] = radiant_sin;
	rot_mat[1][0] = 0;
	rot_mat[1][1] = 1;
	rot_mat[1][2] = 0;
	rot_mat[2][0] = -radiant_sin;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = radiant_cos;
}

void	matrix_z(double rot_mat[3][3], double angle)
{
	double	radiant_cos;
	double	radiant_sin;

	radiant_cos = cos(angle * MY_PI / (double)180);
	radiant_sin = sin(angle * MY_PI / (double)180);
	rot_mat[0][0] = radiant_cos;
	rot_mat[0][1] = -radiant_sin;
	rot_mat[0][2] = 0;
	rot_mat[1][0] = radiant_sin;
	rot_mat[1][1] = radiant_cos;
	rot_mat[1][2] = 0;
	rot_mat[2][0] = 0;
	rot_mat[2][1] = 0;
	rot_mat[2][2] = 1;
}