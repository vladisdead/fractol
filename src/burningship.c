/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:26:26 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/10 12:40:42 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void		set_def_burning(t_mlx *mlx)
{
	mlx->view.max_iter = 50;
	mlx->view.zoom = 300;
	mlx->view.offx = -2.0;
	mlx->view.offy = -2.0;
}

void		calc_burning(t_mlx *in, t_point point)
{
	t_complex	z0;
	t_complex	z1;
	int			iters;
	double		temp;

	in->view.c_re = point.x / in->view.zoom + in->view.offx;
	in->view.c_im = point.y / in->view.zoom + in->view.offy;
	in->view.z_re = 0;
	in->view.z_im = 0;
	iters = 0;
	while (in->view.z_re * in->view.z_re + in->view.z_im * in->view.z_im <
	4 && iters < in->view.max_iter)
	{
		temp = in->view.z_re * in->view.z_re - in->view.z_im * in->view.z_im +
		in->view.c_re;
		in->view.z_im = fabs(2 * in->view.z_re * in->view.z_im) + in->view.c_im;
		in->view.z_re = fabs(temp);
		iters++;
	}
	if (iters == in->view.max_iter)
		image_put_pixel(in, point.x, point.y, 0x000000);
	else
		image_put_pixel(in, point.x, point.y, get_color(iters, in));
}

void		burningship(t_mlx *in)
{
	t_point	point;

	point.x = 0;
	while (point.x < WIDTH)
	{
		point.y = 0;
		while (point.y < HEIGHT)
		{
			calc_burning(in, point);
			point.y++;
		}
		point.x++;
	}
	mlx_put_image_to_window(in->mlx, in->win, in->img, 0, 0);
	clear_image(in);
}
