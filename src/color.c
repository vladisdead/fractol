/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:27:21 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/10 12:56:41 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int iters, t_mlx *set)
{
	int r;
	int g;
	int b;

	if (iters == set->view.max_iter)
		return (0x000000);
	r = iters * 8;
	g = iters % 8;
	b = iters % 48;
	return (r << 8 | g | b);
}
