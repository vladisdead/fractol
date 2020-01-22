/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:54:31 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/10 12:32:05 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx_keycode.h"

void		movexy(t_mlx *in, int key)
{
	if (key == UP_KEY)
		in->view.offy -= 30 / in->view.zoom;
	if (key == DOWN_KEY)
		in->view.offy += 30 / in->view.zoom;
	if (key == LEFT_KEY)
		in->view.offx -= 30 / in->view.zoom;
	if (key == RIGHT_KEY)
		in->view.offx += 30 / in->view.zoom;
}

void		zoomin(int x, int y, t_mlx *in)
{
	in->view.offx = (x / in->view.zoom + in->view.offx)
	- (x / (in->view.zoom * 1.3));
	in->view.offy = (y / in->view.zoom + in->view.offy)
	- (y / (in->view.zoom * 1.3));
	in->view.zoom *= 1.3;
	in->view.max_iter++;
}

void		zoomout(int x, int y, t_mlx *in)
{
	in->view.offx = (x / in->view.zoom +
	in->view.offx) - (x / (in->view.zoom / 1.3));
	in->view.offy = (y / in->view.zoom +
	in->view.offy) - (y / (in->view.zoom / 1.3));
	in->view.zoom /= 1.3;
	in->view.max_iter--;
}

int			mouse_hook(int mousecode, int x, int y, t_mlx *in)
{
	if (mousecode == 4 || mousecode == 1)
		zoomin(x, y, in);
	if (mousecode == 5 || mousecode == 2)
		zoomout(x, y, in);
	draw_fracts(in);
	return (0);
}
