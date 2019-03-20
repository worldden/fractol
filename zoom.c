/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:01:40 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/20 19:01:41 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_zoom(int keycode, int x, int y, t_fractol *den)
{
	if (keycode == 5 || keycode == 1)
		mous_out(x, y, den);
	else if (keycode == 4 || keycode == 2)
		mous_in(x, y, den);
	clear_image(den);
	make_threads(den);
	return (0);
}

void	mous_in(int x, int y, t_fractol *den)
{
	if (den->zoom > 0.1)
	{
		den->zoom /= 1.3;
		den->x1 -= (x - 500) / (den->zoom * 1000);
		den->y1 -= (y - 500) / (den->zoom * 1000);
	}
}

void	mous_out(int x, int y, t_fractol *den)
{
	den->zoom *= 1.5;
	den->x1 += (x - 500) / (den->zoom * 1000);
	den->y1 += (y - 500) / (den->zoom * 1000);
}
