/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:37:36 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/10 14:14:15 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			mouse_jul(int x, int y, t_mlx *in)
{
	if (in->view.fract == 2 && in->view.freeze != 1)
	{
		in->c_part.z_re2 = x * 2 - 200;
		in->c_part.z_im2 = y * 2 - 1200;
		julia(in);
		put_menu(in);
		mlx_string_put(in->mlx, in->win, 1201, 61,
		0xFFFFFF, "F - freeze Julia");
		mlx_string_put(in->mlx, in->win, 1201, 76,
		0xFFFFFF, "G - Unfreeze Julia");
	}
	return (0);
}

void		set_def_jul(t_mlx *mlx)
{
	mlx->view.max_iter = 50;
	mlx->view.zoom = 300;
	mlx->view.offx = -2.0;
	mlx->view.offy = -2.0;
	mlx->view.radius = 2;
	mlx->c_part.z_re2 = 0.285;
	mlx->c_part.z_im2 = 0;
	mlx->view.freeze = 0;
}

t_complex	mappoint(t_point point, double radius)
{
	int			l;
	t_complex	c;

	l = (WIDTH < HEIGHT) ? WIDTH : HEIGHT;
	c.z_im2 = 2 * radius * (point.y - HEIGHT / 2.0) / l;
	c.z_re2 = 2 * radius * (point.x - WIDTH / 2.0) / l;
	return (c);
}

void		calc_julia(t_mlx *in, t_point point)
{
	t_complex	z0;
	t_complex	z1;
	int			iters;
	double		temp;

	in->view.z_re = point.x / in->view.zoom + in->view.offx;
	in->view.z_im = point.y / in->view.zoom + in->view.offy;
	iters = 0;
	while (in->view.z_re * in->view.z_re + in->view.z_im * in->view.z_im <
	4 && iters < in->view.max_iter)
	{
		temp = in->view.z_re;
		in->view.z_re = in->view.z_re * in->view.z_re - in->view.z_im
		* in->view.z_im - 0.8 + (in->c_part.z_re2 / WIDTH);
		in->view.z_im = 2 * in->view.z_im * temp + in->c_part.z_im2 / WIDTH;
		iters++;
	}
	if (iters == in->view.max_iter)
		image_put_pixel(in, point.x, point.y, 0x000000);
	else
		image_put_pixel(in, point.x, point.y, get_color(iters, in));
}

void		julia(t_mlx *in)
{
	t_point	point;

	point.x = 0;
	while (point.x < WIDTH)
	{
		point.y = 0;
		while (point.y < HEIGHT)
		{
			calc_julia(in, point);
			point.y++;
		}
		point.x++;
	}
	mlx_put_image_to_window(in->mlx, in->win, in->img, 0, 0);
	clear_image(in);
}
