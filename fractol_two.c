/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:16:51 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/20 19:16:53 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbar_option(t_fractol *den)
{
	den->x1 = 0.0;
	den->y1 = -0.7;
	den->zoom = 1.0;
	den->maxi = 50;
}

void	mandelbar_set(t_fractol *den)
{
	int	color;

	den->pr = 1.0 * (den->x - WIDTH / 2.0) / (0.5 * den->zoom *
		WIDTH) + den->y1;
	den->pi = (den->y - WIDTH / 2.0) / (0.5 * den->zoom * WIDTH) + den->x1;
	b_zero(den);
	den->i = -1;
	while (++den->i < den->maxi)
	{
		den->or = den->nr;
		den->oi = den->ni;
		den->nr = (den->or * den->or) - (den->oi * den->oi) + den->pr;
		den->ni = 15 * den->or * den->oi - den->pi;
		if ((den->nr * den->nr + den->ni * den->ni) > 4)
			break ;
		if (den->i < den->maxi && den->i > 1)
			color = chec_color(den->i, den);
		if (den->i >= den->maxi - 4 || den->i == 0)
			color = 0;
		ft_create_img(den, den->y, den->x, color);
	}
}
