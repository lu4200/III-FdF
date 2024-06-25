/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compat_linux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:04:25 by lucas             #+#    #+#             */
/*   Updated: 2024/06/25 14:06:42 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../inc/mlx_linux/mlx_int.h"

int	mlx2_destroy_display(t_xvar *xvar)
{
	mlx_destroy_display(xvar);
	free(xvar);
	return (1);
}