/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heip_fract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:19:20 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/20 19:19:21 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_info(t_fractol *den)
{
	char	*str;

	str = ft_itoa(den->maxi);
	mlx_string_put(den->mlx_ptr, den->win_ptr, 5, 10, 0xFFFFFF,
				"Fractol:              change 'Tab'");
	mlx_string_put(den->mlx_ptr, den->win_ptr, 100, 10, 0xFFFFFF,
				find_fractols(den));
	mlx_string_put(den->mlx_ptr, den->win_ptr, 80, 30, 0xFFFFFF,
				str);
	mlx_string_put(den->mlx_ptr, den->win_ptr, 5, 30, 0xFFFFFF,
				"iter :(    ) : '+' / '-' ");
	mlx_string_put(den->mlx_ptr, den->win_ptr, 5, 50, 0xFFFFFF,
				"reset :'r', move:'arrows', color: 'e' ");
	free(str);
}

char	*find_fractols(t_fractol *den)
{
	if (den->name == 1)
		return ("Mandelbrot");
	if (den->name == 2)
		return ("Julia");
	if (den->name == 3)
		return ("Burningship");
	if (den->name == 4)
		return ("Star");
	if (den->name == 5)
		return ("Cock");
	if (den->name == 6)
		return ("Buffalo");
	if (den->name == 7)
		return ("julia_wlover");
	if (den->name == 8)
		return ("Mandelbar");
	return (NULL);
}

int		make_fract(t_fractol *den)
{
	if (den->name == 1)
		mandelbrot_set(den);
	if (den->name == 2)
		julia_set(den);
	if (den->name == 3)
		burningship_set(den);
	if (den->name == 4)
		star_set(den);
	if (den->name == 5)
		cock_set(den);
	if (den->name == 6)
		buffalo_set(den);
	if (den->name == 7)
		julia_wlover_set(den);
	if (den->name == 8)
		mandelbar_set(den);
	return (0);
}

int		find_fractol(t_fractol *den)
{
	den->var_color = 1;
	if (den->name == 1)
		mandelbrot_option(den);
	if (den->name == 8)
		mandelbar_option(den);
	if (den->name == 2 || den->name == 7)
	{
		julia_option(den);
	}
	if (den->name == 3 || den->name == 4 || den->name == 5 || den->name == 6)
	{
		mandelbrot_option(den);
		den->zoom = 0.6;
	}
	make_threads(den);
	return (0);
}

int		name_fractol(char *name)
{
	if (ft_strcmp(name, "Mandelbrot") == 0)
		return (1);
	if (ft_strcmp(name, "Julia") == 0)
		return (2);
	if (ft_strcmp(name, "Burningship") == 0)
		return (3);
	if (ft_strcmp(name, "Star") == 0)
		return (4);
	if (ft_strcmp(name, "Cock") == 0)
		return (5);
	if (ft_strcmp(name, "Buffalo") == 0)
		return (6);
	if (ft_strcmp(name, "Julia_wlover") == 0)
		return (7);
	if (ft_strcmp(name, "Mandelbar") == 0)
		return (8);
	else
		ft_putendl("usage: ./fdf file\
		\n ->Mandelbrot \n ->Julia\n ->Burningship\
		\n ->Star\n ->Cock\n ->Buffalo\n ->Julia_wlover\n ->Mandelbar");
	return (0);
}
