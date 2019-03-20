/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:46:31 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/12 15:46:32 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_x(void *par)
{
	par = NULL;
	exit(1);
	return (0);
}

void	mlx_windof(t_fractol *den)
{
	den->mlx_ptr = mlx_init();
	den->win_ptr = mlx_new_window(den->mlx_ptr, WIDTH, WIDTH, "fractol");
	find_img_addr(den);
	mlx_key_hook(den->win_ptr, deal_key, den);
	find_fractol(den);
	mlx_hook(den->win_ptr, 17, 1L << 17, exit_x, den);
	mlx_hook(den->win_ptr, 2, (1L << 0), deal_key_hook, den);
	mlx_hook(den->win_ptr, 6, 1L << 7, mouse_hints, den);
	mlx_mouse_hook(den->win_ptr, mouse_zoom, den);
	mlx_loop(den->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_fractol	den;

	if (argc == 2)
	{
		den.name = name_fractol(argv[1]);
		if (den.name > 0)
			mlx_windof(&den);
	}
	else
		ft_putendl("usage: ./fdf file\
		\n ->Mandelbrot \n ->Julia\n ->Burningship\
		\n ->Star\n ->Cock\n ->Buffalo\n ->Julia_wlover\n ->Mandelbar");
	return (0);
}
