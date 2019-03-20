/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 19:22:26 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/20 19:22:27 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_create_img(t_fractol *den, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < WIDTH)
		*(int *)(den->img_data_addr + ((x + y * WIDTH) * 4)) = color;
}

void	find_img_addr(t_fractol *den)
{
	den->bpp = 8;
	den->sl = 1;
	den->endian = (WIDTH * WIDTH);
	den->img_ptr = mlx_new_image(den->mlx_ptr, WIDTH, WIDTH);
	den->img_data_addr = mlx_get_data_addr(den->img_ptr,
		&den->bpp, &den->sl, &den->endian);
}

int		chec_color(int n, t_fractol *den)
{
	int	color;

	if (den->var_color == 2)
		color = 265 * n;
	if (den->var_color == 1)
		color = more_color(n);
	if (den->var_color == 3)
		color = 12212294 * n;
	if (den->var_color == 4)
		color = 8421504 * n;
	return (color);
}

int		more_color(int n)
{
	int	i;
	int color[16];

	i = (n % 15);
	{
		color[0] = 4333071;
		color[1] = 1640218;
		color[2] = 590127;
		color[3] = 263241;
		color[4] = 1892;
		color[5] = 797834;
		color[6] = 1594033;
		color[7] = 3767761;
		color[8] = 8828389;
		color[9] = 13888760;
		color[10] = 15854015;
		color[11] = 16304479;
		color[12] = 16755200;
		color[13] = 13402112;
		color[14] = 10049280;
		color[15] = 6960131;
	}
	return (color[i]);
}
