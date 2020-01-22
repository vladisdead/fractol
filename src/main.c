/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:28:07 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/13 14:01:02 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fracts(t_mlx *in)
{
	if (in->view.max_iter < 0)
		in->view.max_iter = 0;
	if (in->view.fract == 1)
		mandelbrot(in);
	else if (in->view.fract == 2)
	{
		julia(in);
		mlx_string_put(in->mlx, in->win, 1201, 61,
		0xFFFFFF, "F - Freeze Julia");
		mlx_string_put(in->mlx, in->win, 1201, 76,
		0xFFFFFF, "G - Unfreeze Julia");
	}
	else if (in->view.fract == 3)
		burningship(in);
	put_menu(in);
}

void	init_params(t_mlx *in)
{
	if (in->view.fract == 1)
		set_def_jul(in);
	else if (in->view.fract == 2)
		set_def_mand(in);
	else if (in->view.fract == 3)
		set_def_burning(in);
	draw_fracts(in);
}

int		read_fract(char **argv, t_mlx *in)
{
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		in->view.fract = 1;
	else if (ft_strcmp(argv[1], "julia") == 0)
		in->view.fract = 2;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		in->view.fract = 3;
	else
	{
		ft_putendl("Usage: ./fractol [mandelbrot], [julia], [burningship]");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_mlx *mlx;

	if (argc == 2)
	{
		mlx = init();
		if ((read_fract(argv, mlx)) == 0)
			return (0);
		init_params(mlx);
		keyboard(mlx);
		mlx_loop(mlx->mlx);
	}
	else
		ft_putendl("Usage: ./fractol [mandelbrot], [julia], [burningship]");
}
