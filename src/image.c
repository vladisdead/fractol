/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:34:06 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/10 13:56:12 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clear_image(t_mlx *set)
{
	ft_bzero(set->addr, WIDTH * HEIGHT * (set->bits_pp / 8));
}

void	image_put_pixel(t_mlx *in, int x, int y, int color)
{
	int i;

	i = 0;
	if (x >= 0 && x < (WIDTH - MENU_WIDTH) && y >= 0 && y < HEIGHT)
	{
		i = (x * in->bits_pp / 8) + (y * in->s_line);
		in->addr[i] = color;
		in->addr[++i] = color >> 8;
		in->addr[++i] = color >> 16;
		in->addr[++i] = 0;
	}
}
