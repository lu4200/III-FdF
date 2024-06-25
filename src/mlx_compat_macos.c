/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_compat_macos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:05:03 by lucas             #+#    #+#             */
/*   Updated: 2024/06/25 14:05:28 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/mlx_macos/mlx_int.h"

int	mlx2_destroy_display(mlx_ptr_t *xvar)
{
	mlx_destroy_image(xvar, xvar->font);
	free(xvar);
	return (1);
}