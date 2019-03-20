/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:57:49 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/20 18:57:50 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_option(t_fractol *den)
{
	den->x1 = -0.5;
	den->y1 = 0.0;
	den->zoom = 1.0;
	den->maxi = 50;
}

void	mandelbrot_set(t_fractol *den)
{
	int		color;

	den->pr = 1.0 * (den->x - WIDTH / 2.0) / (0.5 * den->zoom
		* WIDTH) + den->x1;
	den->pi = (den->y - WIDTH / 2.0) / (0.5 * den->zoom * WIDTH) + den->y1;
	b_zero(den);
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = (den->or * den->or) - (den->oi * den->oi) + den->pr;
		den->ni = 2 * den->or * den->oi + den->pi;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		if (den->i < den->maxi && den->i > 1)
			color = chec_color(den->i, den);
		if (den->i >= den->maxi - 4 || den->i == 0)
			color = 0;
		ft_create_img(den, den->x, den->y, color);
	}
}

void	julia_option(t_fractol *den)
{
	den->x1 = 0.05;
	den->y1 = 0.02;
	den->zoom = 0.7;
	den->maxi = 50;
	den->cre = -0.7;
	den->cim = 0.27015;
	den->lock = 1;
}

void	julia_set(t_fractol *den)
{
	int		color;

	den->nr = 1.0 * (den->x - WIDTH / 2) / (0.5 * den->zoom * WIDTH) + den->x1;
	den->ni = (den->y - WIDTH / 2) / (0.5 * den->zoom * WIDTH) + den->y1;
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = den->or * den->or - den->oi * den->oi + den->cre;
		den->ni = 2 * den->or * den->oi + den->cim;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		color = chec_color(den->i, den);
		ft_create_img(den, den->x, den->y, color);
	}
}

void	julia_wlover_set(t_fractol *den)
{
	int		color;

	den->nr = 1.0 * (den->x - WIDTH / 2) / (0.5 * den->zoom * WIDTH) + den->x1;
	den->ni = (den->y - WIDTH / 2) / (0.5 * den->zoom * WIDTH) + den->y1;
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = den->or * den->or - den->oi * den->oi + den->cre;
		den->ni = 2 * den->or * den->oi + den->cim;
		if ((den->nr * den->nr / den->ni * den->ni) > 8)
			break ;
		color = chec_color(den->i, den);
		ft_create_img(den, den->x, den->y, color);
	}
}
