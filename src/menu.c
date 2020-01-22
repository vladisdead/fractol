/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:57:24 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/10 14:02:46 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_menu(t_mlx *in)
{
	mlx_string_put(in->mlx, in->win, 1201, 1, 0xFFFFFF, "Fractol by Cmicha");
	mlx_string_put(in->mlx, in->win, 1201, 16, 0xFFFFFF,
	"Mouse buttons/wheel - Zoom");
	mlx_string_put(in->mlx, in->win, 1201, 31, 0xFFFFFF, "Arrows - Move");
	mlx_string_put(in->mlx, in->win, 1201, 46, 0xFFFFFF, "R - reload fractal");
}
