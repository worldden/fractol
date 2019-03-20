/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:57:31 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/07/19 19:22:25 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		deal_key_hook(int key, t_fractol *den)
{
	if (key == 123)
		den->x1 -= 0.3 / den->zoom;
	if (key == 124)
		den->x1 += 0.3 / den->zoom;
	if (key == 125)
		den->y1 += 0.3 / den->zoom;
	if (key == 126)
		den->y1 -= 0.3 / den->zoom;
	if (key == 24)
		den->maxi += 20;
	if (key == 27)
		den->maxi -= 20;
	if (key == 49)
		den->lock = den->lock == 1 ? 0 : 1;
	if (key == 14)
		den->var_color += den->var_color == 4 ? -3 : 1;
	ft_chenge_frac(den);
	if (key == 15 || key == 48)
	{
		if (key == 48)
			den->name += den->name == 8 ? -7 : 1;
		clear_image(den);
		find_fractol(den);
	}
	return (0);
}

int		deal_key(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

int		mouse_hints(int x, int y, t_fractol *den)
{
	if ((x > 0 && x < WIDTH) && (y > 0 && y < WIDTH) && den->lock == 1)
	{
		den->cre = -0.7 + x / 1000.0;
		den->cim = 0.27015 + y / 1000.0;
	}
	ft_chenge_frac(den);
	return (0);
}

void	clear_image(t_fractol *den)
{
	ft_memset(den->img_data_addr, 0, ((WIDTH * WIDTH) * 4));
}

void	ft_chenge_frac(t_fractol *den)
{
	clear_image(den);
	make_threads(den);
}
