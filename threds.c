/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 18:58:50 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/07/23 20:42:30 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_threads(t_fractol *den)
{
	pthread_t	threads[THREAD];
	t_fractol	dens[THREAD];
	int			i;
	int			j;

	i = -1;
	j = 0;
	while (++i < THREAD)
	{
		dens[i] = *den;
		dens[i].st = j;
		j += WIDTH / THREAD;
		dens[i].end = j;
		pthread_create(&threads[i], NULL,
			(void *(*)(void *))drop_fractol, (void *)&dens[i]);
	}
	while (i-- > 0)
		den->status = pthread_join(threads[i], (void **)&den->img_status_addr);
	mlx_put_image_to_window(den->mlx_ptr, den->win_ptr, den->img_ptr, 0, 0);
	put_info(den);
}

void	drop_fractol(t_fractol *den)
{
	den->y = den->st;
	while (den->y < den->end)
	{
		den->x = 0;
		while (den->x < WIDTH)
		{
			make_fract(den);
			den->x++;
		}
		den->y++;
	}
}
