/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:46:10 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/12 15:46:12 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FRACTOL_H
# define _FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include "libft/libft.h"
# define WIDTH 1000
# define THREAD 4

typedef struct	s_fractol
{
	int			name;
	void		*mlx_ptr;
	void		*win_ptr;
	int			bpp;
	int			sl;
	int			endian;
	int			end;
	int			maxi;
	int			i;
	double		x1;
	double		y1;
	int			lock;
	int			y;
	int			x;
	double		nr;
	double		ni;
	double		or;
	double		oi;
	double		pr;
	double		pi;
	double		cre;
	double		cim;
	double		zoom;
	double		x2;
	double		y2;
	char		*img_data_addr;
	void		*img_ptr;
	int			color;
	int			status;
	int			*img_status_addr;
	int			st;
	int			var_color;

}				t_fractol;

int				more_color(int n);
void			mlx_windof(t_fractol *den);
void			put_info(t_fractol *den);
char			*find_fractols(t_fractol *den);
int				make_fract(t_fractol *den);
int				find_fractol(t_fractol *den);
int				name_fractol(char *name);
void			ft_create_img(t_fractol *den, int x, int y, int color);
void			find_img_addr(t_fractol *den);
int				chec_color(int n, t_fractol *den);
void			mandelbrot_option(t_fractol *den);
void			mandelbrot_set(t_fractol *den);
void			julia_option(t_fractol *den);
void			julia_set(t_fractol *den);
void			julia_wlover_set(t_fractol *den);
void			mandelbar_option(t_fractol *den);
void			mandelbar_set(t_fractol *den);
void			make_threads(t_fractol *den);
void			drop_fractol(t_fractol *den);
void			burningship_set(t_fractol *den);
void			star_set(t_fractol *den);
void			cock_set(t_fractol *den);
void			buffalo_set(t_fractol *den);
int				deal_key_hook(int key, t_fractol *den);
int				deal_key(int key);
int				mouse_hints(int x, int y, t_fractol *den);
void			clear_image(t_fractol *den);
void			ft_chenge_frac(t_fractol *den);
int				mouse_zoom(int keycode, int x, int y, t_fractol *den);
void			mous_in(int x, int y, t_fractol *den);
void			mous_out(int x, int y, t_fractol *den);
void			b_zero(t_fractol *den);
int				exit_x(void *par);

#endif
