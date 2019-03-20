/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:03:54 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/20 19:03:56 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	burningship_set(t_fractol *den)
{
	int		color;

	den->pr = 1.0 * (den->x - WIDTH / 2) / (0.5 * den->zoom * WIDTH) + den->x1;
	den->pi = (den->y - WIDTH / 2) / (0.5 * den->zoom * WIDTH) + den->y1;
	b_zero(den);
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = den->or * den->or - den->oi * den->oi + den->pr;
		den->ni = fabs(den->or * den->oi) * -2 + den->pi;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		if (den->i < den->maxi && den->i > 1)
			color = chec_color(den->i, den);
		if (den->i >= den->maxi - 4 || den->i == 0)
			color = 0;
		ft_create_img(den, den->x, den->y, color);
	}
}

void	star_set(t_fractol *den)
{
	int		color;

	den->pr = 1.0 * (den->x - WIDTH / 2) / (0.3 * den->zoom * WIDTH) + den->x1;
	den->pi = (den->y - WIDTH / 2) / (0.3 * den->zoom * WIDTH) + den->y1;
	b_zero(den);
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = den->or * den->or - den->oi * den->oi + den->pr;
		den->ni = -2 * den->or * den->oi + den->pi;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		if (den->i < den->maxi && den->i > 1)
			color = chec_color(den->i, den);
		if (den->i >= den->maxi - 4 || den->i == 0)
			color = 0;
		ft_create_img(den, den->x, den->y, color);
	}
}

void	cock_set(t_fractol *den)
{
	int		color;

	den->pr = 1.0 * (den->x - WIDTH / 2.0) / (0.3 * den->zoom
		* WIDTH) + den->x1;
	den->pi = (den->y - WIDTH / 2.0) / (0.3 * den->zoom * WIDTH) + den->y1;
	b_zero(den);
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = (den->or * den->or) - (den->oi * den->oi) + den->pr;
		den->ni = den->or * -2 * fabs(den->oi) + den->pi;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		if (den->i < den->maxi && den->i > 1)
			color = chec_color(den->i, den);
		if (den->i >= den->maxi - 4 || den->i == 0)
			color = 0;
		ft_create_img(den, den->x, den->y, color);
	}
}

void	buffalo_set(t_fractol *den)
{
	int		color;

	den->pr = 1.0 * (den->x - WIDTH / 2.0) / (0.3 * den->zoom
		* WIDTH) + den->x1;
	den->pi = (den->y - WIDTH / 2.0) / (0.3 * den->zoom * WIDTH) + den->y1;
	b_zero(den);
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = fabs(den->or * den->or - den->oi * den->oi) + den->pr;
		den->ni = fabs(den->or * den->oi) * -2 + den->pi;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		if (den->i < den->maxi && den->i > 1)
			color = chec_color(den->i, den);
		if (den->i >= den->maxi - 4 || den->i == 0)
			color = 0;
		ft_create_img(den, den->x, den->y, color);
	}
}

void	b_zero(t_fractol *den)
{
	den->nr = 0;
	den->ni = 0;
	den->oi = 0;
}
