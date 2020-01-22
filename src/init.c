/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 11:28:34 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/09 14:49:35 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx	*init(void)
{
	t_mlx	*set;

	if (!(set = (t_mlx*)ft_memalloc(sizeof(t_mlx))))
		return (0);
	set->mlx = mlx_init();
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "Fract'ol");
	set->img = mlx_new_image(set->mlx, WIDTH, HEIGHT);
	set->addr = mlx_get_data_addr(set->img, &(set->bits_pp),
	&(set->s_line), &(set->endian));
	return (set);
}
