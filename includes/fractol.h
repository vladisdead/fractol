/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmicha <cmicha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:00:43 by cmicha            #+#    #+#             */
/*   Updated: 2019/09/13 14:00:32 by cmicha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 1200
# define WIDTH 1500
# define MENU_WIDTH 300
# define THREADS 8
# include <mlx.h>
# include <stdlib.h>
# include "libft.h"
# include <pthread.h>

# ifdef __APPLE__
#  include <OpenCL/opencl.h>
# else
#  include <CL/cl.h>
# endif

typedef struct		s_point
{
	int				x;
	int				y;
	int				y_max;
}					t_point;

typedef struct		s_complex
{
	double			z_re2;
	double			z_im2;
}					t_complex;

typedef struct		s_view
{
	double			minre;
	double			maxre;
	double			minim;
	double			maxim;
	double			c_re;
	double			c_im;
	double			re_fact;
	double			im_fact;
	double			z_re;
	double			z_im;
	int				max_iter;
	int				color;
	double			zoom;
	double			mousere;
	double			mouseim;
	double			offx;
	double			offy;
	double			radius;
	int				fract;
	int				freeze;
}					t_view;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				bits_pp;
	int				s_line;
	int				endian;
	int				*img;
	char			*addr;
	t_view			view;
	t_point			point;
	t_complex		zreim;
	t_complex		c_part;
}					t_mlx;

t_mlx				*init(void);

int					esc(void *param);
void				keyboard(t_mlx *in);
int					key_press(int key, void *param);

void				image_put_pixel(t_mlx *in, int x, int y, int color);
void				clear_image(t_mlx *set);

int					get_color(int iters, t_mlx *set);

void				movexy(t_mlx *in, int key);
void				zoomin(int x, int y, t_mlx *in);
void				zoomout(int x, int y, t_mlx *in);
int					mouse_hook(int mousecode, int x, int y, t_mlx *in);

void				set_def_mand(t_mlx *mlx);
void				calc_mandel(t_mlx *in, t_point point);
void				mandelbrot(t_mlx *in);

void				set_def_jul(t_mlx *mlx);
void				calc_julia(t_mlx *in, t_point point);
void				julia(t_mlx *in);
int					mouse_jul(int x, int y, t_mlx *in);

void				draw_fracts(t_mlx *in);
void				init_params(t_mlx *in);
int					read_fract(char **argv, t_mlx *in);

void				set_def_burning(t_mlx *mlx);
void				calc_burning(t_mlx *in, t_point point);
void				burningship(t_mlx *in);
void				put_menu(t_mlx *in);

#endif
