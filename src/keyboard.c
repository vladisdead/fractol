/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:38:01 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/13 14:06:45 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keycode.h"

int		esc(void *param)
{
	(void)param;
	exit(0);
}

int		key_press(int key, void *param)
{
	t_mlx *in;

	in = (t_mlx *)param;
	if (key == ESC_KEY)
		exit(0);
	if (key == UP_KEY || key == DOWN_KEY ||
	key == LEFT_KEY || key == RIGHT_KEY)
		movexy(in, key);
	if (key == R_KEY)
	{
		set_def_mand(in);
		in->view.freeze = 0;
	}
	if (in->view.fract == 2)
	{
		if (key == F_KEY)
			in->view.freeze = 1;
		if (key == G_KEY)
			in->view.freeze = 0;
	}
	draw_fracts(in);
	return (0);
}

void	keyboard(t_mlx *in)
{
	mlx_hook(in->win, 17, 0, esc, in);
	mlx_hook(in->win, 2, 0, key_press, in);
	mlx_mouse_hook(in->win, mouse_hook, in);
	mlx_hook(in->win, 6, 0, mouse_jul, in);
}
