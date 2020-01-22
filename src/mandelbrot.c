/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:47:10 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/13 14:00:48 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

void		set_def_mand(t_mlx *mlx)
{
	t_point point;

	mlx->view.minre = -2.1;
	mlx->view.maxre = 1.1;
	mlx->view.minim = -1.5;
	mlx->view.maxim = 1.5;
	mlx->view.re_fact = (mlx->view.maxre - mlx->view.minre) / (WIDTH);
	mlx->view.im_fact = (mlx->view.maxim - mlx->view.minim) / (HEIGHT);
	mlx->view.max_iter = 100;
	mlx->view.zoom = 300;
	mlx->view.offx = -2.0;
	mlx->view.offy = -2.0;
}

void		mandelbrot(t_mlx *in)
{
	t_point	point;

	point.x = 0;
	while (point.x < WIDTH)
	{
		point.y = 0;
		while (point.y < HEIGHT)
		{
			calc_mandel(in, point);
			point.y++;
		}
		point.x++;
	}
	mlx_put_image_to_window(in->mlx, in->win, in->img, 0, 0);
}

void		calc_mandel(t_mlx *in, t_point point)
{
	t_complex	c;
	int			iters;
	double		temp;

	in->view.c_im = point.y / in->view.zoom + in->view.offy;
	in->view.c_re = point.x / in->view.zoom + in->view.offx;
	in->view.z_re = 0;
	in->view.z_im = 0;
	iters = 0;
	while (in->view.z_re * in->view.z_re + in->view.z_im * in->view.z_im < 4 &&
	iters < in->view.max_iter)
	{
		temp = in->view.z_re * in->view.z_re - in->view.z_im *
		in->view.z_im + in->view.c_re;
		in->view.z_im = 2 * in->view.z_re * in->view.z_im + in->view.c_im;
		in->view.z_re = temp;
		iters++;
	}
	in->view.color = get_color(iters, in);
	image_put_pixel(in, point.x, point.y, in->view.color);
}
